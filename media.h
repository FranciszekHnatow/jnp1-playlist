#ifndef PLAYLIST_MEDIA_H
#define PLAYLIST_MEDIA_H

#include <string>
#include "element.h"

// Media
class Media : public Element {
public:
	bool canBeAdded(const std::shared_ptr<Element> &element) override;
	~Media() override = default;
};

// Playlist w osobnym pliku

// Audio

class Audio : public Media {
public:
	Audio(std::string &creator);
	~Audio() override = default;
	void play() override {}
private:
	std::string title;
	std::string artist;
	std::string content;
};

// Video

class Video : public Media {
public:
	Video(std::string &creator);
	~Video() override = default;
	void play() override {}
private:
	std::string title;
	std::string content;
	int year;
};


// File

class File {
public:
	File(const char *content);
	std::string getContent();

private:
	std::string content;
};


#endif //PLAYLIST_MEDIA_H

