#ifndef INVALID_INPUT_EXCEP_H
#define INVALID_INPUT_EXCEP_H
#include <stdexcept>
class InvalidInputException : public std::runtime_error {
    public:
        InvalidInputException(const std::string& message)
            : std::runtime_error(message) {}
};
#endif // INVALID_INPUT_EXCEP_H