//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include <cstddef>
#include "element.h"
#include "../modes/mode.h"


class PlayList : public Element {
public:
	void add(pElement element);
	void add(pElement element, size_t position);
	void remove();
	void remove(size_t position);
	void setMode(pMode mode);

};

using pPlayList = std::unique_ptr<PlayList>;

#endif //PLAYLIST_PLAYLIST_H
