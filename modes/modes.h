//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_MODES_H
#define PLAYLIST_MODES_H

#include <cstddef>
#include <memory>
#include "oddevenmode.h"
#include "shufflemode.h"
#include "sequencemode.h"


pMode createOddEvenMode();
pMode createShuffleMode(size_t seed);
pMode createSequenceMode();

#endif //PLAYLIST_MODES_H
