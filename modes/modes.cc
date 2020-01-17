//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

Mode *createOddEvenMode() {
	return new OddEvenMode();
}

Mode *createShuffleMode(size_t seed) {
	return ShuffleMode(seed);
}

Mode *createSequenceMode() {
	return SequenceMode();
}
