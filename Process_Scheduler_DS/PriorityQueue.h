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
            throw std::runtime_error("Priority queue is empty");
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
};

