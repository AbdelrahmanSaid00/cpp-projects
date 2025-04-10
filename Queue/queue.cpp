#include<bits/stdc++.h>
using namespace std;
const int cap = 100;
struct Queue {
    int arr [cap];
    int front = -1;
    int rear = -1;
    bool isempty() {
        return (front == -1 && rear == -1);
    }
    bool isfull() {
        return (rear ==(cap-1));
    }
    void inqueue (int data) {
        if (isempty()) {
            front=rear=0;
            arr[rear] = data;
        }else if (isfull()) {
            cout << "The queue is full" << endl;
        }else {
            arr[++rear] = data;
        }
    }
    void dequeue() {
        if (isempty()) {
            cout << "The queue is empty" << endl;
        }else if (rear == front) {
            rear = front = -1;
        }else {
            front++;
        }
    }
    int frontValue() {
        if (isempty()) {
            return -1;
        }else {
            return arr[front];
        }
    }
};

int main () {
    Queue que;
    que.inqueue(5);
    que.inqueue(1);
    que.inqueue(2);
    que.inqueue(3);
    que.inqueue(77);
    cout << que.frontValue() <<endl;
    while (!(que.isempty())) {
        cout << que.frontValue() << ' ';
        que.dequeue();
    }
    return 0;
}