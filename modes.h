
#ifndef PLAYLIST_MODES_H
#define PLAYLIST_MODES_H

#include <cstddef>
#include <memory>
#include<random>
#include "mode.h"

//modes.h
std::shared_ptr<Mode> createOddEvenMode();
std::shared_ptr<Mode> createShuffleMode(size_t seed);
std::shared_ptr<Mode> createSequenceMode();


//  ShuffleMode (from shufflemode.h)
class ShuffleMode : public Mode {
public:
	explicit ShuffleMode(size_t seed) : engine(seed){};
	~ShuffleMode() override = default;

	void play(std::deque<std::shared_ptr<Element>> const &playList) const override;
private:
	std::default_random_engine engine;
};

// OddEvenMode (from oddevenmode.h)
class OddEvenMode : public Mode {
public:
	OddEvenMode() = default;
	~OddEvenMode() override = default;

	void play(std::deque<std::shared_ptr<Element>> const &playList) const override;
};

// SequenceMode (from sequence.h)
class SequenceMode : public Mode {
public:
	SequenceMode() = default;
	~SequenceMode() override = default;

	void play(std::deque<std::shared_ptr<Element>> const &playList) const override;
};


#endif //PLAYLIST_MODES_H
