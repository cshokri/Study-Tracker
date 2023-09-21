#include "stdafx.h"
#include "capture.hpp"
#include <iostream>

// Use this to open a url
//#include <windows.h>
//#include <shellapi.h>
//ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOW);

int main() {

	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	MFStartup(MF_VERSION);
	std::cout << "Capturing screen for 10 seconds...";
	DESKTOPCAPTUREPARAMS dp;

	// To Video
	dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264;
	dp.f = L"C:\\dev\\Study-Tracker\\capture.mp4";
	dp.HasVideo = 1;

	// To Audio
	dp.HasAudio = 1;
	EnumVistaMixers();
	std::vector<int> numChannels{ 0, 1 };
	dp.AudioFrom = {
		make_tuple(vistamixers[0].id, numChannels)
	};
	//%(AdditionalIncludeDirectories)
	dp.EndMS = 10000;
	DesktopCapture(dp);
	std::cout << "Done.\r\n";
	return 0;
}