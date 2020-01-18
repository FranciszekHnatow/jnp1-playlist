//
// Created by franciszek on 12.01.2020.
//

#include "modes.h"

pMode createOddEvenMode() {
	return pMode(new OddEvenMode());
}

pMode createShuffleMode(size_t seed) {
	return pMode(new ShuffleMode(seed));
}

pMode createSequenceMode() {
	return pMode(new SequenceMode());
}
