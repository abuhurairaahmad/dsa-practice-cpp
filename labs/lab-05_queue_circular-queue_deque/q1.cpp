#include <iostream>
#include <string>
using namespace std;

class MyCircularDeque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main(){
    std::cout << std::boolalpha;

    // i am copying this exact from the lab manual
    MyCircularDeque* myCircularDeque = new MyCircularDeque(3);

    cout << "insertLast(1): " << myCircularDeque->insertLast(1) << " (Expected: true)\n";
    cout << "insertLast(2): " << myCircularDeque->insertLast(2) << " (Expected: true)\n";
    cout << "insertFront(3): " << myCircularDeque->insertFront(3) << " (Expected: true)\n";
    cout << "insertFront(4): " << myCircularDeque->insertFront(4) << " (Expected: false - Full)\n";
    cout << "getRear(): " << myCircularDeque->getRear() << " (Expected: 2)\n";
    cout << "isFull(): " << myCircularDeque->isFull() << " (Expected: true)\n";
    cout << "deleteLast(): " << myCircularDeque->deleteLast() << " (Expected: true)\n";
    cout << "insertFront(4): " << myCircularDeque->insertFront(4) << " (Expected: true)\n";
    cout << "getFront(): " << myCircularDeque->getFront() << " (Expected: 4)\n";
    
    return 0;
}
