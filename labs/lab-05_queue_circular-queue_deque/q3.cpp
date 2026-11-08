#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Call {
public:
    int callID;
    string arrivalTime;
    string customerName;

    Call(int id, const string& time, const string& name) : callID(id), arrivalTime(time), customerName(name) {}
};

class CallCenter {
private:
    queue<Call> callQueue;
    int callCSR; // Call Center Service Representative
    vector<bool> csrAvailability; // ture = available, false = busy

public:
    CallCenter(int numCSR) : callCSR(numCSR), csrAvailability(numCSR, true) {}

    void addCall(const Call& newCall) {
        callQueue.push(newCall);
        cout << "[Arrival] Call #" << newCall.callID 
                  << " from " << newCall.customerName 
                  << " at " << newCall.arrivalTime 
                  << " added to queue. (Queue size: " << callQueue.size() << ")\n";
    }

    void processCalls() {
        cout << "\n--- Processing Call Queue ---\n";

        for (int i = 0; i < callCSR && !callQueue.empty(); ++i) {
            if (csrAvailability[i]) {
                Call currentCall = callQueue.front();
                callQueue.pop();

                csrAvailability[i] = false;

                cout << "[Handling] CSR #" << (i + 1)
                     << " is now answering Call #" << currentCall.callID
                     << " (" << currentCall.customerName << ")...\n";

                cout << "[Completed] Call #" << currentCall.callID
                     << " resolved successfully.\n";

                csrAvailability[i] = true;
                cout << "[Status] CSR #" << (i + 1) << " is now free.\n\n";
            }
        }

        if (callQueue.empty()) {
            std::cout << "All calls have been processed. Queue is empty.\n";
        } else {
            std::cout << "Remaining calls in queue: " << callQueue.size() << "\n";
        }
    }
  
};

int main() {
    const int TOTAL_CSRS = 2;
    CallCenter center(TOTAL_CSRS);

    // Simulate incoming calls arriving at different times
    center.addCall(Call(101, "09:00 AM", "Ahmed"));
    center.addCall(Call(102, "09:02 AM", "Bilal"));
    center.addCall(Call(103, "09:05 AM", "Chaudhry"));
    center.addCall(Call(104, "09:07 AM", "Danish"));

    // Process calls on a First-Come, First-Served basis
    center.processCalls();
    
    return 0;
}