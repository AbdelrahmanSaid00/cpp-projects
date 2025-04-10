#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct node {
    T data;
    node* next;
};
template<typename T>
class LinkedStack {
private:
    int counter;
    node<T>*top;
public:
    LinkedStack() {
        MakeNull();
    }
    void MakeNull() {
        top = nullptr;
        counter=-1;
    }
    T peek () {
        if(emptty())throw runtime_error("Stack is empty"); 
        return top->data;
    }
    void push(T data) {
        node<T>* newElement = new node<T>;
        newElement->data = data;
        newElement->next = top;
        top = newElement;
        counter++;
    }
    void pop () {
        if (emptty()) throw runtime_error("Stack underflow");
            char ele = top->data;
            node<T>*temp = top;
            top = top->next;
            delete temp;
            counter--;
    }
    bool emptty() {
        return top == nullptr;
    }
    void printStack () {
        node<T>* p =top;
        while(p) {
            cout << p->data << ' ';
            p = p->next;
        }
    }
};
bool valid (string s) {
    LinkedStack<char>st;
    for(char x : s) {
        if(x == '[' || x == '(' || x == '{') st.push(x);
        else {
            if(st.emptty()) return false;
            if((x==')' && st.peek()!='(') || (x==']' && st.peek()!='[') || (x=='}' && st.peek()!='{')){ return false;}
            st.pop();
        }
    }
    return st.emptty();
}
int priority (char ope) {
    if (ope == '+' || ope == '-') {
        return 1;
    }else if(ope == '*' || ope == '/') {
        return 2;
    }else if(ope == '^') {
        return 3;
    }else {
        return 0;
    }
}
string infix_to_postfix (string s) {
    LinkedStack<char>stc;
    string out = "";
    for(int i=0; i < s.size() ;++i) {
        if (s[i] == ' ') {
            continue;
        }else if (isdigit(s[i]) || isalpha(s[i])) {
            out+=s[i];
        }else if (s[i] == '(' || s[i] == '[') {
            stc.push(s[i]);
        }else if (s[i] == ')') {
            while (stc.peek()!='(') {
                out+=stc.peek();
                stc.pop();
            }
            if (!stc.emptty()) stc.pop();
        }else if (s[i] == ']') {
            while (stc.peek() !='[') {
                out+=stc.peek();
                stc.pop();
            }
            if (!stc.emptty()) stc.pop();
        }else {
            while (!stc.emptty() && (priority(s[i]) <= priority(stc.peek()))) {
                out+=stc.peek();
                stc.pop();
            }
            stc.push(s[i]);
        }
    }
    while (!stc.emptty()) {
        out+=stc.peek();
        stc.pop();
    }
    return out;
}
float operation (float a , float b , char opera) {
    if (opera == '+') {
        return a + b;
    }else if(opera == '-') {
        return a -b;
    }else if (opera == '*') {
        return a * b;
    }else if(opera == '/') {
        return a/b;
    }else {
        return 0;
    }
}
float postfix_evaluate (string s) {
    stack<float>sta;
    for (int i=0 ; i < s.size() ;i++) {
        if (isdigit(s[i])) {
            sta.push(s[i] - '0');
        }else if (s[i] == ']' || s[i] == '}' || s[i] == ')' || s[i] == '(' || s[i] == '[' || s[i] == '{') {
            continue;
        }else{
            float s1 = sta.top(); sta.pop();
            float s2 = sta.top(); sta.pop();
            float re = operation(s2,s1,s[i]);
            sta.push(re);
        }
    }
    return sta.top();
}
string decimalToBinary(int num) {
    LinkedStack<int>sta;
    bool nega_nega = num <0;
    num = abs(num);
    if (num == 0) {
        return "0";
    }
    while (num > 0) {
        sta.push(num%2);
        num/=2;
    }
    string binary = "";
    while (!sta.emptty()) {
        binary+=to_string(sta.peek());
        sta.pop();
    }
    if (nega_nega) {
        binary= "-" + binary;
    }
    return binary;
}
LinkedStack<int>evandod(LinkedStack<int>&ele) {
    LinkedStack<int>ev,od;
    while (!ele.emptty()) {
        if (!(ele.peek() &1)) {
            ev.push(ele.peek());
        }else {
            od.push(ele.peek());
        }
        ele.pop();
    }
    while (!od.emptty()) {
        ev.push(od.peek());
        od.pop();
    }
    return ev;
}
int main () {
    string s;
    cin >> s;
    // cout << valid(s) << endl;
    cout << infix_to_postfix(s) << endl;
    string ss = infix_to_postfix(s);
    cout << postfix_evaluate(ss) << endl;
    int number = (int)postfix_evaluate(ss);
    cout << decimalToBinary(number) << endl;
    LinkedStack<int>ele;
    ele.push(4);
    ele.push(5);
    ele.push(2);
    ele.push(1);
    ele.push(7);
    ele.push(33);
    ele.push(42);
    ele.push(44);
    ele.push(43);
    ele.printStack();
    LinkedStack<int>ans = evandod(ele);
    cout << endl;
    cout << "After" <<endl;
    ans.printStack();
    return 0;
}