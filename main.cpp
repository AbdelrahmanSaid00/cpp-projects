#include<bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef int Position;
class List {
private:
    ElementType *element;
    int capacity;
    Position last;
public:
    List() {
        element = new ElementType[100];
        capacity = 100;
        last = -1;
    }
    List (int n) {
        element = new ElementType[n];
        capacity = n;
        last = -1;
    }
    void makeNull () {
        last = -1;
    }
    Position END () {
        return last + 1;
    }
    void Insert (Position pos, ElementType x) {
        if (capacity == last) {
            cout << "The List is full" << endl;
        }else if (pos > last + 1 || pos < 0) {
            cout << "pos out of the range" << endl;
        }else {
            for (int i=last ; i >= pos ;i--) {
                element[i+1] = element[i];
            }
            last++;
            element[pos] = x;
        }
    }
    void Delete (Position pos) {
        if (pos > last || pos < 0) {
            cout << "out of range" << endl;
        }
        for (int i = pos ; i <= last ;i++) {
            element[i] = element[i+1];
        }
        last--;
    }
    Position Locate (ElementType x) {
        for (int i=0 ; i < last ; i++) {
            if (element[i] == x) {
                return i+1;
            }
        }
        return -1;
    }
    ElementType Retrieve (Position pos) {
        if (pos > last || pos < 0) {
            cout << "Out of range" << endl;
            return 0;
        }else{
            return element[pos];
        }
    }
    void Display () {
        for (int i=0 ; i <= last ; i++) {
            cout << "Element[" << i << "] = " <<  element[i] << " "  << endl;
        }
        cout << endl;
    }
    Position first () {
        return 0;
    }
    Position Next (const Position pos) {
        if (pos < 0 || pos > last) {
            cout << "out of range" << endl;
            return -1;
        }else {

            return pos+1;
        }
    }
    Position Previous (Position pos) {
        if (pos < 0 || pos > last) {
            cout << "out of range" << endl;
        }else {
            return pos--;
        }
    }
    Position Size () {
        return END();
    }
    void Purge () {
        unordered_set<int> duble;
        int NewLast=-1;
        for (int i=0 ; i <= last ;i++) {
            if (duble.find(element[i]) == duble.end()) {
                duble.insert(element[i]);
                element[++NewLast] = element[i];
            }
        }
        last = NewLast;
    }
    void Revarse () {
        for (int i=0 , j = last ; i < j ;i++ , j--) {
            swap(element[i], element[j]);
        }
    }
    void InsertXafterY (ElementType x , ElementType y) {
        Position pos = Locate(y);
        if (pos == last+1) {
            Insert(pos , x);
        }else {
            Insert(pos+1 , x);
        }
    }
    void Concatenate (List &Lt) {
        for (int i=0 ; i < Lt.Size() ;i++) {
            Insert(END() , Lt.element[i]);
        }
    }
    void Split(List &oddList, List &evenList) {
        for (int i = 0; i <= last; i++) {
            if (element[i] % 2 == 0) {
                evenList.Insert(evenList.END(), element[i]);
            } else {
                oddList.Insert(oddList.END(), element[i]);
            }
        }
    }
    int Sum() {
        int sum = 0;
        for (int i = 0; i <= last; i++) {
            sum += element[i];
        }
        return sum;
    }
    void RemoveOccurrences(ElementType x) {
        int newLast = -1;
        for (int i = 0; i <= last; i++) {
            if (element[i] != x) {
                element[++newLast] = element[i];
            }
        }
        last = newLast;
    }
    Position LocateInRange(ElementType x, Position start, Position end) {
        if (start < 0 || end > last || start > end) {
            return END();
        }
        for (int i = start; i <= end; i++) {
            if (element[i] == x) {
                return i;
            }
        }
        return END();
    }
    void RemoveOccurrencesInRange(ElementType x, Position start, Position end) {
        if (start < 0 || end > last || start > end) {
            cout << "Non Valid" << endl;
            return;
        }
        else {
            int NewLast = start -1;
            for (int i=start ; i <= end; i++) {
                if (element[i] != x) {
                    element[++NewLast] = element[i];
                }
            }
            last = NewLast;
        }
    }
};
signed main() {
    List L(10);
    L.Insert(L.END(),3);
    L.Insert(L.first(),1);
    L.Insert(L.END(),2);
    L.Insert(L.first(),4);
    L.Display();
    L.Delete(1);
    L.Display();
    int pos;
    cout << "Enter the position of your Element that you wanna Retrieve: ";
    cin >> pos;
    cout << "The Element of position " << pos << "is : " << L.Retrieve(pos) << endl;
    int x;
    cout << "Enter the element that you want to delete it" << endl;
    cin >> x;
    L.RemoveOccurrencesInRange(x,2,5);
    L.Display();
    List oddList, evenList;
    L.Split(oddList, evenList);
    cout << "Odd Numbers: ";
    oddList.Display();
    cout << "Even Numbers: ";
    evenList.Display();
    cout << "Thanks for using this program." << endl;
    return 0;
}