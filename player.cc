#include "player.h"
#include "exceptions.h"

#include<regex>

std::shared_ptr<PlayList> Player::createPlaylist(const char *name) {
	return std::make_shared<PlayList>(name);
}

std::shared_ptr<Audio> get_audio(std::string &toConvert) {
	return std::make_shared<Audio>(toConvert);
}

std::shared_ptr<Media> Player::openFile(File file) {
	std::regex audio_regex ("^audio\\|artist:(\\w|\\d|\\s)*\\|title:(\\w|\\d|\\s)*\\|.*");
	std::regex video_regex("^video\\|title:(\\w|\\d|\\s)*\\|year:(\\d)*\\|.*");

	std::string toConvert = file.getContent();

	if(std::regex_match(toConvert, audio_regex)) {
		return std::static_pointer_cast<Media>(std::make_shared<Audio>(toConvert));
	} else if(std::regex_match(toConvert, video_regex)) {
		return std::static_pointer_cast<Media>(std::make_shared<Video>(toConvert));
	} else {
		throw UnsupportedFormatException();
	}
}


