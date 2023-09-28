#include "View/gui.h"
#include "Model/screen_capture.h"
#include "Model/event_tracker.h"
#include "Model/data_storage.h"
#include "Model/user_data.h"

#include <iostream>

int main() {
    // Init the model
    // Have this object be the thing with all the data (doesn't have to be the one that fetches it all)
    // Then on every iteration of the while loop we can check whether it is showtime
    // Once it is showtime then a flag on the object changes which causes the rendering to change
    // Once showtime is over, the next showtime time will be set on the object and stored on disk
    // so if the program keeps running overnight it will still work and if we close it and reopen it still works
    
    DataStorage data_store = DataStorage(); // Interface write/read disk
    UserData user_info = UserData(data_store);  // Uses data store for user actions

    std::string directory_location = user_info.GetDirLocation() != "" ? user_info.GetDirLocation() : ".//";
    ScreenCapture screen_recorder = ScreenCapture(directory_location);  // The recording code

    std::string start_time = user_info.GetStartTime() != "" ? user_info.GetStartTime() : "21:19:00";
    EventTracker tracker = EventTracker(start_time);   // Call IsTestTime() to check

    // Init the view
    initView(tracker, user_info, screen_recorder);

    std::cout << "hello" << std::endl;
    return 0;
}