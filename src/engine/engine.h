#pragma once

#include "glad.h"
#include "GLFW/glfw3.h"
#include "particle.h"
#include "world.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <fstream>
#include <sstream>

GLFWwindow* DrawWindow();

void framebuffer_size_callback(GLFWwindow* window, int height, int width);

void processInput(GLFWwindow* window);

void renderObjects(int width, int height, World* world);

std::string loadShader(const char* filepath);
