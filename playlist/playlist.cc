//
// Created by franciszek on 11.01.2020.
//

#include "playlist.h"

PlayList::~PlayList() {
	delete(mode.get());
}

void PlayList::play() const {
	mode->play(elements);
}

void PlayList::setMode(std::unique_ptr<Mode> mode) {
	if(this->mode) {
		delete(mode.get());
	}

	this->mode = std::move(mode);
}

void PlayList::add(const std::shared_ptr<Element>& element) {
	if (canAdd(element)) {
		elements.push_back(element);
	}
}

void PlayList::add(const std::shared_ptr<Element>& element, size_t position) {
	if (canAdd(element)) {
		elements.insert(elements.begin() + position, element);
	}
}

void PlayList::remove() {
	elements.pop_back();
}

void PlayList::remove(size_t position) {
	elements.erase(elements.begin() + position);
}