#include "player.h"
#include "media.h"

#include<regex>

std::shared_ptr<PlayList> Player::createPlaylist(const char *name) {
	return std::make_shared<PlayList>(name);
}

std::shared_ptr<Element> openFile(File file) {
	std::regex audio_regex ("^audio\\|artist:(\\w|\\d|\\s)*\\|title:(\\w|\\d|\\s)*\\|.*");
	std::regex video_regex("^video\\|title:(\\w|\\d|\\s)*\\|year:(\\d)*\\|.*");

	std::string toConvert = file.getContent();

	// TODO krzyczy na returnowane :c 
	if(std::regex_match(toConvert, audio_regex)) {
		return std::make_shared<Audio>(toConvert);
	}
	if(std::regex_match(toConvert, video_regex)) {
		return std::make_shared<Video>(toConvert);
	}
	// TODO: throw exception - incorrect title
	
}

