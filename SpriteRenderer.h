#pragma once

#include <string>

#include "Component.h"
#include "Texture.h"

class SpriteRenderer : public Component
{
public:
    // Constructor
    SpriteRenderer(const std::string& fileName);

    // Destructor
    ~SpriteRenderer();

    // Render the sprite
    void render() override;

private:
    // Texture for the sprite
    Texture texture;
};
