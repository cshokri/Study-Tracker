#pragma once
#include "data_storage.h"
#include <iostream>

class UserData {
public:
    UserData(DataStorage storage) : m_storage(storage),
        m_directory_location(storage.GetVodDirectory()),
        m_pass_streak(storage.GetPassStreak()),
        m_total_test_count(storage.GetTotalTestCount()) {

    };

    const bool SetDirLocation(const std::string& dir);
    const std::string GetDirLocation() const;

    const std::string GetStartTime() const;
private:
    DataStorage m_storage;
    std::string m_directory_location;
    int m_pass_streak;
    int m_total_test_count;
};