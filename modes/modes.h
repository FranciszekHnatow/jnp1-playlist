//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_MODES_H
#define PLAYLIST_MODES_H

#include <cstddef>
#include "oddevenmode.h"
#include "shufflemode.h"
#include "sequencemode.h"

OddEvenMode createOddEvenMode();
ShuffleMode createShuffleMode(size_t seed);
SequenceMode createSequenceMode();

#endif //PLAYLIST_MODES_H
