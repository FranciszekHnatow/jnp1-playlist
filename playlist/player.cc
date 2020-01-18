//
// Created by franciszek on 11.01.2020.
//

#include "player.h"
#include "media.h"

std::shared_ptr<PlayList> Player::createPlaylist(const char *name) {
	return std::make_shared<PlayList>(name);
}

