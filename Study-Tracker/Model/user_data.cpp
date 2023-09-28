#include "user_data.h"

const bool UserData::SetDirLocation(const std::string& dir)
{
    return false;
}

const std::string UserData::GetDirLocation() const
{
    return m_directory_location;
}

const std::string UserData::GetStartTime() const
{
    return std::string();
}
