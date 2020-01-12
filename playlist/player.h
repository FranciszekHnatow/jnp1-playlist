//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_PLAYER_H
#define PLAYLIST_PLAYER_H

#include "file.h"
#include "playlist.h"

class Player {
public:
	Playlist &createPlaylist(const char *name);
	Element &openFile(File file);

};

#endif //PLAYLIST_PLAYER_H
