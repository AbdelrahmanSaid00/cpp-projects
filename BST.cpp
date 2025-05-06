#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    node (int value) {
        data =value;
        left = right = parent =nullptr;
    }
};
class BST {
    private:
    node* root = nullptr;
    node *minElement (node *temp) {
        while (temp !=nullptr) {
            temp = temp->left;
        }
        return temp;
    }
    node *maxElement (node *temp) {
        while (temp !=nullptr) {
            temp = temp->right;
        }
        return temp;
    }
    void Inorder (node* temp) {
        if (temp == nullptr) {
            return;
        }
        Inorder(temp->left);
        cout << temp->data << ' ';
        Inorder(temp->right);
    }
    int findHeight (node* temp) {
        if (temp == nullptr) {
            return -1;
        }
        return max(findHeight(temp->left) , findHeight(temp->left)) + 1;
    }
    public:
    void insertion (int data) {
        node * newNode = new node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        node* cur = root;
        node* parent = nullptr;
        while (cur !=nullptr) {
            parent = cur;
            if (data > cur->data) {
                cur = cur->right;
            }else {
                cur = cur->left;
            }
        }
        newNode->parent = parent;
        if (parent->data > data) {
            parent->left = newNode;
        }else {
            parent->right = newNode;
        }
    }
    node* successor (node*temp) {
        if (temp->right !=nullptr) {
            return minElement(temp->right);
        }
        node* par = temp->parent;
        while (par != nullptr && temp == par->right) {
            temp = par;
            par = par->parent;
        }
        return par;
    }
    node* searchNode (int t) {
        if (root == nullptr) {
            return nullptr;
        }
        node* cur = root;
        while (cur!=nullptr) {
            if (cur->data == t) {
                return cur;
            }
            else if (cur->data > t) {
                cur = cur->left;
            }else {
                cur = cur->right;
            }
        }
        return nullptr;
    }
    void deleteNode (int t) {
        if (root == nullptr) {
            cout << "The tree is empty" << endl;
            return;
        }
        node* cur = searchNode(t);
        if (cur == nullptr) {
            cout << "The element doesn't founded" << endl;
            return;
        }
        //case 1 no child
        if (cur->left == nullptr && cur->right == nullptr) {
            if (cur == root) {
                root = nullptr;
            }else {
                if (cur->parent->left == cur) {
                    cur->parent->left = nullptr;
                } else {
                    cur->parent->right = nullptr;
                }
                delete cur;
            }
        }
        //case 2 one child
        else if (cur->right == nullptr || cur->left == nullptr) {
            node* son = cur->left?cur->left:cur->right;
            if (cur == root) {
                root = son;
            }else {
                if (cur->parent->left == cur) {
                    cur->parent->left = son;
                }else {
                    cur->parent->right = son;
                }
                son->parent = cur->parent;
                delete cur;
            }
        }
        //case 3 two child
        else {
            node* temp = successor(cur);
            cur->data = temp->data;
            delNo(cur);
        }
    }
    void delNo(node *temp) {
        //case 1 no child
        if (temp->left == nullptr && temp->right == nullptr) {
            if (temp == root) {
                root = nullptr;
            }else {
                if (temp->parent->left == temp) {
                    temp->parent->left = nullptr;
                } else {
                    temp->parent->right = nullptr;
                }
                delete temp;
            }
        }
        //case 2 one child
        else if (temp->right == nullptr || temp->left == nullptr) {
            node* son = temp->left?temp->left:temp->right;
            if (temp == root) {
                root = son;
            }else {
                if (temp->parent->left == temp) {
                    temp->parent->left = son;
                }else {
                    temp->parent->right = son;
                }
                son->parent = temp->parent;
                delete temp;
            }
        }else {
            cout << "can't do this " << endl;
            return;
        }
    }
    void display () {
        if (root == nullptr) {
            return;
        }Inorder(root);
    }
    int findHt () {
        if (root == nullptr) {
            return 0;
        } return findHeight(root);
    }
};

int main() {
    BST t;
    vector<int>v = {439, 409, 449, 399, 389, 419, 459,469, 479, 429};
    for(int i=0 ; i < v.size() ;i++) {
        t.insertion(v[i]);
    }
    t.display();
    cout << endl;
    sort(v.begin() , v.end());
    for(auto i : v) {
        node*temp = t.searchNode(i);
        if (temp) {
            cout << "successor of "<< i <<" is " << (t.successor(temp)?t.successor(temp)->data : -1) << endl;
        }else {
            cout << "Not exist" << endl;
        }
    }
    cout << "The H before delete is " << t.findHt() << endl;
    t.deleteNode(449);t.deleteNode(469);
    t.deleteNode(479);
    t.deleteNode(459);
    t.deleteNode(389);
    t.display();
    cout << '\n';
    cout << "The H After delete is " << t.findHt() << endl;
    return 0;
}