//
// Created by franciszek on 12.01.2020.
//

#include <algorithm>
#include "shufflemode.h"
#include "../playlist/element.h"

void ShuffleMode::play(std::deque<std::shared_ptr<Element>> const &playList) const {
	std::vector<size_t> indexes(playList.size());
	std::iota(indexes.begin(), indexes.end(), 0);
	std::shuffle(indexes.begin(), indexes.end(), engine);
	for (size_t index : indexes) {
		playList[index]->play();
	}
}