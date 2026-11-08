/*
For a stream of integers, implement a data structure that checks if the last k integers parsed in the
stream are equal to value. Implement the DataStream class:
- DataStream(int value, int k) Initializes the object with an empty integer stream and the two integers
value and k.
- boolean consec(int num) Adds num to the stream of integers. Returns true if the last k integers are
equal to value, and false otherwise. If there are less than k integers, the condition does not hold true,
so returns false.
- Main Program:
void main(){
DataStream dataStream = new DataStream(4, 3); //value = 4, k = 3
dataStream.consec(4); // Only 1 integer is parsed, so returns False.
dataStream.consec(4); // Only 2 integers are parsed.
 // Since 2 is less than k, returns False.
dataStream.consec(4); // The 3 integers parsed are all equal to value, so returns True.
dataStream.consec(3); // The last k integers parsed in the stream are [4,4,3].
 // Since 3 is not equal to value, it returns False.
}
*/

#include <iostream>
using namespace std;

class DataStream {
private:
    int targetValue;
    int requiredCount;
    int streak;

public:
    DataStream(int value, int k) : targetValue(value), requiredCount(k), streak(0) {}

    bool consec(int num) {
        if (num == targetValue) {
            streak++;
        } else {
            streak = 0;
        }
        return streak >= requiredCount;
    }
};

int main(){
    
    DataStream* dataStream = new DataStream(4, 3);
    std::cout << std::boolalpha;


    cout << "consec(4): " << dataStream->consec(4) << " (Expected: false)\n";
    cout << "consec(4): " << dataStream->consec(4) << " (Expected: false)\n";
    cout << "consec(4): " << dataStream->consec(4) << " (Expected: true)\n";
    cout << "consec(3): " << dataStream->consec(3) << " (Expected: false)\n";
    cout << "consec(4): " << dataStream->consec(4) << " (Expected: false)\n";
    cout << "consec(4): " << dataStream->consec(4) << " (Expected: false)\n";
    cout << "consec(4): " << dataStream->consec(4) << " (Expected: true)\n";

    delete dataStream;


    return 0;
}
