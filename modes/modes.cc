//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

OddEvenMode createOddEvenMode() {
	return OddEvenMode();
}

ShuffleMode createShuffleMode(size_t seed) {
	return ShuffleMode(seed);
}

SequenceMode createSequenceMode() {
	return SequenceMode();
}
