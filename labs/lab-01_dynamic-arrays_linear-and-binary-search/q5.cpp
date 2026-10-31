#include <iostream>
#include <algorithm>
using namespace std;

bool searchMatrix(int matrix[3][4], int target)
{
    int rows = 3;
    int cols = 4;
    int left = 0, right = rows * cols - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return true; // Target found
        }
        else if (midValue < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return false; // Target not found
}

int main() {
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    bool found1 = searchMatrix(matrix, target1);
    cout << "Target: " << target1 << ", to find: " << found1 << ", status: " << (found1 ? " found." : " not found.") << endl;

    int target2 = 13;
    bool found2 = searchMatrix(matrix, target2);
    cout << "Target: " << target2 << ", to find: " << found2 << ", status: " << (found2 ? " found." : " not found.") << endl;

    return 0;
}
