#include<bits/stdc++.h>
using namespace std;
const int tsize = 11;
struct node {
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};
class HashTable {
private:
node *ptr[tsize],*temp[tsize],*root[tsize];
public:
    HashTable () {
        for(int i=0 ; i < tsize ;i++) {
            ptr[i] = temp[i] = root[i] = nullptr;
        }
    }
    void insert(int key) {
        int index = key % tsize;
        ptr[index] = new node(key);
        if (root[index]==nullptr) {
            root[index] = ptr[index];
            root[index]->next = nullptr;
            temp[index] = ptr[index];
        }else {
            temp[index] = root[index];
            while(temp[index]->next!=nullptr) {
                temp[index] = temp[index]->next;
            }
            temp[index]->next = ptr[index];
            temp[index]->next->next = nullptr;
        }
    }
    bool search(int key) {
        int index = key % tsize;
        if (root[index] == nullptr) {
            return false;
        }
        temp[index] = root[index];
        while(temp[index] !=nullptr) {
            if (temp[index]->data == key) {
                return true;
            }
            temp[index] = temp[index]->next;
        }
        return false;
    }
    void deleteNode(int key) {
        int index = key % tsize;
        if (root[index] == nullptr) {
            cout << "Element not found \n";
            return;
        }
        if (root[index]->data == key) {
            node* deletenode = root[index];
            root[index] = root[index]->next;
            delete deletenode;
            return;
        }
        temp[index] = root[index];
        while (temp[index] != nullptr && temp[index]->next != nullptr){
            if (temp[index]->next->data == key) {
                node* deletenode = temp[index]->next;
                temp[index]->next = temp[index]->next->next;
                delete deletenode;
                return;
            }
            temp[index] = temp[index]->next;
        }
        cout << "Element not found\n";
    }
    void display () {
        for(int i=0 ; i < tsize ;i++) {
            cout << "Index " << i << ": ";
            node* curr = root[i];
            while(curr!= nullptr) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout <<"NULL\n";
        }
    }
    void sortHash(int k) {
        int index = k % tsize;
        vector<int>v;
        if (root[index] == nullptr) {
            cout << "The root is empty" << endl;
            return;
        }
        temp[index] = root[index];
        while(temp[index]!=nullptr) {
            v.push_back(temp[index]->data);
            temp[index] = temp[index]->next;
        }
        sort(v.begin() , v.end());
        temp[index] = root[index];
        int i=0;
        while(temp[index]!=nullptr) {
            temp[index]->data = v[i];
            i++;
            temp[index] = temp[index]->next;
        }
        cout << "The sort is complete" << endl;
    }
};

int main () {
    HashTable ht;
    ht.insert(43);ht.insert(10);ht.insert(32);
    ht.insert(54);ht.insert(21);ht.insert(22);ht.insert(4);
    ht.insert(66);ht.insert(88);ht.insert(48);ht.insert(49);ht.insert(27);
    cout << "\n--- Hash Table ---\n";
    ht.display();
    int key = 32;
    if (ht.search(key))
        cout << "\n" << key << " found in the table.\n";
    else
        cout << "\n" << key << " not found in the table.\n";
    ht.insert(5);
    cout << "\nDeleting 88...\n";
    ht.deleteNode(88);
    cout << "\n--- Hash Table After Deletion ---\n";
    ht.sortHash(10);
    ht.display();
    return 0;
}