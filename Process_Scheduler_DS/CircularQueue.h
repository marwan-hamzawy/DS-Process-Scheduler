#include<iostream>
using namespace std;

template<typename T, int N>
class CircularQueue {
private:
    T arr[N];
    int front;
    int rear;
    int count;
public:
    CircularQueue() : front(0), rear(0), count(0) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == N;
    }

    int size() const {
        return count;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            return;
        }
        arr[rear] = item;
        rear = (rear + 1) % N;
        ++count;
    }
    void Display() {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T dequeue() {
        if (isEmpty()) {
            return T();
        }
        T item = arr[front];
        front = (front + 1) % N;
        --count;
        return item;
    }


    const T& frontValue() const {
        return arr[front];
    }

    T print() const {
        if (isEmpty()) {
            //std::cout << "Circular Queue is empty.\n";
            return 0;
        }
        //std::cout << "Circular Queue:\n";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % N;
        } while (i != rear);
        return arr[i];
        //std::cout << "\n";
    }
};
