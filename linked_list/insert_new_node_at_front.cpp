#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

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

Node* insertAtBeginning(Node** head, int value){
    Node* current_first = *head;
    Node* temp = new Node();
    temp->data = value;
    if ( !current_first)
        temp->next = nullptr;
    else
        temp->next = current_first;
    return temp;
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
    printNodes(first);

    int data_at_beginning = 0;
    cout<<"Enter data for node you want to insert at beginning \n";
    cin>>data_at_beginning;

    Node* newFirst = insertAtBeginning(&first, data_at_beginning);
    cout<<"Linked list after inserting new node at beginning \n";
    printNodes(newFirst);
 }
