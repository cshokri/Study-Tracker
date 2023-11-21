#pragma once

#include <ctime>
#include <iostream>

namespace timer {
    std::tm StrTimeToObj(const std::string& time);
    std::string ObjTimeToStr(const std::tm& time);
    std::string HrMinSecToStr(const int hours, const int minutes, const int seconds);
    std::tm OffsetCurrentTime(const int minutes_offset);
    std::string SecondsToTimer(const int seconds_left);
    std::string GetCurrentDate();
}