//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_ELEMENT_H
#define PLAYLIST_ELEMENT_H


#include <memory>

class Element {
public:
	virtual void play() const = 0;
	virtual bool canBeAdded(const std::shared_ptr<Element> &element) = 0;
	Element() = default;
	virtual ~Element() = default;
};



#endif //PLAYLIST_ELEMENT_H
