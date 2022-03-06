#include <iostream>
#include <vector>
static const int ELEMENT_NOT_FOUNDED = -1;
static const int ELEMENT_KEY_NOT_MATCH = -1;

using namespace std;

// 1 MB
int LinearSearch(const int array[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return ELEMENT_NOT_FOUNDED;
}
// STL CONTAINER VECTOR
int LinearSearchUsingVector(const vector<int>& data, int key) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == key) {
      return i;
    }
  }
  return ELEMENT_NOT_FOUNDED;
}




int* LinearSearchMultipleResults(const int array[], int n, int key) {

  int *temp; // Matched elements indexes
  temp = new int[n];
  for (int i = 0; i < n; i++) {
    if (array[i] == key) {
      temp[i] = i;
    }else{
      temp[i] = ELEMENT_KEY_NOT_MATCH;
    }
  }
  return temp;
}


// TODO VECTOR DISPLAY TO CONSOLE
/*void SingleMatchUsingVector(const int *dataset, int size, int key) {
  int result = LinearSearch(dataset, size, key);

  if (result != ELEMENT_NOT_FOUNDED) {
    cout << "Element founded at pos: " << result << ", value= " << dataset[result] << endl;
  } else {
    cout << "Element not FOUND SINGLE MATCH";
  }
}*/


void SingleMatchTesting(const int *dataset, int size, int key) {
  int result = LinearSearch(dataset, size, key);

  if (result != ELEMENT_NOT_FOUNDED) {
    cout << "Element founded at pos: " << result << ", value= " << dataset[result] << endl;
  } else {
    cout << "Element not FOUND SINGLE MATCH";
  }
}

void MultipleMatchesTesting(const int *dataset, int size, int key) {
  int *multipleResults = LinearSearchMultipleResults(dataset, size, key);

  int count = 0;

  cout << "======================================================================\n";
  for (int i = 0; i < size; i++) {
    if (multipleResults[i] != ELEMENT_NOT_FOUNDED) {
      cout << "Element founded at pos: " << i << ", value= " << dataset[i] << endl;
    } else {
      count++;
    }
  }
  if(count == size){
    cout << "Search results: 404 NOT FOUND ANY RESUTLS" << endl;
  }

  cout << "======================================================================\n";
}



int main() {
  int dataset[] = {22, 22, 22, 22, 22, 1251, 5152, 22, 44, 99, 77, 22};
  int size = sizeof(dataset) / sizeof(dataset[0]);

  SingleMatchTesting(dataset, size, 22);

  MultipleMatchesTesting(dataset, size, 22);


  return 0;
}
