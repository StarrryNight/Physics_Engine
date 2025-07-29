
#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include "../include/Object.h"
#include "../include/Shader.h"

float screenHeight = 600.0f;
float screenWidth = 800.0f;

GLFWwindow* StartGLFW();
int main() {
    std::cout << "Starting program..." << std::endl;
    
    GLFWwindow* window = StartGLFW();
    
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    std::cout << "Window created successfully" << std::endl;

    // Make the window's context current
    glfwMakeContextCurrent(window);
    
    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // Set up the viewport and projection
    glViewport(0, 0, screenWidth, screenHeight);
    std::cout << "OpenGL setup complete" << std::endl;

    float startX = screenWidth/5.0f;
    float startY = screenHeight/2.0f;
    

    float prev_time = 0;
    std::cout << "Entering main loop..." << std::endl;

    // Create shader
    Shader d_shader("vertex", "fragment");  // Using default shaders from Shader class
    
    //Object initialization -------------------------------------------------------------------------------------------------------------------
    std::vector<Object> objects;

    Object circle1("triangle", objects.size(), &d_shader, glm::vec3(startX, startY, 0.0f));
    objects.push_back(circle1);
    //-----------------------------------------------------------------------------------------------------------------------------------------
    
    // Setup the object
    circle1.setup();
    
    while(!glfwWindowShouldClose(window)){
        // Clear the screen
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Render the object
        circle1.render();
       
        //display
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    std::cout << "Exiting program..." << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
} 

GLFWwindow* StartGLFW(){
    std::cout << "Initializing GLFW..." << std::endl;
    if (!glfwInit()){
        std::cerr << "GLFW initialization failed" << std::endl;
        return nullptr;
    }
    
    std::cout << "Creating window..." << std::endl;
    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Renderer", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    std::cout << "Window created" << std::endl;
    return window;
}