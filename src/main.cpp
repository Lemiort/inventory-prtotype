#include <GLFW/glfw3.h>  // Will drag system OpenGL headers

#include <format>
#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

static void glfw_error_callback(int error, const char* description) {
    std::cerr << std::format("Glfw Error {}: {}\n", error, description);
}

auto main() -> int {
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        return 1;
    }

    // GL 4.4 + GLSL 440
    const char* glsl_version = "#version 440";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // only for Mac

    // no windows borders
    // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow* window =
        glfwCreateWindow(1280, 720, "Level editor demo", NULL, NULL);
    if (window == NULL) {
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& imgui_io = ImGui::GetIO();
    (void)imgui_io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    ImVec4 clear_color{0.45f, 0.55f, 0.60f, 1.00f};
    bool close_button_pressed = false;

    // Main loop
    while (!glfwWindowShouldClose(window) && !close_button_pressed) {
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

        // We demonstrate using the full viewport area or the work area (without
        // menu-bars, task-bars etc.) Based on your use case you may want one of
        // the other.
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(kUseWorkArea ? viewport->WorkPos
                                             : viewport->Pos);
        ImGui::SetNextWindowSize(kUseWorkArea ? viewport->WorkSize
                                              : viewport->Size);

        if (ImGui::Begin("Example: Simple layout", &close_button_pressed,
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
                            close_button_pressed = true;
                        }
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            // Left
            static int selected = 0;
            {
                ImGui::BeginChild("left pane", ImVec2(650, 0), true);
                for (int i = 0; i < 100; i++) {
                    // FIXME: Good candidate to use
                    // ImGuiSelectableFlags_SelectOnNav
                    char label[128];
                    sprintf(label, "MyObject %d", i);
                    if (ImGui::Selectable(label, selected == i)) {
                        selected = i;
                    }
                }
                ImGui::EndChild();
            }
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
                ImGui::Text("MyObject: %d", selected);
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
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w,
                     clear_color.y * clear_color.w,
                     clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
