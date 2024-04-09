#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }
    if (arrSize == 1) {
        return arr;
    }
    const int *minLoc = min(arr, arrSize - 1);
    if (*minLoc < arr[arrSize - 1]) {
        return minLoc;
    }
    else {
        return arr + arrSize - 1;
    }
}