#include <iostream>
#include <memory>
#include "sorting-processor.h"

SortingProcessor::SortingProcessor() {};

void SortingProcessor::process(SortingAlgorithm *sort) {
    if (sort == nullptr) {
        return;
    }

    sort->get();
}