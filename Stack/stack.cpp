#include<bits/stdc++.h>
using namespace std;
#define E <<endl;

class Stack {
private:
    int cap;
    int top;
    int *element;
public:
    Stack(int size = 10) {
        top = -1;
        element = new int[size];
        cap = size;
    }
    ~Stack () {
        delete []element;
    }
    bool empty () {
        return top==-1;
    }
    bool full () {
        return (top+1)== cap;
    }
    void push (int ele) {
        if(full()) {
            cout << "The Stack is full" <<endl;
        }
        else {
            element[++top] = ele;
        }
    }
    void pop () {
        if(empty()) {
            cout << "empty" << endl;
            return;
        }
        else {
            top--;
            cap--;
        }
    }
    int topp () {
        if(empty()) {
            cout << "The stack is empty" << endl;
            return -1;
        }
        else {
            return element[top];
        }
    }

};
bool balanced (string s) {
    Stack openbrac(100);
    for (int i=0 ; i < s.size() ;i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            openbrac.push(s[i]);
        }else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (openbrac.empty()) {
                return false;
            }else {
                if ((openbrac.topp() == '(' && s[i] == ')') ||(openbrac.topp() == '{' && s[i] == '}') || (openbrac.topp() == '[' && s[i] == ']') ) {
                    openbrac.pop();
                }else {
                    return false;
                }
            }
        }
    }
    if (!openbrac.empty()) {
        return false;
    }else {
        return true;
    }
}
int main () {
    Stack l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.push(5);
    l1.push(6);
    l1.push(7);
    while (!l1.empty()) {
        cout << l1.topp() << ' ';
        l1.pop();
    }
    l1.push(4);
    cout << endl;
    cout << l1.topp() << endl;
    string s;
    cin >> s;
    if (balanced(s)) {
        cout << "Is OK" << endl;
    }else {
        cout << "no it is no balanced" << endl;
    }
    return 0;
}