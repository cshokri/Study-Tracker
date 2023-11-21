#include "screen_capture.h"

#include <thread>

ScreenCapture::ScreenCapture(std::string dir) : m_save_directory(dir) {
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	MFStartup(MF_VERSION);

	m_dp.VIDEO_ENCODING_FORMAT = MFVideoFormat_H264;

	/*
	// Set the file name and location
	std::string file_location = m_save_directory;
	// TODO: Filter the video name for invalid characters
	file_location += video_name;

	// Convert the string to a wstring
	int len = MultiByteToWideChar(CP_UTF8, 0, file_location.c_str(), -1, nullptr, 0);
	if (len == 0) {
		// Handle error
		std::cout << "Error with converting file location to wide string" << std::endl;
	}

	std::wstring wide_file_dir(len, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, file_location.c_str(), -1, &wide_file_dir[0], len);
	m_dp.f = wide_file_dir;
	*/

	m_dp.f = L"temp.mp4";

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

void ScreenCapture::SetSaveDirectory(std::string dir) {
	m_save_directory = dir;
}

void ScreenCapture::StartRecording() {
	std::thread bt(DesktopCapture, std::ref(m_dp));

	bt.detach();
}

void ScreenCapture::StopRecording(std::string video_name) {
	m_dp.MustEnd = true;

	if (std::rename("temp.mp4", (m_save_directory + video_name + ".mp4").c_str()) != 0) {
		std::cerr << "Error moving file" << std::endl;
	}
	else {
		std::cout << "File moved successfully" << std::endl;
	}
}
