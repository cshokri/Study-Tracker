#include "timer.h"

#include <sstream>
#include <chrono>

std::tm timer::StrTimeToObj(const std::string &time)
{
    std::tm converted_time{};
    std::istringstream time_stream(time);

    std::string hours_str, minutes_str, seconds_str;
    std::getline(time_stream, hours_str, ':');
    std::getline(time_stream, minutes_str, ':');
    std::getline(time_stream, seconds_str);

    converted_time.tm_hour = std::stoi(hours_str);
    converted_time.tm_min = std::stoi(minutes_str);
    converted_time.tm_sec = std::stoi(seconds_str);

    return converted_time;
}

std::string timer::ObjTimeToStr(const std::tm& time)
{
    std::string hours_str, minutes_str, seconds_str;
    hours_str = std::to_string(time.tm_hour);
    minutes_str = std::to_string(time.tm_min);
    seconds_str = std::to_string(time.tm_sec);
    return hours_str + ":" + minutes_str + ":" + seconds_str;
}

std::string timer::HrMinSecToStr(const int hours, const int minutes, const int seconds)
{
    std::string hours_str, minutes_str, seconds_str;
    hours_str = std::to_string(hours);
    minutes_str = std::to_string(minutes);
    seconds_str = std::to_string(seconds);
    return hours_str + ":" + minutes_str + ":" + seconds_str;
}

std::tm timer::OffsetCurrentTime(const int minutes_offset)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::chrono::minutes minutes(minutes_offset);
    std::chrono::system_clock::time_point offset_time_point = now + minutes;

    std::time_t offset_time_t = std::chrono::system_clock::to_time_t(offset_time_point);
    std::tm offset_time;
    
    if (localtime_s(&offset_time, &offset_time_t) != 0) {
        std::cerr << "Couldn't get local time" << std::endl;
    }

    return offset_time;
}

std::string timer::SecondsToTimer(const int seconds_left)
{
    int remaining_hours = seconds_left / 3600;
    int remaining_minutes = (seconds_left % 3600) / 60;
    int remaining_seconds = seconds_left % 60;
    return timer::HrMinSecToStr(remaining_hours, remaining_minutes, remaining_seconds);
}
