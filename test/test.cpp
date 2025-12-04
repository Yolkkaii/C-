#include <iostream>
using namespace std;
#include <string>

// Main function to get user's name & mood to reply with a message
int main() {
    // // std::string name; -- Instead of this, thanks to namespace:
    // string name; // We can use this without the std::
    // int mood {0};

    // cout << "Please, tell me your name: ";
    // getline(std::cin, name); // We have to use getline for input that requires " " since regular cin gets input SEPERATED by " "

    // cout << "How are you feeling on a scale of 1 to 10? ";
    // cin >> mood;

    // const double PI {3.14159}; // This is a constant variable, usually being named in all CAPS, it's value can't be changed
    // // #define PI 3.14159 -- This also defines a constant, but using preprocessing to replace all instances of PI in the code before compilation

    // if (mood < 6){
    //     cout << "I'm sorry to hear that " << name << ", hope it gets better!";
    // } else {
    //     cout << "That's good to hear " << name << "!";
    // };

    // int first_num {0};
    // int second_num {0};

    // cout << "Enter a number: ";
    // cin >> first_num;

    // cout << "Enter a second number to add to the first: ";
    // cin >> second_num;

    // cout << "The sum is " << first_num + second_num << endl; //endl adds an end line

    // int sum {first_num + second_num};

    // cout << "Sum incremented by 1: " << ++sum << endl; //If it is ++VAR it will increment before printing, if it is after (VAR++), it will increment after the line is finished

    // //Type casting
    // int flt = static_cast<float>(sum);

    // cout << "Adding 0.5 to the int Sum: " << flt + 0.5 << endl;

    // // short a = 32768; -- if a number overflows (short is min-max -32768-32767) it will go back to the first numbers

    int a;
    double b;

    cin >> a >> b; //Recieves multiple inputs using one line!

    return 0;
}
