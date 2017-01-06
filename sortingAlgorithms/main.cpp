#include <iostream>

using namespace std;

int arrBubble[] = {2, 3, 1, 5, 4};
int arrAscend[] = {2, 3, 1, 5, 4};
int arrDescend[] = {2, 3, 1, 5, 4};
int arrSelect[] = {2, 3, 1, 5, 4};
int arrInsert[] = {13, 81, 92, 65, 43, 31, 57, 26, 75, 0};
int arrQuick[] = {13, 81, 92, 65, 43, 31, 57, 26, 75, 0};

//
// partition an array into 2 halves
//
//      select pivot as first element in the array
//      loop over the array from first to last
//      compare each value to the pivot
//          if a value less than pivot:
//              set the value at the pivot index to the current value
//              increment the pivot index
//              move all values below pivot index down to the current value index
//              set the value at the new pivotIndex equal to pivot value
//          if higher than pivot, do nothing
//      return the new pivot index that divides the array into 2 subarrays
//
int partition(int *arr, int size, int pivotIndex)
{
    int pivot = arr[pivotIndex];
    int start = pivotIndex;
    for (int i = start; i < size + start; ++i) {
        //
        // if value less than pivot...
        //
        if (arr[i] < pivot) {
            arr[pivotIndex] = arr[i];
            ++pivotIndex;
            for (int j = i; j > pivotIndex; --j) {
                arr[j] = arr[j - 1];
            }
            arr[pivotIndex] = pivot;
        }
    }
    return pivotIndex;
}

// Quick sort - recursive divide and conquer
//
// select a pivot value
//  base case: lower array size is equal to 1
//      return
//  recursive case:
//      partition array into two subarrays
//      - one subarray has values less than pivot
//          - call quick sort with this array
//      - one subarray has values greater than the pivot
//          - call quick sort with this array
//
void quickSort(int *arr, int startIndex, int endIndex)
{
    int size = endIndex - startIndex + 1;
    //
    // base case
    //
    if (size < 2) {
        return;
    }
    //
    // recursive case
    //      the new pivot location defines one end of each subarray
    //      the end of the less array is new pivot index - 1
    //      the start of the greater array is new pivot index + 1
    //
    else {
        int oldPivotIndex = startIndex;
        int newPivotIndex = partition(arr, size, oldPivotIndex);
        //
        // lower values
        //
        quickSort(arr, oldPivotIndex, newPivotIndex - 1);
        //
        // upper values
        //
        quickSort(arr, newPivotIndex + 1, endIndex);
    }
}

int main()
{
    cout << "unsorted bubble:" << endl;
    int n = (int)(sizeof(arrBubble)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrBubble[i] << endl;
    }
    //
    // Conventional bubble sort
    //  1. loop through the array a number of times equal to the size of the array
    //  2. each iteration in each loop will compare two consecutive array elements
    //  3. if the first is greater than the second, swap the elements (sort ascending)
    //  4. alternatively, if the first is less than the second, swap the elements (sort descending)
    //

    // loop over the array...
    for (int i = 0; i < n; ++i) {
        // each iteration, ...
        for (int j = 0; j < n - 1; ++j) {
            // compare and swap...
            if (arrBubble[j] > arrBubble[j+1]) {
                cout << "bubble swap..." << endl;
                int temp = arrBubble[j];
                arrBubble[j] = arrBubble[j+1];
                arrBubble[j+1] = temp;
            }
        }
    }
    cout << "sorted bubble:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrBubble[i] << endl;
    }

    cout << "unsorted ascending modified bubble:" << endl;
    n = (int)(sizeof(arrAscend)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrAscend[i] << endl;
    }

    //
    // Modified bubble sort, ascending order:
    //  1. set starting index = 0 => outer loop
    //  2. set ending index to (size of array - 1) => outer loop
    //      3. loop over the array from starting index to ending index
    //      4. at each iteration, compare the element at current index and index + 1
    //      5. if elem[i] > elem[i + 1], swap
    //      6. if pass all the way through and no swap, break
    //  7. decrement ending index => outer loop
    //
    //  first pass, i goes from 0 to n - 1
    //  second pass, i goes from 0 to n - 2
    //  third pass, i goes from 2 to n - 3
    //  etc...
    //
    bool swapped = false;
    cout << "array size n = " << n << endl;
    for (int index = 0; index < n; ++index) {
        swapped = false;
        //for (int elem = 0; elem < (n - 1 - index); ++elem) {
        for (int elem = 0; elem < (n - 1); ++elem) {
            if (arrAscend[elem] > arrAscend[elem + 1]) {
                cout << "swapping, index = " << index << endl;
                int temp = arrAscend[elem];
                arrAscend[elem] = arrAscend[elem + 1];
                arrAscend[elem + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            cout << "no swap, index = " << index << endl;
            break;
        }
    }
    cout << "sorted ascending modified bubble:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrAscend[i] << endl;
    }

    cout << "unsorted descending modified bubble:" << endl;
    n = (int)(sizeof(arrDescend)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrDescend[i] << endl;
    }

    //
    // Modified bubble sort, descending order:
    //  1. set starting index = last element - 1
    //  2. set ending index = first element
    //  3. loop over the array from starting index to ending index - 1
    //  4. at each iteration, compare the element at current index and index - 1
    //  5. if elem[i] > elem[i - 1], swap
    //  6. if pass all the way through and no swap, break
    //  7. increment ending index
    //
    //  first pass, i goes from n - 1 to 0
    //  second pass, i goes from n - 1 to 1
    //  third pass, i goes from n - 1 to 2
    //  etc...
    //
    swapped = false;
    cout << "array size n = " << n << endl;
    for (int index = 0; index < n; ++index) {
        swapped = false;
        //for (int elem = n - 1; elem > index; --elem) {
        for (int elem = n - 1; elem > 0; --elem) {
            if (arrDescend[elem] > arrDescend[elem - 1]) {
                cout << "swapping, index = " << index << endl;
                int temp = arrDescend[elem];
                arrDescend[elem] = arrDescend[elem - 1];
                arrDescend[elem - 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            cout << "no swap, index = " << index << endl;
            break;
        }
    }
    cout << "sorted descending modified bubble:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrDescend[i] << endl;
    }

    // Selection sort
    //
    //  1. loop through the array a number of times equal to the size of the array
    //  2. initialise the current index of the lowest (ascending) or highest (descending) value to 0
    //  3. for each iteration of each loop, compare the value at index to value at index of lowest value
    //     and swap if lower
    //  4. at the end of each loop, place the value at min index at the index of loop start, swap values
    //  5. reduce starting index of next loop by 1
    cout << "unsorted ascending selection sort:" << endl;
    n = (int)(sizeof(arrSelect)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrSelect[i] << endl;
    }
    // 1. loop through the array...
    // 5. reduce starting...
    for (int start = 0; start < n; ++start) {
        // 2. initialize the current index...
        int indexOfMin = start;
        // 3. for each iteration of each loop...
        for (int index = start; index < n; ++index) {
            // compare ...
            if(arrSelect[indexOfMin] > arrSelect[index]) {
                indexOfMin = index;
            }
        }
        // 4. at the end of each...
        int temp = arrSelect[indexOfMin];
        arrSelect[indexOfMin] = arrSelect[start];
        arrSelect[start] = temp;
    }
    cout << "sorted ascending selection sort:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrSelect[i] << endl;
    }

    // Insertion sort - insert each element into the proper position
    //
    //  assume first element index is equal to 0
    //
    //  algorithm works by marching each value up the array, starting with
    //  the second element in the array, stopping when the correct location
    //  for the value is found.  As the value is moved up the array, the index
    //  of the value is swapped with the value it is being compared to.
    //
    //  set current element index equal to 1
    //  set next element index equal to 2
    //  while next index less than or equal to last index
    //      while current index is greater than 0
    //          compare value at current index to value preceding it
    //          if value at current is greater than preceding value
    //              do nothing and break
    //          else
    //              swap value at current index with value preceding it
    //              decrement current index
    //      set current index equal to next index
    //      increment next index
    //
    //
    cout << "unsorted ascending insertion sort:" << endl;
    n = (int)(sizeof(arrInsert)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrInsert[i] << endl;
    }

    int firstIdx = 0;
    int currIdx = 1;
    int nextIdx = 2;
    int lastIdx = n - 1;
    //
    // while we are not to the end...
    //
    while (nextIdx <= lastIdx + 1) {
        //
        // while we are not at the top with the current value...
        //
        while (currIdx > firstIdx) {
            //
            // location found, break out and get next value...
            //
            if (arrInsert[currIdx] > arrInsert[currIdx - 1]) {
                break;
            }
            //
            // not found yet, swap and keep comparing...
            //
            else {
                int temp = arrInsert[currIdx];
                arrInsert[currIdx] = arrInsert[currIdx - 1];
                arrInsert[currIdx - 1] = temp;
                --currIdx;
            }
        }
        //
        // get the next value to insert
        //
        currIdx = nextIdx;
        ++nextIdx;
    }

    cout << "sorted ascending insertion sort:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrInsert[i] << endl;
    }

    // Quick sort - recursive divide and conquer
    //
    // select a pivot value
    //  base case: lower array size is equal to 1
    //      return
    //  recursive case:
    //      partition array into two subarrays
    //      - one subarray has values less than pivot
    //          - call quick sort with this array
    //      - one subarray has values greater than the pivot
    //          - call quick sort with this array
    //
    cout << "unsorted ascending quick sort:" << endl;
    n = (int)(sizeof(arrQuick)/sizeof(int));
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrQuick[i] << endl;
    }

    quickSort(arrQuick, 0, n - 1);

    cout << "sorted ascending quick sort:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i << " = " << arrQuick[i] << endl;
    }

    return 0;
}

