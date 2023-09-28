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
    void StopRecording();
private:
    std::string m_save_directory;
    DESKTOPCAPTUREPARAMS m_dp;
};