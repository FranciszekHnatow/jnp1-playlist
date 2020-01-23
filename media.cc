#include "media.h"
#include <regex>
#include <string>

// UTIL FUNCTION
std::string first_match(std::string &text, std::regex &r);

void rot13(std::string &text);


// Media
bool Media::canBeAdded(const std::shared_ptr<Element> &element) {
	return true;
}

// Audio

Audio::Audio(std::string &creator) {
	std::regex beginning_regex("audio\\|");
	std::regex artist_regex("artist:(\\w\\d\\s)*\\|");
	std::regex title_regex("title:(\\w\\d\\s)*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string artistUncutted = first_match(creator, artist_regex);
	std::string titleUncutted = first_match(creator, title_regex);

	artist = artistUncutted.substr(7, artistUncutted.size() - 8);
	title = titleUncutted.substr(6, titleUncutted.size() - 7);

	this->content = creator;
}

// Video

Video::Video(std::string &creator) {

	std::regex beginning_regex("video\\|");
	std::regex title_regex("title:(\\w\\d\\s)*\\|");
	std::regex year_regex("year:(\\d)*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string titleUncutted = first_match(creator, title_regex);
	std::string yearUncutted = first_match(creator, year_regex);

	title = titleUncutted.substr(6, titleUncutted.size() - 7);
	year = std::stoi(titleUncutted.substr(5, yearUncutted.size() - 6));

	rot13(creator);

	//TODO exception:
	this->content = creator;
}

// File

File::File(const char* content) {
	std::string helper(content);
	this->content = helper;
}

std::string File::getContent() {
	return this->content;
}

/* UTIL FUNCTION */

std::string first_match(std::string &text, std::regex &r) {
    std::smatch match;
    std::regex_search(text, match, r);
    std::string res = match.str(0);
    text = match.suffix().str();
    return res;
}

void rot13(std::string &text) {
	for(char & i : text) {
		int a = i;
		if(a >= 97) {
			a = (a - 'a' - 13 + 26)%26 + 'a';
		}
		else {
			a = (a - 'A' - 13 + 26) %26 + 'A';
		}
		i = char(a);
	}
}