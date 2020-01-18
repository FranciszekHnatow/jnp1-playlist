//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_BASEMODE_H
#define PLAYLIST_BASEMODE_H

#include <deque>
class Element;


// TODO tutaj na pewno przyda się Strategy i Factory Patterns
class Mode {
public:
	virtual void play(std::deque<Element> const &playList) const = 0;
	Mode() = default;
	~Mode() = default;
};

using pMode = std::unique_ptr<Mode>;

#endif //PLAYLIST_BASEMODE_H
