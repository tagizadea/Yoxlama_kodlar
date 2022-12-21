Texture::Texture(const char* filepath)
{
    // Load the image file using stb_image
    int width, height, numComponents;
    unsigned char* data = stbi_load(filepath, &width, &height, &numComponents, 4);

    if (data == nullptr)
        std::cerr << "Failed to load texture: " << filepath << std::endl;

    // Generate the texture
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // Set the texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Upload the texture data
   
Texture::Texture(const char* filepath)
{
    // Load the image file using stb_image
    int width, height, numComponents;
    unsigned char* data = stbi_load(filepath, &width, &height, &numComponents, 4);

    if (data == nullptr)
        std::cerr << "Failed to load texture: " << filepath << std::endl;

    // Generate the texture
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // Set the texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Upload the texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // Free the image data
    stbi_image_free(data);

    // Save the texture dimensions
    this->width = width;
    this->height = height;
}

Texture::~Texture()
{
    // Delete the texture
    glDeleteTextures(1, &id);
}

void Texture::bind()
{
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}
