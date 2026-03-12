#ifndef SCORE_SUBJECT_H
#define SCORE_SUBJECT_H
#include "score-observer.h"
#include <vector>
class ScoreSubject {
    //task 1: Complete the ScoreSubject class definition
    // this is the subject class in the observer pattern, 
    // it maintains a list of observers and notifies them of score changes
    // it should have methods to add and remove observers, and a method to notify all observers of a score change
    // you can use a vector to store the list of observers
    // the name of the method to notify observers should be notifyScore()
    // the method to add an observer should be addSubscriber(ScoreObserver* observer)
    // the method to remove an observer should be removeSubscriber(ScoreObserver* observer)
    private:
        std::vector<ScoreObserver*> observerList;

    public:
        virtual ~ScoreSubject() = default;

        void notifyScore();
        void addSubscriber(ScoreObserver* observer);
        void removeSubscriber(ScoreObserver* observer);
};
#endif // SCORE_SUBJECT_H