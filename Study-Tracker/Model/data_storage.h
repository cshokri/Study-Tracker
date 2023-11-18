#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <iostream>

class DataStorage {
public:
    DataStorage(const std::string& default_dir, const std::string& default_time);
    
    bool SetStartTime(const std::string& start_time);
    std::string GetStartTime() const;
    bool SetVodDirectory(const std::string& dir);
    std::string GetVodDirectory() const;
    bool SetTodaysPerformance(const bool passed);
    const int GetPassStreak() const;
    const int GetTotalTestCount() const;
private:
    const int kMaxInitRetries = 3;
    const std::string kDefaultStartTime = "11:00:00";
    const std::string kDefaultVodDirectory = ".//";
};