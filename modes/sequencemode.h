//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_SEQUENCEMODE_H
#define PLAYLIST_SEQUENCEMODE_H

#include "mode.h"
class SequenceMode : public Mode {
public:
	SequenceMode() = default;
	~SequenceMode() = default;

	void play(std::deque<Element> const &playList) const override;
};

#endif //PLAYLIST_SEQUENCEMODE_H
