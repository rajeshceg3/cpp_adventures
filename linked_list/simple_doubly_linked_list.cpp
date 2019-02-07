#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};


Node* createNode(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
   	return temp;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	Node* Node_arr[5] = {};
	int Node_index = 0;
	for (auto &a: arr){
	Node_arr[Node_index++] = createNode(a);
	}
   
  for(auto& i : Node_arr){
	  cout<<i->data << "\n";
  }
}
