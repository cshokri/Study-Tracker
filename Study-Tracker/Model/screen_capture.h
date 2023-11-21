#pragma once

#include "stdafx.h"
#include "capture.hpp"

#include <Windows.h>
#include <iostream>
#include <codecvt>

class ScreenCapture {
public:
    ScreenCapture(std::string dir);

    void SetSaveDirectory(std::string dir);
    void StartRecording();
    void StopRecording(std::string video_name);
private:
    std::string m_save_directory;
    DESKTOPCAPTUREPARAMS m_dp;
};