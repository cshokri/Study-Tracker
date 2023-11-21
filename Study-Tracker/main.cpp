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
    std::string default_directory = ".//";
    std::string default_time = "14:42:00";
    
    DataStorage data_store = DataStorage(default_directory, default_time); // Interface write/read disk
    UserData user_info = UserData(data_store);  // Uses data store for user actions

    std::string directory_location = user_info.GetDirLocation();
    /* TODO: Once the defaults are verified to work you can delete this
    if (directory_location == "") {
        data_store.SetVodDirectory(default_directory);
        directory_location = default_directory;
    }
    */
    ScreenCapture screen_recorder = ScreenCapture(directory_location);  // The recording code

    std::string start_time = user_info.GetStartTime();
    /*
    if (start_time == "") {
        data_store.SetStartTime(default_time);
        start_time = default_time;
    }
    */
    EventTracker tracker = EventTracker(start_time);   // Call IsTestTime() to check

    // Init the view
    initView(tracker, user_info, screen_recorder);

    std::cout << "hello" << std::endl;
    return 0;
}