#include "view_model/Renderable.h"

#include <imgui.h>

#include "view_model/TextureLoader.h"

namespace {
constexpr size_t kMaxPathLength = 260;
constexpr int kIconSize = 64;
}  // namespace

namespace view_model {

int Renderable::objects_count_{0};

struct Renderable::OpenGlTexture {
public:
    GLuint texture{0};
    int width{0};
    int height{0};
};

Renderable::Renderable() {
    object_id_ = objects_count_++;
    name_ = "Object " + std::to_string(object_id_);
}

Renderable::~Renderable() {}

int Renderable::getId() const { return object_id_; }
void Renderable::setName(std::string name) { name_ = name; }

bool Renderable::renderSelectableItem(bool is_selected) {
    return ImGui::Selectable(name_.c_str(), is_selected);
}
void Renderable::renderEditWindow() {
    if (first_render_) {
        createTextureFromPath(getIcon().getFilePath());
        first_render_ = false;
    }

    if (ImGui::Button("Delete")) {
        is_marked_to_delete_ = true;
    }

    auto position = getPosition();
    float* flat_array = &position.x;
    if (ImGui::InputFloat2("Position", flat_array)) {
        setPosition({flat_array[0], flat_array[1]});
    }
    const auto& icon = getIcon();
    const auto icon_path = icon.getFilePath();
    const auto path_string = icon_path.string();
    char path_buffer[kMaxPathLength] = "";
    path_string.copy(path_buffer,
                     std::min(path_string.length(), sizeof(path_buffer)));
    if (ImGui::InputTextWithHint("Icon path", "Valid path of icon", path_buffer,
                                 sizeof(path_buffer))) {
        std::filesystem::path path = std::string(path_buffer);
        createTextureFromPath(path);
        if (texture_) {
            setIcon(std::make_unique<model::Icon>(path));
        }
    }

    if (texture_) {
        ImGui::Text("Icon");
        ImGui::Image((void*)(intptr_t)texture_->texture,
                     ImVec2(texture_->width, texture_->height));
    }
}

bool Renderable::getIsMarkedToDelete() const { return is_marked_to_delete_; }

void Renderable::createTextureFromPath(std::filesystem::path path) {
    if (std::filesystem::exists(path)) {
        GLuint texture_id{0};
        int width{0};
        int height{0};
        if (TextureLoader::LoadFromFile(path.string().c_str(), &texture_id,
                                        &width, &height)) {
            texture_ = std::make_unique<OpenGlTexture>();
            texture_->texture = texture_id;
            auto max_size = std::max(width, height);
            float scaling_factor = 1.0F;
            if (max_size > kIconSize) {
                scaling_factor = static_cast<float>(kIconSize) /
                                 static_cast<float>(max_size);
            }
            texture_->height = height * scaling_factor;
            texture_->width = width * scaling_factor;
        }
    }
}

}  // namespace view_model
