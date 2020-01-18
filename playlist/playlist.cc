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
	if (element->canBeAdded(std::shared_ptr<Element>(this))) {
		elements.push_back(element);
	}
}

void PlayList::add(const std::shared_ptr<Element>& element, size_t position) {
	if (element->canBeAdded(std::shared_ptr<Element>(this))) {
		elements.insert(elements.begin() + position, element);
	}
}

void PlayList::remove() {
	if (elements.back().unique() && elements.back()->isDisposable()) {
		delete(elements.back().get());
	}
	elements.pop_back();
}

void PlayList::remove(size_t position) {
	if (elements[position - 1].unique() && elements[position]->isDisposable()) {
		delete(elements.back().get());
	}
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
