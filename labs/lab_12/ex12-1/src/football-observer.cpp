#include "football-observer.h"
#include "football-score.h"
#include <iostream>
//task 7: Implement the methods of the FootballObserver class
FootballObserver::FootballObserver(std::string name) : name(name) {}

void FootballObserver::updateScore(ScoreSubject* subject) {
    FootballScore* score = dynamic_cast<FootballScore*>(subject);

    if (score != nullptr) {
        std::cout << name << ": "  << score->getScoreLine() << std::endl;
    }
}
