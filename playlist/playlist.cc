//
// Created by franciszek on 11.01.2020.
//

#include "playlist.h"

PlayList::~PlayList() {
	delete(mode.get());
}
