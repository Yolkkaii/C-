#include "football-score.h"
#include <string>
//task6: Implement the methods of the FootballScore class
void FootballScore::setScoreLine(const std::string& score) {
    currentScoreLine = score;
}

std::string FootballScore::getScoreLine() const {
    return currentScoreLine;
}
