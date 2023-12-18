#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }

    ~CircularQueue() {
        if (rear != nullptr) {
            Node* temp = rear->next;
            while (temp != rear) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            delete rear;
        }
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear; // Point back to itself for circularity
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << item << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue item." << endl;
            return -1;
        } else {
            int item;
            if (rear->next == rear) {
                item = rear->data;
                delete rear;
                rear = nullptr;
            } else {
                Node* frontNode = rear->next;
                item = frontNode->data;
                rear->next = frontNode->next;
                delete frontNode;
            }
            cout << "Dequeued: " << item << endl;
            return item;
        }
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.dequeue();
    queue.dequeue();

    queue.enqueue(6);

    return 0;
}
