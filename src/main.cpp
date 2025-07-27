
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "../include/Object.h"
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
    std::cout << "Context made current" << std::endl;
    
    // Set up the viewport and projection
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, screenHeight, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    std::cout << "OpenGL setup complete" << std::endl;

    float startX = screenWidth/5.0f;
    float startY = screenHeight/2.0f;
    

    float prev_time = 0;
    std::cout << "Entering main loop..." << std::endl;

    //Object initialization -------------------------------------------------------------------------------------------------------------------
    std::vector<Object> objects;

    Object circle1("triangle", objects.size(), startX, startY);
    objects.push_back(circle1);
    Object circle2("circle", objects.size(), startX, 0);
    objects.push_back(circle2);
    //-----------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    while(!glfwWindowShouldClose(window)){
        //initialize each scene
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Update objects' physics
        float curr_time = glfwGetTime();
        float dt = curr_time - prev_time;
        prev_time = curr_time;
        for (auto& ob: objects){
            ob.update(dt);
        }
        std::cerr << dt << std::endl;

       //render each objct
        for (auto& ob: objects){
            ob.render();
        }
        
       
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