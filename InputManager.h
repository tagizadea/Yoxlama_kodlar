#pragma once

#include <unordered_map>

#include "Singleton.h"

// Forward declarations
struct GLFWwindow;

class InputManager : public Singleton<InputManager>
{
    friend class Singleton<InputManager>;

public:
    // Update the input manager
    void update();

    // Check if a key is down
    bool isKeyDown(int key) const;

    // Check if a key was just pressed
    bool isKeyPressed(int key) const;

    // Check if a key was just released
    bool isKeyReleased(int key) const;

    // Check if a mouse button is down
    bool isMouseButtonDown(int button) const;

    // Check if a mouse button was just pressed
    bool isMouseButtonPressed(int button) const;

    // Check if a mouse button was just released
    bool isMouseButtonReleased(int button) const;

    // Get the mouse position
    void getMousePosition(double& x, double& y) const;

private:
    // Private constructor
    InputManager();

    // GLFW window
    GLFWwindow* window;

    // Key states
    std::unordered_map<int, bool> keys
    std::unordered_map<int, bool> keysDown;
    std::unordered_map<int, bool> keysUp;

    // Mouse button states
    std::unordered_map<int, bool> mouseButtons;
    std::unordered_map<int, bool> mouseButtonsDown;
    std::unordered_map<int, bool> mouseButtonsUp;
};
