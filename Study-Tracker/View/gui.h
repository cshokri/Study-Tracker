#pragma once

#include "../Model/event_tracker.h"
#include "../Model/user_data.h"
#include "../Model/screen_capture.h"

// TODO: The cazz guy uses win32 api and i am using vulkan so it's a no go there
// tho my recording code only works on windows anyways so idk
// can try going down the vulkan route and if it is doomed just run it back.

// TODO: Should these be references?
int initView(EventTracker& tracker, UserData& user_info, ScreenCapture& recorder);