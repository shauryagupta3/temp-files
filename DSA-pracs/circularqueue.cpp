#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int *queue;
    int front, rear;

public:
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue item." << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            queue[rear] = item;
            cout << "Enqueued: " << item << endl;
        }
    }

    int dequeue() {
        int item = -1;
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue item." << endl;
        } else {
            item = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            cout << "Dequeued: " << item << endl;
        }
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue: ";
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.display();

    queue.enqueue(6);
    queue.display();

    return 0;
}
