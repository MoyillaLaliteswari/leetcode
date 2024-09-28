class MyCircularDeque {
private:
    vector<int> deque;  // Vector to store deque elements
    int front;          // Index of the front element
    int rear;           // Index of the rear element
    int size;           // Current number of elements in the deque
    int capacity;       // Maximum number of elements that the deque can hold

public:
    // Constructor to initialize the deque with a maximum size of k
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;  // Start the front at 0
        rear = 0;   // Start the rear at 0
        size = 0;
    }

    // Insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false;  // Check if deque is full
        front = (front - 1 + capacity) % capacity;  // Safely update front position
        deque[front] = value;
        size++;
        return true;
    }

    // Insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false;  // Check if deque is full
        deque[rear] = value;  // Insert at current rear
        rear = (rear + 1) % capacity;  // Safely update rear position circularly
        size++;
        return true;
    }

    // Delete an element from the front of the deque
    bool deleteFront() {
        if (isEmpty()) return false;  // Check if deque is empty
        front = (front + 1) % capacity;  // Safely move front circularly
        size--;
        return true;
    }

    // Delete an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) return false;  // Check if deque is empty
        rear = (rear - 1 + capacity) % capacity;  // Safely move rear circularly
        size--;
        return true;
    }

    // Get the front element from the deque
    int getFront() {
        if (isEmpty()) return -1;  // Return -1 if deque is empty
        return deque[front];
    }

    // Get the rear element from the deque
    int getRear() {
        if (isEmpty()) return -1;  // Return -1 if deque is empty
        return deque[(rear - 1 + capacity) % capacity];  // Return the last element
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }
};
