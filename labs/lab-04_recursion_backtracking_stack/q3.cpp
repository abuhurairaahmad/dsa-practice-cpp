#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int idx, vector<int>& nums, vector<vector<int>>& result) {
    if (idx == nums.size()) {
        result.push_back(nums);
        return;
    }
    
    for (int i = idx; i < nums.size(); ++i) {
        swap(nums[idx], nums[i]);
        backtrack(idx + 1, nums, result);
        swap(nums[idx], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(0, nums, result);
    return result;
}

void printPermutations(const std::vector<std::vector<int>>& perms) {
    cout << "[";
    for (size_t i = 0; i < perms.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < perms[i].size(); ++j) {
            cout << perms[i][j] << (j + 1 < perms[i].size() ? "," : "");
        }
        cout << "]" << (i + 1 < perms.size() ? ", " : "");
    }
    cout << "]\n";
}

int main(){
    // Example 1
    vector<int> nums1 = {1, 2, 3};
    vector<std::vector<int>> result1 = permute(nums1);
    cout << "Example 1 Input: [1, 2, 3]\nOutput: ";
    printPermutations(result1);

    // Example 2
    vector<int> nums2 = {0, 1};
    vector<std::vector<int>> result2 = permute(nums2);
    cout << "\nExample 2 Input: [0, 1]\nOutput: ";
    printPermutations(result2);
    
    return 0;
}
