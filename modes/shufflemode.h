//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_SHUFFLEMODE_H
#define PLAYLIST_SHUFFLEMODE_H

#include <random>
#include "mode.h"

class ShuffleMode : public Mode {
public:
	explicit ShuffleMode(size_t seed) : engine(seed){};
	~ShuffleMode() = default;

	void play(std::deque<Element> const &playList) const override;
private:
	std::default_random_engine engine;
};


#endif //PLAYLIST_SHUFFLEMODE_H
