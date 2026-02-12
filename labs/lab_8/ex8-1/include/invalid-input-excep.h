#ifndef INVALID_INPUT_EXCEP_H
#define INVALID_INPUT_EXCEP_H
#include <stdexcept>
//task 8: Define the InvalidInputException class here.
// This class should inherit from std::runtime_error
// and have a constructor that takes a string message.
// The constructor should pass the message to the base class constructor.
class InvalidInputException : public std::runtime_error {
    public:
        InvalidInputException(const std::string& message)
            : std::runtime_error(message) {}
};

#endif // INVALID_INPUT_EXCEP_H