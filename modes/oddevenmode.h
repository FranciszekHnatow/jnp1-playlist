//
// Created by franciszek on 12.01.2020.
//

#ifndef PLAYLIST_ODDEVENMODE_H
#define PLAYLIST_ODDEVENMODE_H

#include "mode.h"
class OddEvenMode : public Mode {
public:
	OddEvenMode() = default;
	~OddEvenMode() override = default;

	void play(std::deque<std::shared_ptr<Element>> const &playList) const override;
};


#endif //PLAYLIST_ODDEVENMODE_H
