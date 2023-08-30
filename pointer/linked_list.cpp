#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node;

node createNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void insertLastNode(node a ,int x){
    // if(a->next == nullptr){
    //     a->next = createNode(x);
    //     return;
    // }
    // insertLastNode(a->next,x);
    node  tmp = a;
    while(tmp->next){
        tmp=tmp->next;
    };
    tmp->next = createNode(x);
}
void insertFirstNode(node &a,int x){
    node  tmp = createNode(x);
    if(a == nullptr){
        a = tmp;
        return;
    }
    tmp->next = a;
    a = tmp;
    return;
}
int size(node a){
    int size = 0;
    while (a != nullptr)
    {
        a = a->next;
        ++size;
    }
    return size;
    
}
void deleteLast(node a){
    if(a == nullptr) return;

    node node_prev = a;
    node node_next = a->next;
    while (node_next->next)
    {
        node_prev = node_next;
        node_next = node_next->next;
    }
    node_prev->next = nullptr;
     
    
}
int main(){
    int x;
    cout << "Enter fisrt value: "; cin >> x;
    node n = createNode(x);
    cout << n->data << " " << n->next << endl;
    int valueNew ;
    cout << "Insert Node: ";  cin >> valueNew;
    insertLastNode(n,valueNew);
    cout << "Insert Node: ";  cin >> valueNew;
    insertLastNode(n,valueNew);
    cout << n->data << " " << n->next->next->data << endl;
    deleteLast(n);
    cout << n->data << " " << n->next->data<< endl;
    cout << "Size: " << size(n);
    
}
