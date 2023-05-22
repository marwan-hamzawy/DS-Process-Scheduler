#include<iostream>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node(T data, int priority) : data(data), priority(priority), next(nullptr) {}
    };
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}
    bool empty() const {
        return head == nullptr;
    }
    void enqueue(T data, int priority) {
        Node* new_node = new Node(data, priority);
        if (empty()) {
            head = new_node;
        }
        else {
            if (priority < head->priority) {
                new_node->next = head;
                head = new_node;
            }
            else {
                Node* curr = head;
                Node* prev = nullptr;
                while (curr != nullptr && priority >= curr->priority) {
                    prev = curr;
                    curr = curr->next;
                }
                new_node->next = curr;
                prev->next = new_node;
            }
        }
    }
    T dequeue() {
        if (empty()) {
           
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
    void removeProccess(T data) {
        if (empty()) {
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            return;
        }
        if (curr == head) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }

    T peek() {
        if (empty()) {
            return T();
        }
        return head->data;
    }
    T getFront() {
        if (empty()) {
            return T();
        }
        return head->data;
    }
    T getNext() {
        if (empty()) {
            return T();
        }
        return head->next->data;
    }
    T print() const {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout <<endl;
        return (curr == nullptr) ? T() : curr->data;
    }
    void Display()
    {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


