#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value =0;
    node *prev = nullptr;
    node *next = nullptr;
};
class DoubleLS
{
private:
    node *head;
    int counter;
    node *tail;
public:
    DoubleLS()
    {
        head = nullptr;
        counter = 0;
        tail = nullptr;
    }
    node * END()
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        node * temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp;
    }
    void insert (int data)
    {
        node* newNode = new node;
        newNode->value = data;
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        else
        {
            node * temp = head;
            while(temp->next!= nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nullptr;
            tail = newNode;
        }
        counter++;
    }
    void insertInPosition(int position, int data)
    {
        if( position > counter   || position < 1 )
        {
            cout<<"Invalid Position" << endl;
        }
        else if (position == 1)
        {
            if(head == nullptr)
            {
                insert (data);
            }
            else
            {
                node* temp = new node;
                temp->value = data;
                temp->next = head;
                head->prev = temp;
                temp->prev = nullptr;
                head = temp;
                counter++;
            }
        }
        else if(position != counter)
        {
            node *newNode = new node;
            node * temp = head ;
            int find=1;
            while(temp->next !=nullptr && find < position)
            {
                temp = temp->next;
                find++;
            }
            newNode->value = data;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
            counter++;
        }
        else if(position == counter)
        {
            insert(data);
        }
    }
    void deleteNode(int position)
    {
        if(head == nullptr)
        {
            cout<<"The Linked list is empty"<<endl;
        }
        else if(position < 1 || position > counter)
        {
            cout<<"Invalid Position"<<endl;
        }
        else
        {
            if(position == 1)
            {
                if(counter == 1)
                {
                    node *temp = head;
                    delete(temp);
                    head = nullptr;
                    counter--;
                }
                else
                {
                    node *temp = head->next;
                    node *temp2 = head;
                    delete(temp2);
                    head = temp;
                    head->prev = nullptr;
                    counter--;
                }
            }
            else if(position < counter)
            {
                node *temp = head;
                int cnt = 2;
                while(temp!= nullptr && cnt < position)
                {
                    temp = temp->next;
                    cnt++;
                }
                node *denode = temp->next;
                temp->next = temp->next->next;
                if(temp->next != nullptr)
                {
                    temp->next->prev = temp;
                }
                delete(denode);
                counter--;
            }
            else
            {
                node *temp = tail;
                tail = tail->prev;
                delete(temp);
                counter--;
            }
        }
    }
    void display()
    {
        if(head == nullptr)
        {
            cout<<"The Linked list is empty"<<endl;
        }
        else
        {
            node *temp = head;
            while(temp != nullptr)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout  << endl;
        }
    }
    node *Location(int data)
    {
        bool valid = false;
        node *temp = head;
        while(temp != nullptr)
        {
            if(temp->value == data)
            {
                valid = true;
                break;
            }
            temp = temp->next;
        }
        if(!valid)
        {
            return nullptr;
        }
        else
        {
            return temp;
        }
    }
    int Value (node *temp)
    {
        if(temp == nullptr)
        {
            return -1;
        }
        else
        {
            return temp->value;
        }
    }

    node *&fisrtNode()
    {
        return head;
    }

    node *&LastNode()
    {
        return tail;
    }
    int Postion (node *temp)
    {
        if(temp == nullptr)
        {
            return -1;
        }
        int cnt =1;
        node * fnode = head;
        while(fnode != nullptr)
        {
            if(fnode == temp)
            {
                return cnt;
            }
            fnode = fnode->next;
            cnt++;
        }
        return -1;
    }
    node* Next (node* temp)
    {
        if (temp == nullptr)
        {
            cout << "Not Founded" << endl;
            return nullptr;
        }
        return temp->next;
    }
    node *prev (node *temp)
    {
        if (temp == nullptr)
        {
            cout << "Not Founded" << endl;
            return nullptr;
        }
        node *foundNode = head;
        while(foundNode->next != nullptr && foundNode->next != temp)
        {
            foundNode = foundNode->next;
        }
        return foundNode;
    }
    int Length ()
    {
        return counter;
    }
    void marge(DoubleLS &marge1 , DoubleLS &marge2)
    {
       node *m1 = marge1.head;
       node *m2 = marge2.head;
       while(m1) {
            insert(m1->value);
            m1 = m1->next;
       }
       while(m2) {
            insert(m2->value);
            m2 = m2->next;
       }
    }
    void deleteNodeP(node *temp) {
        if(temp == head) {
            node *del = head;
            head = head->next;
            head->prev = nullptr;
            if(!head->next) {
                tail = head;
            }
            delete del;
        }
        else if(temp == tail) {
            node *del = tail;
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
    void purge () {
        node *start = head;
        if(counter == 1) {
            return;
        }
        else if(head == nullptr) {
            return;
        }
        while(start !=nullptr) {
            node *fast = start->next;
            while(fast) {
                node *save = fast->next;
                if(fast->value == start->value && fast !=start) {
                    deleteNodeP(fast);
                }
                fast = save;
            }
            start = start->next;
        }
    }
    void reverse ()
    {
        if(tail == nullptr || head == nullptr)
        {
            cout << "The linked list is empty"  << endl;
            return;
        }
        node *cur = head;
        while(cur != nullptr)
        {
            node *temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = temp;
        }
        swap(tail, head);
    }
};

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
    l1.insertInPosition(4,10);
    l2.insert(4);
    l2.insert(1);
    l2.insert(3);
    l2.insert(2);
    l2.insert(7);
    l2.insertInPosition(1,6);
    l1.display();
    l2.display();
    cout << "************" << endl;
    l1.deleteNode(3);
    l1.display();
    cout << "************" << endl;
    l2.deleteNode(1);
    l2.display();
    cout << "************" << endl;
    l3.marge(l1,l2);
    l3.display();
    cout << "************" << endl;
    l1.reverse();
    l1.display();
    cout << "************" << endl;
    cout << l1.Postion(l1.fisrtNode()) << endl;
    cout << l1.Postion(l1.Location(9)) << endl;
    cout << l1.Postion(l1.Next(l1.Location(9))) << endl;
    cout << l1.Postion(l1.Next(l1.Next(l1.Location(9)))) << endl;
    cout << "************" << endl;
    cout << "the length of l1 is : "  << l1.Length() << endl;
    cout << "the length of l2 is : "  << l2.Length() << endl;
    cout << "the length of l3 is : "  << l3.Length() << endl;
    cout << "************" << endl;
    l1.purge();
    l1.display();
    cout << "******THANKS******" << endl;
    return 0;
}
