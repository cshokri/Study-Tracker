#pragma once

#include "user_data.h"
#include "timer.h"

#include <iostream>
#include <sstream>
#include <ctime>

class EventTracker {
public:
    EventTracker(std::string start_time) : m_start_time(timer::StrTimeToObj(start_time)),
        m_test_duration_seconds(0),
        m_test_in_progress(false),
        m_test_over(false) {};

    const bool IsTestTime();
    // Test duration in minutes
    void StartTest(int test_duration);
    const bool IsTestOver();
    const bool IsTestInProgress();
    int GetTestTime();
    void EndTest();
private:
    std::tm m_start_time = {};
    std::chrono::steady_clock::time_point m_starting_time;
    std::tm m_end_time = {};
    int m_test_duration_seconds;
    bool m_test_in_progress;
    bool m_test_over;
};
