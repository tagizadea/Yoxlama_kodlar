#pragma once

#include <string>
#include <vector>

#include "Component.h"

class GameObject
{
public:
    // Constructor
    GameObject(const std::string& name);

    // Destructor
    ~GameObject();

    // Update the game object
    void update();

    // Render the game object
    void render();

    // Add a component to the game object
    void addComponent(Component* component);

    // Get a component by type
    template <typename T>
    T* getComponent() const;

private:
    // Name of the game object
    std::string name;

    // List of components
    std::vector<Component*> components;
};

template <typename T>
T* GameObject::getComponent() const
{
    // Iterate through the list of components
    for (Component* component : components)
    {
        // Check if the component is of the desired type
        T* result = dynamic_cast<T*>(component);
        if (result != nullptr)
            return result;
    }

    // Return nullptr if no matching component was found
    return nullptr;
}
