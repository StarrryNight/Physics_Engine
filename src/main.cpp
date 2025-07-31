
#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../include/Object.h"
#include "../include/Shader.h"
#include "../include/Camera.h"
#include "../include/Planets.h"
#include "../include/PhysicsManager.h"

float screenHeight = 800.0f;
float screenWidth = 800.0f;

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// Mouse variables
float lastX = screenWidth / 2.0f;
float lastY = screenHeight / 2.0f;
bool firstMouse = true;

// Timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Function prototypes
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

GLFWwindow* StartGLFW();
int main() {
    std::cout << "Starting program..." << std::endl;
    
    GLFWwindow* window = StartGLFW();
    
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    std::cout << "Window created successfully" << std::endl;

    glfwMakeContextCurrent(window);
    
    // Set up input callbacks
    glfwSetCursorPosCallback(window, mouse_callback);
    
    // Tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    glEnable(GL_DEPTH_TEST);
    
    std::cout << "OpenGL setup complete" << std::endl;

    float startX = 0;  
    float startY = 0;  
    float startZ = 0;  

    std::cout << "Entering main loop..." << std::endl;

    // Create shader
    Shader d_shader("vertex", "fragment");
    
    // Create planets
    Planets* earth = new Planets("Earth", 0, &d_shader, 0.5f, 5.5f, glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    Planets* moon = new Planets("Moon", 1, &d_shader, 0.2f, 3.3f, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    
    earth->setupPlanet();
    moon->setupPlanet();
    
    PhysicsManager physicsManager(0.1f);
    physicsManager.addPlanet(earth);
    physicsManager.addPlanet(moon);
    

    while(!glfwWindowShouldClose(window)){
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        processInput(window);
        
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        d_shader.Use();
        
        glm::mat4 projection = camera.GetProjectionMatrix(screenWidth / screenHeight);
        d_shader.setProjectionMatrix(projection);
        
        glm::mat4 view = camera.GetViewMatrix();
        d_shader.setViewMatrix(view);
        
        physicsManager.updatePhysics(deltaTime);
        
        static int frameCount = 0;
        frameCount++;
        if (frameCount % 60 == 0) {
            std::cout << "Earth po: (" << earth->getPosition().x << ", " << earth->getPosition().y << ", " << earth->getPosition().z << ")" << std::endl;
            std::cout << "Moon pos: (" << moon->getPosition().x << ", " << moon->getPosition().y << ", " << moon->getPosition().z << ")" << std::endl;
            std::cout << "Distance: " << glm::length(moon->getPosition() - earth->getPosition()) << std::endl;
        }
        
        earth->render();
        moon->render();
       
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

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera::DOWN, deltaTime);
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}