//
// Created by franciszek on 11.01.2020.
//

#include "playlist.h"

void PlayList::play() {
	mode->play(elements);
}

void PlayList::setMode(std::shared_ptr<Mode> newMode) {
	this->mode = newMode;
}

void PlayList::add(const std::shared_ptr<Element>& element) {
	if (element->canBeAdded(shared_from_this())) {
		elements.push_back(element);
	}
}

void PlayList::add(const std::shared_ptr<Element>& element, size_t position) {
	if (element->canBeAdded(shared_from_this())) {
		elements.insert(elements.begin() + position, element);
	}
}

void PlayList::remove() {
	elements.pop_back();
}

void PlayList::remove(size_t position) {
	elements.erase(elements.begin() + position);
}

bool PlayList::canBeAdded(const std::shared_ptr<Element> &element) {
	if (this == element.get()) {
		return false;
	}

	for (const auto& e : elements) {
		if (!e->canBeAdded(element)) {
			return false;
		}
	}

	return true;
}
