#pragma once

#include "glad.h"
#include "GLFW/glfw3.h"
#include "particle/particle.h"
#include "physics/kinematics/kinematics.h"
#include "physics/dynamics/dynamics.h"

GLFWwindow* DrawWindow();

void framebuffer_size_callback(GLFWwindow* window, int height, int width);

void processInput(GLFWwindow* window);

void simulationLoop();
