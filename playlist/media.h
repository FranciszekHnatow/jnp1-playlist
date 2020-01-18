//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_MEDIA_H
#define PLAYLIST_MEDIA_H

#include "element.h"
class Media : public Element {
public:
	bool canBeAdded(const std::shared_ptr<Element> &element) override;
};

#endif //PLAYLIST_MEDIA_H

