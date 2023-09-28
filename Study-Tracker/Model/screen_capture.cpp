#include "screen_capture.h"

ScreenCapture::ScreenCapture(std::string dir) : m_save_directory(dir) {
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	MFStartup(MF_VERSION);

	m_dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264;

	int len = MultiByteToWideChar(CP_UTF8, 0, dir.c_str(), -1, nullptr, 0);
	if (len == 0) {
		// Handle error
		std::cout << "Error with converting directory to wide string" << std::endl;
	}

	std::wstring wide_dir(len, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, dir.c_str(), -1, &wide_dir[0], len);
	m_dp.f = wide_dir;

	m_dp.HasVideo = 1;

	// To Audio
	m_dp.HasAudio = 1;
	EnumVistaMixers();
	std::vector<int> numChannels{ 0, 1 };
	m_dp.AudioFrom = {
		make_tuple(vistamixers[0].id, numChannels)
	};

	m_dp.EndMS = 0;
}

void ScreenCapture::SetSaveDirectory(std::string dir)
{
}

void ScreenCapture::StartRecording()
{
	DesktopCapture(m_dp);
}

void ScreenCapture::StopRecording()
{
	m_dp.MustEnd = true;
}
