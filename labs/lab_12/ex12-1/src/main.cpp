/*
    ID: 68011278
    Name: Ananda Stallard
    Lab No: 12
    Question No: 1
    Date: March 12, 2026
*/
#include <iostream>
#include <memory>
#include <string>
#include "football-score.h"
#include "football-observer.h"
using namespace std;
int main() {
    auto footballScore = make_unique<FootballScore>();
    auto footballObserver1 = make_unique<FootballObserver>("subscriber 1");
    auto footballObserver2 = make_unique<FootballObserver>("subscriber 2");
    auto footballObserver3 = make_unique<FootballObserver>("subscriber 3");
    footballScore->addSubscriber(footballObserver1.get());
    footballScore->addSubscriber(footballObserver2.get());
    footballScore->addSubscriber(footballObserver3.get());
    int count = 1;
    while(true) {
        cout << "Enter new score (or 'exit' to quit): ";
        string newScore;
        getline(cin, newScore);
        if (newScore == "exit") {
            break;
        }
        footballScore->setScoreLine(newScore);
        footballScore->notifyScore();
        count++;
        if (count == 3) {
            cout << "Subscriber 3 unsubscribes" << endl;
            footballScore->removeSubscriber(footballObserver3.get());
        }
    }
    return 0;
}