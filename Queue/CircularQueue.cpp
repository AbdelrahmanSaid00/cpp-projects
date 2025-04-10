#include<bits/stdc++.h>
using namespace std;
const int cap = 100;
class CircularQueue {
private:
    int* arr;
    int front,rear,counter,capacity;
public:
    CircularQueue(int size) {
        MakeSize(size);
    }
    void MakeSize(int size) {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
        counter=0;
    }
    bool isempty() {
        return (front == -1 && rear == -1);
    }
    bool isfull() {
        return (((rear+1)%capacity) ==(front));
    }
    void Enqueue (int data) {
        if (isempty()) {
            front=rear=0;
        }else if (isfull()) {
            cout << "The queue is full" << endl;
            return;
        }else {
            rear = (rear + 1)%capacity;
        }
        arr[rear] = data;
        counter++;
    }
    int Dequeue() {
        int x=-1;
        if (isempty()) {
            cout << "The queue is empty" << endl;
            return -1;
        }else if (rear == front) {
            x = arr[front];
            rear = front = -1;
        }else {
            x = arr[front];
            front = (front + 1)%capacity;
        }
        counter--;
        return x;
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
    CircularQueue que(cap);
    que.Enqueue(5);
    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    que.Enqueue(77);
    cout << que.frontValue() <<endl;
    while (!(que.isempty())) {
        cout << que.frontValue() << ' ';
        que.Dequeue();
    }
    cout <<endl;
    cout << que.Dequeue() << endl;
    return 0;
}