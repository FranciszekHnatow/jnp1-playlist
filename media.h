#ifndef PLAYLIST_MEDIA_H
#define PLAYLIST_MEDIA_H

#include "element.h"

// Media
class Media : public Element {
public:
	bool canBeAdded(const std::shared_ptr<Element> &element) override;
};

// Playlist w osobnym pliku

// Audio

class Audio : Media {

};


// File

class File {
public:
	File(const char *content);
};


// Video

class Video : Media {

};

#endif //PLAYLIST_MEDIA_H

