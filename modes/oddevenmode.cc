//
// Created by franciszek on 12.01.2020.
//

#include "oddevenmode.h"
#include "../playlist/element.h"

void OddEvenMode::play(std::deque<std::shared_ptr<Element>> const &playList) const {
	size_t n = playList.size();

	for (size_t i = 0; i < n; i += 2) {
		playList[i]->play();
	}

	for (size_t i = 1; i < n; i += 2) {
		playList[i]->play();
	}
}