//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_ELEMENT_H
#define PLAYLIST_ELEMENT_H


#include <memory>

class Element {
public:
	void play() const;
	//TODO Albo tak, albo przesuwamy setMode do playlist i używamy Observer pattern żeby powiadamiać pozostałe listy
	// w drzewie. (To drugie chyba lepsze, bo pewnie i tak będzie trzeba trzymać listę/mapę identyfikującą wszystkie
	// playlisty w drzewie, żeby nie dodawać powtórek)
};



#endif //PLAYLIST_ELEMENT_H
