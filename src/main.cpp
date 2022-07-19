/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include <GLFW/glfw3.h>  // Will drag system OpenGL headers
#include <imgui.h>

#include <iostream>
#include <sstream>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "model/Ladder.h"
#include "model/Wall.h"
#include "view_model/Player.h"
#include "view_model/Scene.h"

static void glfw_error_callback(int error, const char* description) {
    std::cerr << "Glfw Error " << error << ": " << description << std::endl;
}
namespace {
const char* const kGlslVersion = "#version 440";
}  // namespace

class Main final {
private:
    GLFWwindow* window_{nullptr};
    bool close_button_pressed_{false};
    ImVec4 clear_color_{0.45F, 0.55F, 0.60F, 1.00F};
    view_model::Scene scene_;

    bool initGlfw() {
        // Setup window
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit()) {
            return false;
        }

        // GL 4.4 + GLSL 440
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // only for Mac

        // no windows borders
        // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

        // Create window with graphics context
        window_ =
            glfwCreateWindow(1280, 720, "Level editor demo", nullptr, nullptr);
        if (window_ == nullptr) {
            return false;
        }
        glfwMakeContextCurrent(window_);
        glfwSwapInterval(1);  // Enable vsync

        return true;
    }

    void render() {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        constexpr bool kUseWorkArea = true;
        static ImGuiWindowFlags flags =
            ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoSavedSettings;

        // We demonstrate using the full viewport area or the work area
        // (without menu-bars, task-bars etc.) Based on your use case you
        // may want one of the other.
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(kUseWorkArea ? viewport->WorkPos
                                             : viewport->Pos);
        ImGui::SetNextWindowSize(kUseWorkArea ? viewport->WorkSize
                                              : viewport->Size);

        if (ImGui::Begin("Example: Simple layout", &close_button_pressed_,
                         flags)) {
            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    {
                        if (ImGui::MenuItem("New")) {
                        }
                        if (ImGui::MenuItem("Open", "Ctrl+O")) {
                        }
                        if (ImGui::MenuItem("Save", "Ctrl+S")) {
                        }
                        if (ImGui::MenuItem("Save As..")) {
                        }

                        if (ImGui::MenuItem("Quit", "Alt+F4")) {
                            close_button_pressed_ = true;
                        }
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            // Left
            static size_t selected = 0;
            scene_.renderSelectableList();
            selected = scene_.getSelectedIndex();
            ImGui::SameLine();

            // Right
            {
                ImGui::BeginGroup();
                ImGui::BeginChild(
                    "item view",
                    ImVec2(0,
                           -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                   // room for
                                                                   // 1 line
                                                                   // below us
                ImGui::Text("MyObject: %d", static_cast<int>(selected));
                ImGui::Separator();
                if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) {
                    if (ImGui::BeginTabItem("Description")) {
                        ImGui::TextWrapped(
                            "Lorem ipsum dolor sit amet, consectetur "
                            "adipiscing elit, sed do eiusmod tempor "
                            "incididunt ut labore et dolore magna "
                            "aliqua. ");
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Details")) {
                        ImGui::Text("ID: 0123456789");
                        ImGui::EndTabItem();
                    }
                    ImGui::EndTabBar();
                }
                ImGui::EndChild();
                if (ImGui::Button("Revert")) {
                }
                ImGui::SameLine();
                if (ImGui::Button("Save")) {
                }
                ImGui::EndGroup();
            }
        }
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w;
        int display_h;
        glfwGetFramebufferSize(window_, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color_.x * clear_color_.w,
                     clear_color_.y * clear_color_.w,
                     clear_color_.z * clear_color_.w, clear_color_.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_);
    }

public:
    Main() {
        scene_.addObject(std::make_unique<view_model::Player>());
        scene_.addObject(std::make_unique<view_model::Player>());
        scene_.addObject(std::make_unique<model::Wall>());
        scene_.addObject(std::make_unique<model::Ladder>());
        scene_.addObject(std::make_unique<view_model::Player>());
        scene_.addObject(std::make_unique<model::Wall>());
        scene_.addObject(std::make_unique<model::Ladder>());
    }

    int run() {
        if (!initGlfw()) {
            return 1;
        }

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& imgui_io = ImGui::GetIO();
        (void)imgui_io;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window_, true);
        ImGui_ImplOpenGL3_Init(kGlslVersion);

        // Main loop
        while (!glfwWindowShouldClose(window_) && !close_button_pressed_) {
            render();
        }

        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window_);
        glfwTerminate();

        return 0;
    }
};

int main(int argc, char** argv) {
    Main main;
    return main.run();
}