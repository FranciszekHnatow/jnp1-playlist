//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

std::unique_ptr<Mode> createOddEvenMode() {
	return std::make_unique<OddEvenMode>();
}

std::unique_ptr<Mode> createShuffleMode(size_t seed) {
	return std::make_unique<ShuffleMode>(seed);
}

std::unique_ptr<Mode> createSequenceMode() {
	return std::make_unique<SequenceMode>();
}
