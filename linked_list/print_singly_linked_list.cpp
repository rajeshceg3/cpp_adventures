#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;

Node* CreateNode( int value ){
    Node *temp = new Node();
    temp->data = value;
    temp->next = nullptr;
    return temp;
}

void printNodes(Node* start){
    while (start) {
        cout<<"Data = "<<start->data<<"\n";
        start = start->next;
    }
}


int main(){

    Node* first;
    Node* second;
    Node* third;
    first = CreateNode(10);
    second = CreateNode(20);
    third = CreateNode(30);
    first->next = second;
    second->next = third;
    // Since third is going to be last node we create, it's next can 
    // be left as NULL
    printNodes(first);
 }
