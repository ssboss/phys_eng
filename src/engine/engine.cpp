#include "engine.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "core.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"



void Engine::DrawWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Particle Simulator", NULL, NULL);
    if(!window){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        // write exception code here
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to init GLAD" << std::endl;
        // write exception code here
    }
    glViewport(0,0, width, height);

}

void Engine::renderObjects(RenderInfo* worldInfo){
    int success;
    char log[512];

    // std::vector<Physics::Vector3D> vertices;
    float vertices[] {
        0.0f, 0.0f, 0.0f
    };

    // for(unsigned int i {0}; i < static_cast<unsigned int>(objs.size()); ++i){
    //     vertices.push_back(objs[i]->getCurrPos());
    // }
    std::string vertSource {loadShader("../src/shaders/vert_shader.vs")};
    const char* vertCode {vertSource.c_str()};
    unsigned int vertexShader {glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vertexShader, 1, &vertCode, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, log);
        std::cout << "Vertex shader error: " << log << "\n";
    }

    std::string fragSource {loadShader("../src/shaders/frag_shader.fs")};
    const char* fragCode {fragSource.c_str()};
    unsigned int fragShader {glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fragShader, 1, &fragCode, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, log);
        std::cout << "Fragment shader error: " << log << "\n";
    }

    unsigned int shaderProg {glCreateProgram()};
    glAttachShader(shaderProg, vertexShader);
    glAttachShader(shaderProg, fragShader);
    glLinkProgram(shaderProg);
    glGetProgramiv(shaderProg, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProg, 512, NULL, log);
        std::cout << "Shader link error: " << log << "\n";
    }

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    int modelLoc {glGetUniformLocation(shaderProg, "model")};
    int viewLoc {glGetUniformLocation(shaderProg, "view")};
    int projecLoc {glGetUniformLocation(shaderProg, "projection")};

    glPointSize(5.0f);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput(window);

        glUseProgram(shaderProg);
        glBindVertexArray(VAO);

        glm::mat4 view {glm::mat4(1.0f)};
        // view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        Physics::Vector3D worldCenter {worldInfo->getUpperBounds() + worldInfo->getLowerBounds()};
        glm::vec3 boxCenter {(worldCenter.x, worldCenter.y, worldCenter.z) * 0.5f};
        Physics::Vector3D worldRange {worldInfo->getUpperBounds() - worldInfo->getLowerBounds()}; // check math here
        glm::vec3 boxRadius {(worldRange.x, worldRange.y, worldRange.z) * 0.5f};
        float boundRadius {glm::length(boxRadius)};

        float dist {boundRadius / static_cast<float>(sin(glm::radians(45.0f)))};
        dist *= 1.3f;

        glm::vec3 viewDir {glm::normalize(glm::vec3(0.5f, 1.0f, 0.5f))};

        glm::vec3 eye {boxCenter - (viewDir * dist)};

        view = glm::lookAt(eye, boxCenter, glm::vec3(0,1,0));







        glm::mat4 projection {glm::mat4(1.0f)};
        projection = glm::perspective(glm::radians(90.0f), static_cast<float>(width)/static_cast<float>(height), 0.1f, 1000.0f);
        // // trying ortho projection
        // projection = glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), 0.1f, 1000.0f);

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));

        

        for (unsigned int i{0}; i < worldInfo->getCount(); ++i){
            glm::mat4 model {glm::mat4(1.0f)};
            model = glm::translate(model, glm::vec3(worldInfo->getPos(i).x, worldInfo->getPos(i).y, worldInfo->getPos(i).z));
            model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f)); // want scale of 0.25, will test and mess around w/

            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawArrays(GL_POINTS, 0, 1);
        }
        worldInfo->update();
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}

// helper fxn definitions start here
std::string loadShader(const char* filepath){
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Could not open shader file: " << filepath << "\n";
        return "";
    }
    std::stringstream shaderStream;
    shaderStream << file.rdbuf();
    file.close();
    return shaderStream.str();
}

void framebuffer_size_callback(GLFWwindow* window, int height, int width){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


