#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

ifstream fin("ex_2.txt");

Queue<int> orderQueue{}, timeQueue{};

void rezolvare(int T, int N) {
    int numServ = 0;
    int nextOrderTime = 0;
    int orderTime = 0;
    while (N != 0 && T > orderTime)
    {
        nextOrderTime = timeQueue.dequeue();
        cout << "NT: " << nextOrderTime << endl;

        if (nextOrderTime > orderTime)
        {
            cout << "Pauza intre" << " " << orderTime << " si " << nextOrderTime << endl;
            orderTime = nextOrderTime;
        }

        cout << "Timp de completare: " << orderQueue.peek() << " ";
        orderTime = orderTime + orderQueue.dequeue();
        cout << "Timp real: " << orderTime << endl;
        numServ++;
        N--;
    }

    int pierdute = 0;
    while (N != 0 && orderTime >= T && T > timeQueue.peek())
    {
        pierdute++;
        N--;
    }

    if (orderTime > T)
        cout << "There are orders after the end time" << endl;

    cout << "Serviri:" << " " << numServ << endl;
    cout << "Comenzi neefectuate: " << pierdute << endl;
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

    fin >> T;
    fin >> N;
    int cn = N;

    for (int i = 0; i < cn; i++) {
        int t, d;
        fin >> t;
        fin >> d;

        if (t <= T) {
            timeQueue.enqueue(t);
            orderQueue.enqueue(d);
        }
        else
            N--;
    }

    rezolvare(T, N);

    return 0;
}
