/*
Design an algorithm that accepts a stream of integers and retrieves the product of the last k
integers of the stream. Implement the ProductOfNumbers class:
- ProductOfNumbers() Initializes the object with an empty stream.
- void add(int num) Appends the integer num to the stream.
- int getProduct(int k) Returns the product of the last k numbers in the current list. You can
assume that always the current list has at least k numbers.
- The test cases are generated so that, at any time, the product of any contiguous sequence
of numbers will fit into a single 32-bit integer without overflowing.
- Main Program
Int main(){
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3); // [3]
productOfNumbers.add(0); // [3,0]
productOfNumbers.add(2); // [3,0,2]
productOfNumbers.add(5); // [3,0,2,5]
productOfNumbers.add(4); // [3,0,2,5,4]
*/

#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProducts; // Store the prefix products of the stream

public:
    ProductOfNumbers() { prefixProducts = {1}; } // Initialize with 1 for multiplication

    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset on zero
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) return 0; // If k is larger than the number of elements, return 0
        return prefixProducts.back() / prefixProducts[n - k - 1]; // Calculate product of last k numbers
    }

};

int main(){
    ProductOfNumbers* productOfNumbers = new ProductOfNumbers();

    // Trace from the lab manual:
    productOfNumbers->add(3); // Stream: [3]
    productOfNumbers->add(0); // Stream: [3, 0] (Resets prefix list)
    productOfNumbers->add(2); // Stream: [3, 0, 2]
    productOfNumbers->add(5); // Stream: [3, 0, 2, 5]
    productOfNumbers->add(4); // Stream: [3, 0, 2, 5, 4]

    // getProduct(2) -> 5 * 4 = 20
    std::cout << "getProduct(2): " << productOfNumbers->getProduct(2) 
              << " (Expected: 20)\n";   

    // getProduct(3) -> 2 * 5 * 4 = 40
    std::cout << "getProduct(3): " << productOfNumbers->getProduct(3) 
              << " (Expected: 40)\n";

    // getProduct(4) -> 0 * 2 * 5 * 4 = 0
    std::cout << "getProduct(4): " << productOfNumbers->getProduct(4) 
              << " (Expected: 0)\n";

    productOfNumbers->add(8); // Stream: [3, 0, 2, 5, 4, 8]
    // getProduct(2) -> 4 * 8 = 32
    std::cout << "getProduct(2): " << productOfNumbers->getProduct(2) 
              << " (Expected: 32)\n";

    delete productOfNumbers; 

    return 0;
}
