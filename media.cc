#include "media.h"
#include <regex>
#include <string>
#include<iostream>

// UTIL FUNCTIONS DECLARATION
std::string first_match(std::string &text, std::regex &r);

void rot13(std::string &text);


// Media
bool Media::canBeAdded(const std::shared_ptr<Element> &element) {
	return true;
}

// Audio

Audio::Audio(std::string &creator) {
	std::regex beginning_regex("audio\\|");
	std::regex artist_regex("artist:[^\\|]*\\|");
	std::regex title_regex("title:[^\\|]*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string artistUncutted = first_match(creator, artist_regex);
	std::string titleUncutted = first_match(creator, title_regex);
	
	artistUncutted.erase(artistUncutted.begin(), artistUncutted.begin()+7);
	artistUncutted.erase(artistUncutted.end()-1, artistUncutted.end());
	
	titleUncutted.erase(titleUncutted.begin(), titleUncutted.begin()+6);
	titleUncutted.erase(titleUncutted.end()-1, titleUncutted.end());

	this->artist = artistUncutted;
	this->title = titleUncutted;
	this->content = creator;
}

// Video

Video::Video(std::string &creator) {

	std::regex beginning_regex("audio\\|");
	std::regex year_regex("year:[^\\|]*\\|");
	std::regex title_regex("title:[^\\|]*\\|");

	std::string helper = first_match(creator, beginning_regex);
	std::string titleUncutted = first_match(creator, title_regex);
	std::string yearUncutted = first_match(creator, year_regex);

	titleUncutted.erase(titleUncutted.begin(), titleUncutted.begin()+6);
	titleUncutted.erase(titleUncutted.end()-1, titleUncutted.end());
	
	yearUncutted.erase(yearUncutted.begin(), yearUncutted.begin()+5);
	yearUncutted.erase(yearUncutted.end()-1, yearUncutted.end());

	rot13(creator);

	//TODO exception na stoi(jaki?)
	this->title = titleUncutted;
	this->year = std::stoi(yearUncutted);
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

/* UTIL FUNCTIONS */

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
		if(a >= 'a' && a  <= 'z') {
			a = (a - 'a' - 13 + 26)%26 + 'a';
			i = char(a);
		}
		else if(a >= 'A' && a <= 'Z') {
			a = (a - 'A' - 13 + 26) %26 + 'A';
			i = char(a);
		}
	}
}