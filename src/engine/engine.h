#pragma once

#include "glad.h"
#include "GLFW/glfw3.h"
#include "particle/particle.h"
#include "physics/kinematics/kinematics.h"
#include "physics/dynamics/dynamics.h"
#include "simulation/sim.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <fstream>
#include <sstream>

GLFWwindow* DrawWindow();

void framebuffer_size_callback(GLFWwindow* window, int height, int width);

void processInput(GLFWwindow* window);

void renderObjects(std::vector<Physics::Particle*> objs, float dt, int width, int height);

std::string loadShader(const char* filepath);
