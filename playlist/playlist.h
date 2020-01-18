//
// Created by franciszek on 11.01.2020.
//

#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include <cstddef>
#include "element.h"
#include "../modes/mode.h"


class PlayList : public Element {
public:
	void play() const override;
	void add(const std::shared_ptr<Element>& element);
	void add(const std::shared_ptr<Element>& element, size_t position);
	void remove();
	void remove(size_t position);
	void setMode(std::unique_ptr<Mode> mode);
	bool canBeAdded(const std::shared_ptr<Element>& element) override;
	PlayList() = default;
	~PlayList() override;
private:
	std::deque<std::shared_ptr<Element>> elements;
	std::unique_ptr<Mode> mode;
};

#endif //PLAYLIST_PLAYLIST_H
