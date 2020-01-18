//
// Created by franciszek on 12.01.2020.
//

#include "sequencemode.h"
#include "../playlist/element.h"

void SequenceMode::play(std::deque<std::shared_ptr<Element>> const &playList) const {
	for (std::shared_ptr<Element> element : playList) {
		element->play();
	}
}