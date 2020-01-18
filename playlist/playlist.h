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
	void add(std::shared_ptr<Element> element);
	void add(std::shared_ptr<Element> element, size_t position);
	void remove();
	void remove(size_t position);
	void setMode(std::unique_ptr<Mode> mode);
	PlayList() = default;
	~PlayList();
private:
	std::deque<Element> elements;
	std::unique_ptr<Mode> mode;
};

#endif //PLAYLIST_PLAYLIST_H
