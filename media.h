#ifndef PLAYLIST_MEDIA_H
#define PLAYLIST_MEDIA_H

#include <string>
#include "element.h"

// Media
class Media : public Element {
public:
	bool canBeAdded(const std::shared_ptr<Element> &element) override;
};

// Playlist w osobnym pliku

// Audio

class Audio : Media {
public:
	Audio(std::string creator);
	
private:
	std::string title;
	std::string artist;
	std::string content;
};

// Video

class Video : Media {
public:
	Video(std::string creator);
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

