#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int *arr;     // Pointer to the array that holds the stack elements
    int capacity; // Maximum size of the stack
    int topIndex; // Index of the top element in the stack
public:
    // Constructor to initialize the stack with a given capacity
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; // Indicates an empty stack
    }
    // Destructor to clean up the allocated memory
    ~Stack() {
        delete[] arr;
    }
    // Push an element onto the stack
    void push(int element) {
        if (topIndex == capacity - 1)
        {
            cout << "Stack overflow. Unable to push " << element << endl;
            return;
        }
        arr[++topIndex] = element;
    }
    // Pop an element from the stack
    int pop() {
        if (topIndex == -1)
        {
            cout << "Stack underflow. Unable to pop." << endl;
            return -1; // Returning -1 to indicate an error (assuming only positive numbers are used)
        }
        return arr[topIndex--];
    }
    // Peek at the top element of the stack
    int peek() const {
        if (topIndex == -1)
        {
            cout << "Stack is empty." << endl;
            return -1; // Returning -1 to indicate an error
        }
        return arr[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }
    // Get the current size of the stack
    int size() const {
        return topIndex + 1;
    }
};

bool isPalindrome(const string &str) {
    Stack s(str.length());

    for (char ch : str) {
        s.push(ch);
    }

    for (char ch : str) {
        if (s.pop() != ch) {
            return false;
        }
    }

    return true;
}

int main()
{
    string test1 = "racecar";
    string test2 = "hello";
    string test3 = "noon";
    string test4 = "madam";

    cout << boolalpha; // Print boolean values as true/false instead of 1/0
    cout << "\"" << test1 << "\" is palindrome: " << isPalindrome(test1) << " (Expected: true)\n";
    cout << "\"" << test2 << "\" is palindrome: " << isPalindrome(test2) << " (Expected: false)\n";
    cout << "\"" << test3 << "\" is palindrome: " << isPalindrome(test3) << " (Expected: true)\n";
    cout << "\"" << test4 << "\" is palindrome: " << isPalindrome(test4) << " (Expected: true)\n";

    return 0;
}
