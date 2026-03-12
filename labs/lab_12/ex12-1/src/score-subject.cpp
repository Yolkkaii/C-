#include "score-subject.h"
#include "score-observer.h"
#include <vector>
#include <algorithm>
//task 5: Implement the methods of the ScoreSubject class
void ScoreSubject::notifyScore() {
    for (auto observer: observerList) {
        observer->updateScore(this);
    }
}

void ScoreSubject::addSubscriber(ScoreObserver* observer) {
    observerList.push_back(observer);
}

void ScoreSubject::removeSubscriber(ScoreObserver* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}
