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
};
