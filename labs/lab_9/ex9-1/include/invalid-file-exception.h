#ifndef INVALID_FILE_EXCEPTION_H
#define INVALID_FILE_EXCEPTION_H
#include <stdexcept>
//task 4: Define the InvalidFileException class here.
// This class should inherit from std::runtime_error
// and have a constructor that takes a string message.
// The constructor should pass the message
// to the base class constructor.
class InvalidFileException : public std::runtime_error {
    public:
        InvalidFileException(const std::string& message) : std::runtime_error(message) {}
};

#endif // INVALID_FILE_EXCEPTION_H