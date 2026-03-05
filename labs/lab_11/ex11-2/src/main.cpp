#include "insertion-sort.h"
#include "sorting-processor.h"
#include "selection-sort.h"
#include "merge-sort.h"
#include <iostream>
#include <memory>
using namespace std;
int main() {
    SortingProcessor::process(make_unique<InsertionSort>().get());
    SortingProcessor::process(make_unique<SelectionSort>().get());
    SortingProcessor::process(make_unique<MergeSort>().get());
    return 0;
}