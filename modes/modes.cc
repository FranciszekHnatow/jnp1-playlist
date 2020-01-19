//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

std::shared_ptr<Mode> createOddEvenMode() {
	static std::shared_ptr<OddEvenMode> instance = std::make_shared<OddEvenMode>();
	return instance;
}

std::shared_ptr<Mode> createShuffleMode(size_t seed) {
	return std::make_shared<ShuffleMode>(seed);
}

std::shared_ptr<Mode> createSequenceMode() {
	static std::shared_ptr<SequenceMode> instance = std::make_shared<SequenceMode>();
	return instance;
}
