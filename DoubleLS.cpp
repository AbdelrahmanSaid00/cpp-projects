#include<iostream>
using namespace std;
struct node
{
    int value = 0;
    node* prev = nullptr;
    node* next = nullptr;
};
typedef node* ptr;
class DoubleLS
{
private:
    node* head;
    int counter;
    node* tail;
public:
    DoubleLS()
    {
        head = nullptr;
        counter = 0;
        tail = nullptr;
    }
    node* END() {
        return tail;
    }
    void insert(int data)
    {
        node* newNode = new node;
        newNode->value = data;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }
    void insertInPosition(ptr position, int data) {
        if (position == nullptr) {
            cout << "not Valid" << endl;
            return;
        }
        if (head == nullptr || position == tail) {
            insert(data);
        }
        else if (position == head) {
            node* newNode = new node;
            newNode->value = data;
            newNode->prev = nullptr;

            newNode->next = head;
            head->prev = newNode;

            head = newNode;
            counter++;
        }else {
            node* newNode = new node;
            newNode->value = data;
            newNode->prev = position->prev;
            newNode->next = position;
            position->prev->next = newNode;
            position->prev = newNode;
            counter++;
        }
    }
    void deleteNode(ptr position)
    {
        if (head == nullptr)
        {
            cout << "The Linked list is empty" << endl;
        }
        else if (position == nullptr)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
            if (position == head)
            {
                    node* temp = head;
                    head = head->next;
                    delete(temp);
                    head->prev = nullptr;
                    if (head == nullptr)
                        tail = head;
                    counter--;
            }
            else if( position == tail)
            {
                node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete(temp);
                counter--;
            }
            else
            {
                position->prev->next = position->next;
                position->next->prev = position->prev;
                position->next = nullptr;
                position->prev = nullptr;
                delete position;
                counter--;
            }

        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "The Linked list is empty" << endl;
        }
        else
        {
            node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    node* Locate(int data)
    {
        node* temp = head;
        while (temp != nullptr)
        {
            if (temp->value == data)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }
    int Retrieve(node* temp)
    {
        return (temp==nullptr)?-1:temp->value;
    }

    node* fisrt()
    {
        return head;
    }

    node* Next(node* temp)
    {
        if (temp == nullptr)
        {
            cout << "Not Founded" << endl;
            return nullptr;
        }
        return temp->next;
    }
    node* prev_back(node* temp)
    {
        if (temp == nullptr)
        {
            cout << "Not Founded" << endl;
            return nullptr;
        }
        return temp->prev;
    }
    void deleteNodeP(node* temp) {
        //طيب ما انت شاطر اهو اومال ممرمطني ليه من الصبح!!!
        if (temp == head) {
            node* del = head;
            head = head->next;
            head->prev = nullptr;
            if (!head->next) {
                tail = head;
            }
            delete del;
        }
        else if (temp == tail) {
            node* del = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete del;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    node*& hea () {
        return head;
    }
    node*& tai() {
        return tail;
    }

};
void marge(DoubleLS& marge1, DoubleLS& marge2)
{
    DoubleLS merge;
    node* m1 = marge1.fisrt();
    node* m2 = marge2.fisrt();
    while (m1) {
        merge.insert(marge1.Retrieve(m1));
        m1 = marge1.Next(m1);
    }
    while (m2) {
        merge.insert(marge2.Retrieve(m2));
        m2 = marge1.Next(m2);
    }
    cout << "The data is " << endl;
    merge.display();
}
void purge(DoubleLS &l) {
    //this is application must be outside the class
    node* start = l.fisrt();
    if (start == nullptr) {
        return;
    }
    while (start != nullptr) {
        node* fast = l.Next(start);
        while (fast) {
            node* save = l.Next(fast);
            if (l.Retrieve(fast) == l.Retrieve(start) && fast != start) {
                l.deleteNodeP(fast);
            }
            fast = save;
        }
        start = l.Next(start);
    }
}
void Reverse(DoubleLS &l)
{
    if (l.END() == nullptr || l.fisrt() == nullptr)
    {
        cout << "The linked list is empty" << endl;
        return;
    }
    node* cur = l.fisrt();
    while (cur != nullptr)
    {
        swap(cur->prev , cur->next);
        cur = cur->prev;
    }
    swap (l.hea() ,l.tai());
}

int main()
{
    DoubleLS l1, l2, l3;
    l1.insert(2);
    l1.insert(1);
    l1.insert(6);
    l1.insert(1);
    l1.insert(9);
    l1.insert(9);
    l1.insert(1);
    l1.insertInPosition(l1.fisrt(), 10);
    l2.insert(4);
    l2.insert(1);
    l2.insert(3);
    l2.insertInPosition(l2.END(), 2);
    l2.insert(7);
    l2.insertInPosition(l2.prev_back(l2.END()), 6);
    l1.display();
    l2.display();
    cout << "************" << endl;
    l1.deleteNode(l1.fisrt());
    l1.display();
    l1.deleteNode(l1.Next(l1.fisrt()));
    l1.display();
    cout << "************" << endl;
    l2.deleteNode(l2.END());
    l2.display();
    cout << "************" << endl;
    marge(l1,l2);
    cout <<endl;
    cout << "************" << endl;
    purge(l1);
    Reverse(l1);
    l1.display();
    cout << "******THANKS******" << endl;
    return 0;
}
