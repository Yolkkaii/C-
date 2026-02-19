#include <exception>
#include <stdexcept>
#include <string>
//task 6: Define the NumberOfFieldsException class here.
// This class should inherit from std::runtime_error
// and have a constructor that takes a string message.
// The constructor should pass the message to the base class constructor.
class NumberOfFieldsException : public std::runtime_error {
    public:
        NumberOfFieldsException(const std::string& message) : std::runtime_error(message) {}
};
