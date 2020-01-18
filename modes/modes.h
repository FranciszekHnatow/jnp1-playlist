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


std::unique_ptr<Mode> createOddEvenMode();
std::unique_ptr<Mode> createShuffleMode(size_t seed);
std::unique_ptr<Mode> createSequenceMode();

#endif //PLAYLIST_MODES_H
