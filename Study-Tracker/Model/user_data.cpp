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
    return void();
}

const std::string UserData::GetDirLocation() const
{
    return m_directory_location;
}

const std::string UserData::GetStartTime() const
{
    return m_start_time;
}
