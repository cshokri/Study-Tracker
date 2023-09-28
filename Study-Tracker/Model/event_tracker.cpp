#include "event_tracker.h"
#include "user_data.h"

#include <chrono>

const bool EventTracker::IsTestTime()
{
    std::time_t now = std::time(nullptr);
    std::tm current_time;
    if (localtime_s(&current_time, &now) != 0) {
        return false;
    }

    if (current_time.tm_hour == m_start_time.tm_hour &&
        current_time.tm_min == m_start_time.tm_min &&
        current_time.tm_sec == m_start_time.tm_sec &&
        !m_test_in_progress) {
        std::cout << "Action triggered at " << current_time.tm_hour << ":" << current_time.tm_min << ":" << current_time.tm_sec << std::endl;
        return true;
    }
    return false;
}

void EventTracker::StartTest(int test_duration) {
    m_starting_time = std::chrono::steady_clock::now();
    m_test_in_progress = true;
    m_test_duration_seconds = test_duration * 60;
    m_end_time = timer::OffsetCurrentTime(test_duration);
}

const bool EventTracker::IsTestOver() {
    std::time_t now = std::time(nullptr);
    std::tm current_time;
    if (localtime_s(&current_time, &now) != 0) {
        return false;
    }

    if (current_time.tm_hour == m_end_time.tm_hour &&
        current_time.tm_min == m_end_time.tm_min &&
        current_time.tm_sec == m_end_time.tm_sec &&
        m_test_in_progress) {
        std::cout << "Action triggered at " << current_time.tm_hour << ":" << current_time.tm_min << ":" << current_time.tm_sec << std::endl;
        return true;
    }
    return false;
}

const bool EventTracker::IsTestInProgress() {
    return m_test_in_progress;
}

int EventTracker::GetTestTime() {
    std::chrono::seconds total_duration(m_test_duration_seconds);

    auto current_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = current_time - m_starting_time;
    std::chrono::seconds remaining_duration = total_duration - std::chrono::duration_cast<std::chrono::seconds>(elapsed_seconds);

    return remaining_duration.count();
}

void EventTracker::EndTest() {
    m_test_in_progress = false;
}
