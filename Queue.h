#include <stdio.h>
#include <iostream>
#define NMAX 100

using namespace std;

template <typename T>
class Queue {
private:
    T queueArray[NMAX];
    int head = 0, tail = 0, size = 0;

public:
    void enqueue(T x) {
        if (size == NMAX) {
            cout << "Error 101 - The queue is full!\n";
            return;
        }
        queueArray[tail] = x;
        tail = (tail + 1) % NMAX;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Error 102 - The queue is empty!\n";
            T x = T();
            return x;
        }
        T x = queueArray[head];
        head = (head + 1) % NMAX;
        size--;
        return x;
    }

    T peek() {
        if (isEmpty()) {
            cout << stderr, "Error 103 - The queue is empty!\n";
            T x = T();
            return x;
        }
        return queueArray[head];
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() {
        return(size == 0);
    }
};