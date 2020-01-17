//
// Created by franciszek on 12.01.2020.
//

#include "sequencemode.h"
#include "../playlist/element.h"

void SequenceMode::play(std::deque<Element> const &playList) const {
	for (Element element : playList) {
		element.play();
	}
}