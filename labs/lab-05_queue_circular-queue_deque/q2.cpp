#include <iostream>
#include <queue>
using namespace std;

int findTheWinner(int n, int k) {
    queue<int> circle;

    for (int i = 0; i < n; ++i) {
        circle.push(i + 1);
    }

    while (circle.size() > 1) {
        for (int i = 0; i < k - 1; ++i) {
            circle.push(circle.front());
            circle.pop();
        }
        circle.pop();
    }

    return circle.front();
};

int main(){
    // Example 1: n = 5, k = 2
    int n1 = 5, k1 = 2;
    int winner1 = findTheWinner(n1, k1);
    cout << "Input: n = " << n1 << ", k = " << k1 << "\n";
    cout << "Output: " << winner1 << " (Expected: 3)\n\n";

    // Example 2: n = 6, k = 5
    int n2 = 6, k2 = 5;
    int winner2 = findTheWinner(n2, k2);
    cout << "Input: n = " << n2 << ", k = " << k2 << "\n";
    cout << "Output: " << winner2 << " (Expected: 1)\n";
    
    return 0;
}
