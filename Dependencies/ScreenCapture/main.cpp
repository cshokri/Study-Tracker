#include "stdafx.h"
#include "capture.hpp"
#include <iostream>

int wmain()
{
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	MFStartup(MF_VERSION);
	std::cout << "Capturing screen for 10 seconds...";
	DESKTOPCAPTUREPARAMS dp;

	// To Video
	dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264;
	dp.f = L"capture.mp4";
	dp.HasVideo = 1;
	
	// To Audio
	dp.HasAudio = 1;
	EnumVistaMixers();
	std::vector<int> numChannels{ 0, 1 };
	dp.AudioFrom = { 
		make_tuple(vistamixers[0].id, numChannels)
	};

	dp.EndMS = 10000;
	DesktopCapture(dp);
	std::cout << "Done.\r\n";
	return 0;
}

