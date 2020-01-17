//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include <cstddef>
#include "element.h"
#include "../modes/mode.h"


class Playlist : public Element {
public:
	void add(Element &element);
	void add(Element &element, size_t position);
	void remove();
	void remove(size_t position);
	void setMode(Mode *mode);

	//TODO zdecydować czy chcemy referencję i overloadowanie operatora
	// czy raczej wolimy przekazywać wszędzie wskaźniki (z uwagi na przykład z playlist_example.cc, linia 20:
	// mishmash->add(..)
	Playlist *operator->() noexcept {
		return this;
	}
};

#endif //PLAYLIST_PLAYLIST_H
