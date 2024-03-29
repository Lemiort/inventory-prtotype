#ifndef SRC_VIEW_MODEL_TEXTURELOADER_H_
#define SRC_VIEW_MODEL_TEXTURELOADER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace view_model {

class TextureLoader {
 public:
    ~TextureLoader();

    // Simple helper function to load an image into a OpenGL texture with common
    // settings
    static bool LoadFromFile(const char* filename, GLuint* out_texture,
                             int* out_width, int* out_height) {
        // Load from file
        int image_width = 0;
        int image_height = 0;
        unsigned char* image_data =
            stbi_load(filename, &image_width, &image_height, nullptr, 4);
        if (image_data == nullptr) {
            return false;
        }

        // Create a OpenGL texture identifier
        GLuint image_texture;
        glGenTextures(1, &image_texture);
        glBindTexture(GL_TEXTURE_2D, image_texture);

        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_CLAMP_TO_EDGE);  // This is required on WebGL for non
                                            // power-of-two textures
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_CLAMP_TO_EDGE);  // Same

        // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, image_data);
        stbi_image_free(image_data);

        *out_texture = image_texture;
        *out_width = image_width;
        *out_height = image_height;

        return true;
    }

 protected:
    TextureLoader() = default;
};

}  // namespace view_model

#endif  // SRC_VIEW_MODEL_TEXTURELOADER_H_
