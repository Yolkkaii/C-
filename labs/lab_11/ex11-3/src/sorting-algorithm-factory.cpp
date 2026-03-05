#include <iostream>
#include <memory>
#include "sorting-algorithm-factory.h"
#include "insertion-sort.h"
#include "selection-sort.h"
#include "merge-sort.h"

SortingAlgorithmFactory::SortingAlgorithmFactory() {}

std::unique_ptr<SortingAlgorithm> SortingAlgorithmFactory::createInsertionSort() {
    return std::make_unique<InsertionSort>();
}

std::unique_ptr<SortingAlgorithm> SortingAlgorithmFactory::createSelectionSort() {
    return std::make_unique<SelectionSort>();
}

std::unique_ptr<SortingAlgorithm> SortingAlgorithmFactory::createMergeSort() {
    return std::make_unique<MergeSort>();
}