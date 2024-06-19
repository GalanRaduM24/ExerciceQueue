#include <iostream>
#include <fstream>
#include "Queue.h" // Custom queue implementation is assumed to be in this file

using namespace std;

// Input file
ifstream fin("test.txt");

// Queues to store order durations and arrival times
Queue<int> orderQueue{}, timeQueue{};

// Function to process orders
void solution(int T, int N) {
    int numServ = 0; // Number of served orders
    int nextOrderTime = 0; // Time of the next order
    int orderTime = 0; // Current time after processing an order
    
    // Process orders while there are orders and the restaurant is open
    while (N != 0 && T > orderTime) {
        nextOrderTime = timeQueue.dequeue(); // Get next order time

        // If there's a gap between the current time and the next order time
        if (nextOrderTime > orderTime) {
            cout << "Break between" << " " << orderTime << " si " << nextOrderTime << endl;
            orderTime = nextOrderTime; // Move time forward to the next order
        }

        // Process the current order
        cout << "Finish time: " << orderQueue.peek() << " ";
        orderTime = orderTime + orderQueue.dequeue(); // Add duration to current time
        cout << "Real time: " << orderTime << endl;
        numServ++; // Increment served orders count
        N--; // Decrement remaining orders count
    }

    int pierdute = 0; // Number of lost orders

    // Count orders that cannot be processed because the restaurant is closed
    while (N != 0 && orderTime >= T && T > timeQueue.peek()) {
        pierdute++;
        N--;
    }

    // Output results
    if (orderTime > T)
        cout << "There are orders after the end time" << endl;

    cout << "Orders ready:" << " " << numServ << endl;
    cout << "Orders not prepared: " << pierdute << endl;
    if (orderTime <= T)
        cout << "Close time:" << " " << T << endl;
    else
        cout << "Close time:" << " " << orderTime << endl;
}


int main() {
    int T, N;

    /*Keyboard input
    cout << "Enter closing time of the restaurant: ";
    cin >> T;
    cout << "Enter number of orders: ";
    cin >> N;
    int cn = N;

    for (int i = 0; i < cn; i++) {
        int t, d;
        cout << "Enter time of arrival for order #" << i + 1 << ": ";
        cin >> t;
        cout << "Enter duration for order #" << i + 1 << ": ";
        cin >> d;

        if (t <= T) {
            timeQueue.enqueue(t);
            orderQueue.enqueue(d);
        }
        else
            N--;
    }
    */

    // Read closing time and number of orders from file
    fin >> T;
    fin >> N;
    int cn = N;

    // Read each order's arrival time and duration, enqueue if it can be processed before closing time
    for (int i = 0; i < cn; i++) {
        int t, d;
        fin >> t;
        fin >> d;

        if (t <= T) {
            timeQueue.enqueue(t);
            orderQueue.enqueue(d);
        } else {
            N--; // Decrement number of orders if the order cannot be processed before closing time
        }
    }

    // Process orders
    solution(T, N);

    return 0;
}
