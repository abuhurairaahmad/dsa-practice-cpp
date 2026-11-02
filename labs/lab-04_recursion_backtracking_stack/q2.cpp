/*
Given two strings s and t, return true if they are equal when both are typed into empty text
editors. '#' means a backspace character. Note that after backspacing an empty text, the text will
continue empty.
Example 1: Input: s = "ab#c", t = "ad#c", Output: true, Explanation: Both s and t become "ac".
Example 2: Input: s = "a#c", t = "b", Output: false, Explanation: s becomes "c" while t becomes
"b"
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string buildCleanString(const string& input) {
    stack<char> st;

    for (char ch : input) {
        if (ch != '#') {
            st.push(ch);
        } else if (!st.empty()) {   
            // !st.empty() statement is necessary or else 
            // poping an empty stack gives a compilation error. 
            st.pop();
        }
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

bool backspaceCompare(const string& s, const string& t) {
    return buildCleanString(s) == buildCleanString(t);
}

int main(){
    // Example 1
    string s1 = "ab#c";
    string t1 = "ad#c";
    bool res1 = backspaceCompare(s1, t1);
    cout << std::boolalpha;
    cout << "Example 1 (s = \"" << s1 << "\", t = \"" << t1 << "\"): " 
              << res1 << " (Expected: true)\n";

    // Example 2
    string s2 = "a#c";
    string t2 = "b";
    bool res2 = backspaceCompare(s2, t2);
    std::cout << "Example 2 (s = \"" << s2 << "\", t = \"" << t2 << "\"): " 
              << res2 << " (Expected: false)\n";

    // Example 3: Multiple backspaces on empty editor
    string s3 = "a##c";
    string t3 = "#c";
    bool res3 = backspaceCompare(s3, t3);
    cout << "Example 3 (s = \"" << s3 << "\", t = \"" << t3 << "\"): " 
              << res3 << " (Expected: true)\n";
    
    return 0;
}
