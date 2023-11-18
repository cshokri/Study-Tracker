#pragma once
#include "data_storage.h"
#include <iostream>

/*
* This class is to obfuscate certain interactions with the datastore.
*/
class UserData {
public:
    UserData(DataStorage storage) : m_storage(storage),
        m_directory_location(storage.GetVodDirectory()),
        m_start_time(storage.GetStartTime()),
        m_pass_streak(storage.GetPassStreak()),
        m_total_test_count(storage.GetTotalTestCount()) {

    };

    const bool SetDirLocation(const std::string& dir);
    const bool SetStartTime(const std::string& time);
    const void EndPassStreak();
    const void IncrementPassStreak();
    const std::string GetDirLocation() const;
    const std::string GetStartTime() const;
    const int GetPassStreak() const;
private:
    DataStorage m_storage;
    std::string m_start_time;
    std::string m_directory_location;
    int m_pass_streak;
    int m_total_test_count;
};