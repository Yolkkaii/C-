#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>
#include "invalid-input-excep.h"
class Input {
    private:
        static void clearInputStream();
    public:
        static std::string getString(const std::string& prompt);
        static int getInt(const std::string& prompt);
        static double getDouble(const std::string& prompt);
};
 
#endif // INPUT_H