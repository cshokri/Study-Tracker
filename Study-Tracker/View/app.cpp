#include "app.h"
#include "imgui.h"

#include <iostream>


void app::RenderUI(UserData& user_info) {
    int pass_streak = user_info.GetPassStreak();
    std::string pass_streak_text = "Current Pass Streak: " + std::to_string(pass_streak);
    ImGui::Begin("Dashboard");
    ImGui::Text("%s", pass_streak_text.c_str());
    ImGui::End();

    bool state = false;
    ImGui::Begin("Start Test");
    state = ImGui::Button("Start Test");
    ImGui::End();
    if (state) {
        std::cout << "Clicked" << std::endl;
    }
}

void app::TestUI(EventTracker& tracker, UserData& user_info, ScreenCapture& recorder) {
    bool state = false;
    ImGui::Begin("Close");
    state = ImGui::Button(timer::SecondsToTimer(tracker.GetTestTime()).c_str());
    ImGui::End();
    // User passed the test
    if (state) {
        //glfwIconifyWindow(window);
        tracker.EndTest();
        user_info.IncrementPassStreak();
        // could make this return a boolean for success/fail
    }
}