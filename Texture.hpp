class Texture
{
public:
    // Constructor
    Texture(const char* filepath);

    // Destructor
    ~Texture();

    // Bind the texture
    void bind();

    // Unbind the texture
    void unbind();

    // Get the texture ID
    GLuint getID() const { return id; }

    // Get the texture width
    int getWidth() const { return width; }

    // Get the texture height
    int getHeight() const { return height; }

private:
    // Texture ID
    GLuint id;

    // Texture width and height
    int width, height;
};
