#include "app.h"
#include "imgui.h"

#include <iostream>


void app::RenderUI() {
    bool state = false;
    ImGui::Begin("Start Test");
    state = ImGui::Button("Start Test");
    ImGui::End();
    if (state) {
        std::cout << "Clicked" << std::endl;
    }
}

void app::TestUI(EventTracker& tracker) {
    bool state = false;
    ImGui::Begin("Close");
    state = ImGui::Button(timer::SecondsToTimer(tracker.GetTestTime()).c_str());
    ImGui::End();
    if (state) {
        //glfwIconifyWindow(window);
        tracker.EndTest();
        // could make this return a boolean for success/fail
    }
}