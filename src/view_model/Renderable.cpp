#include "view_model/Renderable.h"

#include <imgui.h>

namespace view_model {

int Renderable::objects_count_{0};

Renderable::Renderable() {
    object_id_ = objects_count_++;
    name_ = "Object " + std::to_string(object_id_);
}

int Renderable::getId() const { return object_id_; }
void Renderable::setName(std::string name) { name_ = name; }

bool Renderable::renderSelectableItem(bool is_selected) {
    return ImGui::Selectable(name_.c_str(), is_selected);
}
void Renderable::renderEditWindow() {
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
    char path_buffer[64] = "";
    path_string.copy(path_buffer,
                     std::min(path_string.length(), sizeof(path_buffer)));
    if (ImGui::InputTextWithHint("Icon path", "Valid path of icon", path_buffer,
                                 sizeof(path_buffer))) {
        // TODO add validation of the path
        std::filesystem::path path = std::string(path_buffer);
        setIcon(std::make_unique<model::Icon>(path));
    }

    // TODO add preview of the texture
    // ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), uv_min, uv_max,
    // tint_col, border_col);
}

bool Renderable::getIsMarkedToDelete() const { return is_marked_to_delete_; }

}  // namespace view_model
