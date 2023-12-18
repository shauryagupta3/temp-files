#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueFront(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Enqueued at front: " << item << endl;
    }

    void enqueueRear(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Enqueued at rear: " << item << endl;
    }

    int dequeueFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot dequeue from front." << endl;
            return -1;
        } else {
            int item = front->data;
            Node* temp = front;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                front = front->next;
                front->prev = nullptr;
            }
            delete temp;
            cout << "Dequeued from front: " << item << endl;
            return item;
        }
    }

    int dequeueRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot dequeue from rear." << endl;
            return -1;
        } else {
            int item = rear->data;
            Node* temp = rear;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                rear = rear->prev;
                rear->next = nullptr;
            }
            delete temp;
            cout << "Dequeued from rear: " << item << endl;
            return item;
        }
    }
};

int main() {
    Deque deque;

    deque.enqueueFront(1);
    deque.enqueueRear(2);
    deque.enqueueFront(3);
    deque.enqueueRear(4);

    deque.dequeueFront();
    deque.dequeueRear();

    return 0;
}
