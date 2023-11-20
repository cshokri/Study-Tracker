#include "screen_capture.h"

#include <thread>

ScreenCapture::ScreenCapture(std::string dir) : m_save_directory(dir) {
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	MFStartup(MF_VERSION);

	m_dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264;

	//dir += "Capture.mp4";

	int len = MultiByteToWideChar(CP_UTF8, 0, dir.c_str(), -1, nullptr, 0);
	if (len == 0) {
		// Handle error
		std::cout << "Error with converting directory to wide string" << std::endl;
	}

	std::wstring wide_dir(len, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, dir.c_str(), -1, &wide_dir[0], len);
	m_dp.f = L"Caputre.mp4";
	//m_dp.f = wide_dir;

	m_dp.HasVideo = 1;
	m_dp.NumThreads = 2;

	// To Audio
	m_dp.HasAudio = 1;
	m_dp.EndMS = 0;
	EnumVistaMixers();
	std::vector<int> numChannels{ 0, 1 };
	m_dp.AudioFrom = {
		make_tuple(vistamixers[0].id, numChannels)
	};
}

void ScreenCapture::SetSaveDirectory(std::string dir)
{
}

void ScreenCapture::StartRecording()
{
	std::thread bt(DesktopCapture, std::ref(m_dp));

	bt.detach();
}

void ScreenCapture::StopRecording()
{
	m_dp.MustEnd = true;
}
