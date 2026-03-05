#pragma once

#include <iostream>
#include <memory>
#include "sorting-algorithm.h"

class SortingAlgorithmFactory {
private:
    SortingAlgorithmFactory();
    
public:
    static std::unique_ptr<SortingAlgorithm> createInsertionSort();
    static std::unique_ptr<SortingAlgorithm> createSelectionSort();
    static std::unique_ptr<SortingAlgorithm> createMergeSort();
};