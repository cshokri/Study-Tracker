#include "user_data.h"

const bool UserData::SetDirLocation(const std::string& dir)
{
    return false;
}

const bool UserData::SetStartTime(const std::string& time)
{
    return false;
}

const void UserData::EndPassStreak()
{
    
    return void();
}

const void UserData::IncrementPassStreak()
{
    if (m_storage.SetTodaysPerformance(true)) {
        m_pass_streak += 1;
        std::cout << "Set today's performance" << std::endl;
    }
    else {
        std::cout << "Failed to set today's performance" << std::endl;
    }
}

const std::string UserData::GetDirLocation() const
{
    return m_directory_location;
}

const std::string UserData::GetStartTime() const
{
    return m_start_time;
}

const int UserData::GetPassStreak() const
{
    return m_pass_streak;
}
