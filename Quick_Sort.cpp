#include <iostream>
#include <vector>

// Function to partition the array into two segments and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high]; // Choose the rightmost element as the pivot
  int i = low - 1; // Index of the smaller element
  
  for (int j = low; j <= high - 1; j++) {
    // If the current element is smaller than or equal to the pivot
    if (arr[j] <= pivot) {
      i++; // Increment index of the smaller element
      std::swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
    }
  }
  
  std::swap(arr[i + 1], arr[high]); // Swap arr[i + 1] and arr[high] (pivot)
  return (i + 1); // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    // Find pivot element such that
    // element smaller than pivot are on the left
    // element greater than pivot are on the right
    int pivotIndex = partition(arr, low, high);
    
    // Recursively sort elements before and after pivot
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  
  std::cout << "Original array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  
  int n = arr.size();
  quickSort(arr, 0, n - 1);
  
  std::cout << "\nSorted array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  
  return 0;
}
