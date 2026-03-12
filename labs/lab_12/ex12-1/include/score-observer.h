#ifndef SCORE_OBSERVER_H
#define SCORE_OBSERVER_H
#include <string>
class ScoreSubject; // Forward declaration
// task 2 : Complete the ScoreObserver class definition
// this is the observer class in the observer pattern,
// it should have a pure virtual method updateScore() that takes a pointer to the ScoreSubject as a parameter, 
// this method will be called by the ScoreSubject when the score changes
class ScoreObserver {
    public:
        virtual void updateScore(ScoreSubject* subject) = 0;
        virtual ~ScoreObserver() = default;
};    

#endif // SCORE_OBSERVER_H