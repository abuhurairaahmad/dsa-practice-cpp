#include <iostream>
#include <stack>

int main() {
	std::stack<char> characters;

	// Add four characters to the stack, one at a time.
	characters.push('A');
	characters.push('B');
	characters.push('C');
	characters.push('D');

	while (!characters.empty()) {
		std::cout << "Popping: " << characters.top() << '\n';
		characters.pop();
	}

	// A stack has no peek() method; top() is its peek operation.
	// Calling top() on an empty stack is undefined behavior, so check first.
	std::cout << "Stack is empty. Trying to peek again...\n";
	if (characters.empty()) {
		std::cout << "Cannot peek: the stack is empty.\n";
	} else {
		std::cout << "Top: " << characters.top() << '\n';
	}

    // cout << characters.pop() << endl; // This line will cause a compilation error because pop() returns void.

	return 0;
}
