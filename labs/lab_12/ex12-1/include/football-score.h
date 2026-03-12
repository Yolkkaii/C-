#ifndef FOOTBALL_SCORE_H
#define FOOTBALL_SCORE_H
#include "score-subject.h"
#include <string>
//task 3: Complete the FootballScore class definition
// this class should inherit from ScoreSubject and implement 
// the specific functionality for football scores
// it should have a private member variable to store the current score line 
// (e.g. "Team A 1 - 0 Team B")
// it should have a public method setScoreLine(const std::string& score) to update 
// the score line and a method getScoreLine() to retrieve the current score line
// when the score line is updated, 
// it should call notifyScore() to notify all observers of the change
// this class is the concrete subject class in the observer pattern,
// it will be observed by concrete observer classes that display the score in different ways
class FootballScore : public ScoreSubject {
    private:
        std::string currentScoreLine;
    public:
        void setScoreLine(const std::string& score);
        std::string getScoreLine() const;
};
#endif // FOOTBALL_SCORE_H