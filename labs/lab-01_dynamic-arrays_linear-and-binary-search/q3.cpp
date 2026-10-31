/*
The median is the middle value in an ordered integer list. If the size of the list is even, there
is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
- MedianFinder() initializes the MedianFinder object.
- void addNum(int num) adds the integer num from the data stream to the data
structure.
- double findMedian() returns the median of all elements so far. Answers within 10-5 of
the actual answer will be accepted.
Example 1:
Input: ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output: [null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1); // arr = [1]
medianFinder.addNum(2); // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3); // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
Constraints: -105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
private:
    vector<int> nums;

    // Binary search helper function
    int findInsertionIndex(int num) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left; // Return the index where num should be inserted
    }

public:
    MedianFinder() {
        // Constructor to initialize the MedianFinder object
    }

    void addNum(int num) {
        if (nums.empty()) {
            nums.push_back(num); 
            return;
        } 

        int index = findInsertionIndex(num);
        nums.insert(nums.begin() + index, num); 
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2 == 1) {
            return nums[n / 2]; 
        }

        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

int main(){
    MedianFinder medianFinder;

    medianFinder.addNum(1); // arr = [1]
    medianFinder.addNum(2); // arr = [1, 2]
    medianFinder.addNum(3); // arr = [1, 2, 3]
    medianFinder.addNum(8); // arr = [1, 2, 3, 8]
    medianFinder.addNum(4); // arr = [1, 2, 3, 4, 8]
    cout << medianFinder.findMedian() << endl; // Output: 3.0
    
    return 0;
}
