class SpriteRenderer : public Component
{
public:
    // Constructor
    SpriteRenderer(Texture* texture = nullptr);

    // Destructor
    ~SpriteRenderer();

    // Set the texture
    void setTexture(Texture* texture);

    // Render the sprite
    void render() override;

private:
    // Texture
    Texture* texture;

    // Vertex array object
    GLuint vao;

    // Vertex buffer object
    GLuint vbo;

    // Element buffer object
    GLuint ebo;
};

SpriteRenderer::SpriteRenderer(Texture* texture)
{
    // Save the texture
    this->texture = texture;

    // Generate the vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Generate the vertex buffer object
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Define the vertex data
    float vertices[] = {
        // Positions      // Texture coordinates
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // Top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // Bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // Top left
    };

    // Upload the vertex data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Generate the element buffer object
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    // Define the element data
    unsigned int elements[] = {
        0, 1, 3, // Triangle 1
        1, 2, 3  // Triangle 2
    };

    // Upload the element data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

SpriteRenderer::~SpriteRenderer()
{
    // Delete the vertex buffer object
    glDeleteBuffers(1, &vbo);

    // Delete the element buffer object
    glDeleteBuffers(1, &ebo);

    // Delete the vertex array object
    glDeleteVertexArrays(1, &vao);
}

void SpriteRenderer::setTexture(Texture* texture)
{
    this->texture = texture;
}

void SpriteRenderer::render()
{
    // Bind the texture
    texture->bind();

    // Bind the vertex array object
    glBindVertexArray(vao);

    // Draw the elements
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
