#include <iostream>

// Node for Queue
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Queue structure
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue method
    void enqueue(int value) {
        // Create a new node
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        // Check if the queue is empty and add the new element if so
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        // Otherwise, add the new element to the rear of the queue
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Dequeue method
    int dequeue() {
        // Check if the queue is empty
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
        // Check if the queue has only one element and remove it if so
        } else if (front == rear) {
            int value = front->data;
            delete front;
            front = nullptr;
            rear = nullptr;
            return value;
        // Otherwise, remove the front element and return its value
        } else {
            int value = front->data;
            Node* temp = front;
            front = front->next;
            front->prev = nullptr;
            delete temp;
            return value;
        }
        return -1;
    }

    // isEmpty method
    bool isEmpty() {
        return front == nullptr;
    }

    // Peek method to return the value at the front of the queue without removing it
    int peek() {
        // Check if the queue is empty
        if (front == nullptr) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        // Otherwise, return the value at the front of the queue
        return front->data;
    }
};

int main() {
    // Test the Queue and LinkedList structures
    Queue queue;

    // Enqueue some values
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Dequeue and print the values
    std::cout << queue.dequeue() << std::endl; // Output: 10
    std::cout << queue.dequeue() << std::endl; // Output: 20

    // Peek and print the value at the front
    std::cout << queue.peek() << std::endl; // Output: 30

    return 0;
}
