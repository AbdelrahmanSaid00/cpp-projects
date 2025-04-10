#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *next;
};
class LinkedCircularQueue{
private:
    node* front;
    node* rear;
    int counter;
public:
    LinkedCircularQueue() {
        makeNull();
    }
    void makeNull() {
        front = rear = nullptr;
        counter=0;
    }
    bool empty() {
        return counter == 0;
    }
    void Enqueue (int x) {
        node *newnode = new node;
        newnode->val = x;
        newnode->next = nullptr;
        if (!counter) {
            rear = newnode;
            front = newnode;
        }else {
            rear->next = newnode;
            rear = newnode;
        }
        counter++;
    }
    int Dequeue() {
        if (empty()) {
            return -1;
        }else {
            int ret = front->val;
            node *temp = front;
            front = front->next;
            delete temp;
            counter--;
            return ret;
        }
    }
    int first () {
        if (empty()) {
            return -1;
        }else {
            return front->val;;
        }
    }
    void print () {
        cout << "Queue is ==>";
        node *q = front;
        while (q != nullptr) {
            cout << q->val << ' ';
            q = q->next;
        }
        cout << endl;
    }
    int culsum () {
        int sum =0;
        node *q = front;
        while (q != nullptr) {
            sum+=q->val;
            q = q->next;
        }
        return sum;
    }
    int max_ele() {
        int max_e=0;
        node *q = front;
        while (q != nullptr) {
            max_e = max (max_e , q->val); 
            q = q->next;
        }
        return max_e;
    }
    LinkedCircularQueue filterEven() {
        LinkedCircularQueue evenQueue;
        node* current = front;
        while (current != nullptr) {
            if (!(current->val & 1)) {
                evenQueue.Enqueue(current->val);
            }
            current = current->next;
        }
        return evenQueue;
    }
};

class LinkedStack {
private:
    int counter;
    node* top;
public:
    LinkedStack() {
        MakeNull();
    }
    void MakeNull() {
        top = nullptr;
        counter=-1;
    }
    int peek () {
        if(emptty())throw runtime_error("Stack is empty"); 
        return top->val;
    }
    void push(int data) {
        node* newElement = new node;
        newElement->val = data;
        newElement->next = top;
        top = newElement;
        counter++;
    }
    void pop () {
        if (emptty()) throw runtime_error("Stack underflow");
            char ele = top->val;
            node*temp = top;
            top = top->next;
            delete temp;
            counter--;
    }
    bool emptty() {
        return top == nullptr;
    }
    void printStack () {
        node* p =top;
        while(p) {
            cout << p->val << ' ';
            p = p->next;
        }
    }
};

bool isPalindrome (string s) {
    LinkedCircularQueue que;
    LinkedStack sta;
    for (int i=0 ;i < s.size() ;i++) {
        if (isalnum(s[i])) {
            char c = tolower(s[i]);
            que.Enqueue(c);
            sta.push(c);
        }
    }
    while (!sta.emptty() && !que.empty()) {
        if (que.first() != sta.peek()) {
            return false;
        }
        que.Dequeue();
        sta.pop();
    }
    if (que.empty() && sta.emptty()) {
        return true;
    }
    return false;
}

int main () {

    LinkedCircularQueue que;
    que.Enqueue(5);
    que.Enqueue(1);
    que.Enqueue(8);
    cout << que.culsum() << endl;
    cout << que.max_ele() << endl;
    cout << que.Dequeue() << endl;
    cout << que.first() << endl;
    que.print();
    LinkedCircularQueue reev = que.filterEven();
    reev.print();
    string s = "123521";
    string ss = "123321";
    cout << isPalindrome(s) << endl;
    cout << isPalindrome(ss) << endl;
    return 0;
}