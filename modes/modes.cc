//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

std::unique_ptr<Mode> createOddEvenMode() {
	return std::unique_ptr<Mode>(new OddEvenMode());
}

std::unique_ptr<Mode> createShuffleMode(size_t seed) {
	return std::unique_ptr<Mode>(new ShuffleMode(seed));
}

std::unique_ptr<Mode> createSequenceMode() {
	return std::unique_ptr<Mode>(new SequenceMode());
}
