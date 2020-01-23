//
// Created by franciszek on 23.01.2020.
//

#ifndef PLAYLIST_EXCEPTIONS_H
#define PLAYLIST_EXCEPTIONS_H

#include <exception>

class PlayerException : public std::exception{};

class CorruptedFileException : public PlayerException {
	[[nodiscard]] const char* what() const noexcept override {return "aha";};
};

class CorruptedFileContentException : public PlayerException {
	[[nodiscard]] const char* what() const noexcept override {return "aha2";};
};

class UnsupportedFormatException : public PlayerException {
	[[nodiscard]] const char* what() const noexcept override {return "aha3";};
};




#endif //PLAYLIST_EXCEPTIONS_H
