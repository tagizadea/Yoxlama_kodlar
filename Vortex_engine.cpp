#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "InputManager.h"

class GameEngine
{
private:
    // Private constructor to prevent instantiation
    GameEngine() {}

public:
    // Static method to get the singleton instance
    static GameEngine& getInstance()
    {
        static GameEngine instance;
        return instance;
    }

    // Initialize the game engine
    bool init(int width, int height, const char* title);

    // Run the game loop
    void run();

    // Shutdown the game engine
    void shutdown();

    // Add a game object to the scene
    void addGameObject(GameObject* gameObject);

    // Get the width of the window
    int getWidth() const { return width; }

    // Get the height of the window
    int getHeight() const { return height; }

    // Get the input manager
    InputManager& getInputManager() { return inputManager; }

private:
    // Window width and height
    int width, height;

    // GLFW window handle
    GLFWwindow* window;

    // Vector of game objects in the scene
    std::vector<GameObject*> gameObjects;

    // Input manager
    InputManager inputManager;

    // Update the game state
    void update(float deltaTime);

    // Render the game
    void render();
};

bool GameEngine::init(int width, int height, const char* title)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Create the window
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return false;
    }

    // Set the input callbacks
    glfwSetKeyCallback(window, InputManager::keyCallback);
    glfwSetMouseButtonCallback(window, InputManager::mouseButtonCallback);
    glfwSetCursorPosCallback(window, InputManager::cursorPosCallback);

    // Save the window size
    this->width = width;
    this->height = height;

    return true;
}

void GameEngine::run()
{
    // Delta time variables
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Calculate delta time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Update the game state
        update(deltaTime);

        // Render the game
        render();

        // Poll for events
        glfwPollEvents();
    }
}


void GameEngine::update(float deltaTime)
{
    // Update the input manager
    inputManager.update();

    // Update all game objects
    for (auto gameObject : gameObjects)
        gameObject->update(deltaTime);
}

void GameEngine::render()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Render all game objects
    for (auto gameObject : gameObjects)
        gameObject->render();

    // Swap the buffers
    glfwSwapBuffers(window);
}

void GameEngine::addGameObject(GameObject* gameObject)
{
    gameObjects.push_back(gameObject);
}

void GameEngine::run()
{
    // Delta time variables
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Calculate delta time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Update the game state
        update(deltaTime);

        // Render the game
        render();

        // Poll for events
        glfwPollEvents();
    }
}

void GameEngine::shutdown()
{
    // Destroy all game objects
    for (auto gameObject : gameObjects)
        delete gameObject;

    // Destroy the window
    glfwDestroyWindow(window);

    // Terminate GLFW
    glfwTerminate();
}

int main()
{
    // Get the game engine singleton instance
    GameEngine& gameEngine = GameEngine::getInstance();

    // Initialize the game engine
    if (!gameEngine.init(640, 480, "My Game"))
        return -1;

    // Create a sprite renderer
    SpriteRenderer* spriteRenderer = new SpriteRenderer();

    // Create a game object
    GameObject* gameObject = new GameObject();

    // Add the sprite renderer to the game object
    gameObject->addComponent(spriteRenderer);

    // Add the game object to the scene
    gameEngine.addGameObject(gameObject);

    // Run the game loop
    gameEngine.run();

    // Shutdown the game engine
    gameEngine.shutdown();

    return 0;
}
