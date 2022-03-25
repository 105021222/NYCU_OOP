#include"LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Clear();
}


void LinkedList::Push_back(int x)
{
	//TODO: add a new node to the back of the list with value x
	if(head==NULL){
		head=new Node;
		head->value=x;
		head->next=NULL;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new Node;
	temp=temp->next;
	temp->value=x;
	temp->next=NULL;
}

void LinkedList::Push_front(int x)
{
	//TODO: add a new node to the front of the list with value x
	if(head==NULL){
		head=new Node;
		head->value=x;
		head->next=NULL;
		return;
	}
	Node* temp=head;
	head=new Node;
	head->value=x;
	head->next=temp;
}

void LinkedList::Insert(int index, int x)
{
	//TODO: add a new node at position "index" of the list with value x
	if(head==NULL||index==0){
		Node* temp=head;
		head=new Node;
		head->value=x;
		head->next=temp;
		return;
	}
	Node* temp1=head;
	for(int i=0;i<index-1;i++){
		temp1=temp1->next;
	}
	Node* temp2=temp1->next;
	temp1->next=new Node;
	temp1->next->value=x;
	temp1->next->next=temp2;
}

void LinkedList::Delete(int index)
{
	//TODO: delete the node at position "index"
	Node* temp1=head;
	if(index==0){
		head=head->next;
		delete(temp1);
		return;
	}
	for(int i=0;i<index-1;i++){
		temp1=temp1->next;
	}
	Node* temp2=temp1->next;
	temp1->next=temp2->next;
	delete(temp2);
}

void LinkedList::Reverse()
{
	//TODO: reverse all elements in the list
	if(head==NULL||head->next==NULL){
		return;
	}
	Node* temp=head;
	Node* prev=NULL;
	Node* next=NULL;
	while(temp!=NULL){
		next=temp->next;
		temp->next=prev;
		prev=temp;
		temp=next;
	}
	head=prev;
}

void LinkedList::Print()
{
	//TODO: print out all elements in the list
	if(head==NULL){
		cout<<"The list is empty"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"List: ";
	while(temp->next!=NULL){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<temp->value<<endl;
	
}

void LinkedList::Clear() 
{
	//TODO: delete all elements in the list
	
	while(head!=NULL){
		Node* temp=head;
		head=head->next;
		delete(temp);
	}
}
