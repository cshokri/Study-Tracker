#pragma once

#include "../Model/event_tracker.h"
#include "../Model/screen_capture.h"

namespace app {
    void RenderUI(UserData& user_info);
    void TestUI(EventTracker& tracker, UserData& user_info, ScreenCapture& recorder);
}