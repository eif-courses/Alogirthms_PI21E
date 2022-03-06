#include <iostream>
#include <vector>
#include <algorithm>

static const int ELEMENT_NOT_FOUNDED = -1;
using namespace std;

void BubbleSort(vector<size_t> &array) {
  size_t temp;
  //int flag = 0;
  size_t length = array.size();
  for (size_t i = 0; i < length; i++) {
    for (size_t j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        //flag = 1;
      }
    }
    // Optimized version of BubbleSort
    // If flag zero after inner loop that means array is sorted
//    if(flag == 0){
//      break;
//    }
  }
}

size_t BinarySearch(vector<size_t> &numbers, size_t left, size_t right, int searchKey) {
  // 0 .. numbers.size()-1

  BubbleSort(numbers);
  //std::sort(numbers.begin(), numbers.end());

  while (left <= right) {
    size_t middle = left + (right - left) / 2;
    if (numbers[middle] == searchKey) {
      return middle;
    }
    if (numbers[middle] < searchKey) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return ELEMENT_NOT_FOUNDED;
}

int main() {
  vector<size_t> numbers = {82, 58, 45, 112, 554, 15, 1549, 66, 99, 5454};

  size_t binarySearchResult = BinarySearch(numbers, 0, numbers.size() - 1, 99);

  cout << "Original sequence: ";
  for (auto i: numbers) {
    cout << i << " ";
  }

  cout << "\nBinary search result: ";

  if (binarySearchResult != ELEMENT_NOT_FOUNDED)
    cout << "Founded at index =  " << binarySearchResult << ", number = " << numbers[binarySearchResult]
              << endl;
  else {
    cout << "No results founded!";
  }
  return 0;
}
