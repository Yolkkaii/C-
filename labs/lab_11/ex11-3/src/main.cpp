#include "sorting-processor.h"
#include "sorting-algorithm-factory.h"
#include <iostream>
#include <memory>
using namespace std;
int main() {
SortingProcessor::process(SortingAlgorithmFactory::createInsertionSort().get());
SortingProcessor::process(SortingAlgorithmFactory::createSelectionSort().get());
SortingProcessor::process(SortingAlgorithmFactory::createMergeSort().get());
return 0;
}