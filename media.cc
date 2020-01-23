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

Audio::Audio(std::string creator) {
	std::regex beginning_regex("audio\\|");
	std::regex artist_regex("artist:(\\w\\d\\s)*\\|");
	std::regex title_regex("title:(\\w\\d\\s)*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string artistUncutted = first_match(creator, artist_regex);
	std::string titleUncutted = first_match(creator, title_regex);

	std::string artist = artistUncutted.substr(7, artistUncutted.size() - 8);
	std::string title = titleUncutted.substr(6, titleUncutted.size() - 7);

	this->title = title;
	this->artist = artist;
	this->content = creator;
}

// Video

Video::Video(std::string creator) {

	std::regex beginning_regex("video\\|");
	std::regex title_regex("title:(\\w\\d\\s)*\\|");
	std::regex year_regex("year:(\\d)*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string titleUncutted = first_match(creator, title_regex);
	std::string yearUncutted = first_match(creator, year_regex);

	std::string title = titleUncutted.substr(6, titleUncutted.size() - 7);
	std::string year = titleUncutted.substr(5, yearUncutted.size() - 6);

	rot13(creator);

	this->title = title;
	//TODO exception:
	this->year = std::stoi(year);
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
	for(size_t i = 0; i < text.size(); i++) {
		int a = text[i];
		if(a >= 97) {
			a = (a - 'a' - 13 + 26)%26 + 'a';
		}
		else {
			a = (a - 'A' - 13 + 26) %26 + 'A';
		}
		text[i] = char(a);
	}
}