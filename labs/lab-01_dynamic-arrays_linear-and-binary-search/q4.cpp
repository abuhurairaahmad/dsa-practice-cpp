/*
Given an array of integers nums which is sorted in ascending order, and an integer
target, write a function to search target in nums. If target exists, then return its
index. Otherwise, return -1. You must write an algorithm with O(log n) runtime
complexity.
Example 1: Input: nums = [-1,0,3,5,9,12], target = 9, Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2: Input: nums = [-1,0,3,5,9,12], target = 2, Output: -1
Explanation: 2 does not exist in nums so return -1
Constraints:
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique
*/

#include <iostream>
using namespace std;

int search(const int arr[], int size, int target) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main(){
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, size, target);
    cout << "Index of " << target << " in nums is: " << result << endl;
    return 0;
}
