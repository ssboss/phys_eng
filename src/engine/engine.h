#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "core.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <fstream>
#include <sstream>

class Engine{
    public:
        Engine(){};
        Engine(int width, int height) : width(width), height(height) {};
        void DrawWindow();
        void renderObjects(RenderInfo* worldInfo);
    private:
        GLFWwindow* window;
        int width;
        int height;
        const char* filepath;
};

// GLFWwindow* DrawWindow();

void framebuffer_size_callback(GLFWwindow* window, int height, int width);

void processInput(GLFWwindow* window);

// void renderObjects(int width, int height);

std::string loadShader(const char* filepath);
