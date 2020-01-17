//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_MODES_H
#define PLAYLIST_MODES_H

#include <cstddef>
#include "oddevenmode.h"
#include "shufflemode.h"
#include "sequencemode.h"

Mode *createOddEvenMode();
Mode *createShuffleMode(size_t seed);
Mode *createSequenceMode();

#endif //PLAYLIST_MODES_H
