#ifndef FOOTBALL_OBSERVER_H
#define FOOTBALL_OBSERVER_H
#include "score-observer.h"
#include "score-subject.h"
#include <string>
//task 4: Complete the FootballObserver class definition
// this class should inherit from ScoreObserver and implement 
// the specific functionality for football score observers
// it should have a private member variable to store the name of the observer 
// (e.g. "subscriber 1")
// it should have a constructor that takes the name of the observer as a parameter and initializes the member variable
// it should implement the updateScore() method to display the updated score
// this class is the concrete observer class in the observer pattern,
// it will be notified by the FootballScore class when the score changes 
// and will display the updated score in a specific way 

class FootballObserver : public ScoreObserver {
    private:
        std::string name;
    public:
        FootballObserver(std::string name);
        void updateScore(ScoreSubject* subject) override;
};
#endif // FOOTBALL_OBSERVER_H