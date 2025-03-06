#include<bits/stdc++.h>
using namespace std;
using value = struct {int num;};
/** Single Linked List*/
struct node {
    value da ;
    node *next;
};
class Linked_List {
private:
    node *head;
    int counter;
    node *tail;
public:
    Linked_List() {
        this->head = nullptr;
        this->counter=0;
        this->tail=nullptr;
    }
    node* END() {
        if (head == nullptr) {
            return nullptr;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }
    void InsertAtPosition(int data , int pos) {
        node *NewNode = new node;
        NewNode->da.num = data;
        if (pos > counter + 1 || pos < 1) {
            cout<<"Invalid Position"<<endl;
        }else if (pos == 1) {
            NewNode->next = head;
            head = NewNode;
            counter++;
        } else {
            node *temp = head;
            for (int i = 1; i < pos - 1 && temp->next!=nullptr; i++) {
                temp = temp->next;
            }
            NewNode->next = temp->next;
            temp->next = NewNode;
            counter++;
        }
    }
    void insertback(int data) {
        node *NewNode = new node;
        NewNode->da.num = data;
        if (head == nullptr) {
            head = NewNode;
            NewNode->next = nullptr;
            counter++;
        }
        else {
            node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = NewNode;
            NewNode->next = nullptr;
            counter++;
        }
    }
    void Delete(int pos) {
        if (pos > counter || pos < 1) {
            cout<<"Invalid Position"<<endl;
        }else if (pos==1) {
            node *temp = head;
            head = head->next;
            delete temp;
            counter--;
        }else {
            node *temp = head;
            int cnt =1;
            while (temp->next != nullptr && cnt < pos -1) {
                temp = temp->next;
                cnt++;
            }
            node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            counter--;
        }
    }
    node*Location (int data) {
        node *temp = head;
        while (temp!= nullptr) {
            if (temp->da.num == data) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    int Ele (node* temp) {
        if (temp == nullptr) {
            cout << "Not Founded" << endl;
            return 0;
        }
        return temp->da.num;
    }
    void display() {
        node *temp = head;
        if (temp == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        while (temp->next != nullptr) {
            cout << temp->da.num << " -> ";
            temp = temp->next;
        }
        cout << temp->da.num <<endl;
    }
    node* First () {
        return head;
    }
    int loca (node* temp ) {
        if (temp == nullptr) {
            return -1;
        }
        int cnt=1;
        node* cur = head;
        while (cur!= nullptr) {
            if (cur == temp) {
                return cnt;
            }
            cur = cur->next;
            cnt++;
        }
        return -1;
    }
    node* Next (node* temp) {
        if (temp == nullptr) {
            cout << "Not Founded" << endl;
            return nullptr;
        }
        return temp->next;
    }
    node* Prev (node* temp) {
        if (temp == head) {
            return nullptr;
        }
        node *prev = head;
        while (prev->next!=nullptr&& prev->next!= temp ) {
            prev = prev->next;
        }
        return prev;
    }
    int Size() {
        return counter;
    }
};

signed main() {
    Linked_List L;
    L.insertback(12);
    L.insertback(13);
    L.InsertAtPosition(14 , 1);
    L.InsertAtPosition(15,2);
    L.insertback(16);
    L.InsertAtPosition(17,3);
    L.display();
    cout << L.Size() << endl;
    int x;
    cin >> x;
    node* loc = L.Location(x);
    loc = L.Next(loc);
    if (loc == nullptr) {
        cout << "Not Founded" << endl;
    }else {
        cout << loc->da.num << endl;
    }
    loc = L.Prev(loc);
    if (loc == nullptr) {
        cout << "Not Founded" << endl;
    }else {
        cout << loc->da.num << endl;
    }
    cout << "The Linked List After Delete x :" << endl;
    int ps = L.loca(loc);
    if (ps == -1) {
        cout << "Can't delete " << endl;
    }else {
        L.Delete(L.loca(loc));
    }
    L.display();
    L.Size();
    return 0;
}