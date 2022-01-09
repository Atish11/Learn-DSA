#include<iostream>
#include<conio.h>

using namespace std;

class Node 
{
	public:
		int data;
		Node *next;
		Node()
		{
			data=0;
			next=NULL;
		}
	
	Node(int num)
	{
		data=num;
		next=NULL;
	}
};
class LinkedList
{
	public:
		Node *last;
		void add(Node *n1);
		void display();
		void addInEnd(Node *n1);
		Node *search(int value);
		void addInmid(Node *n1);
		bool remove(int number);
		
		LinkedList()
		{
			last=NULL;
		}
};


void LinkedList::add(Node *n1){
	if(this->last==NULL){
		cout<<"List is empty!!"<<endl;
		return;

	}
	else{
		n1->next=last->next;
		last->next=n1;
	}
}

void LinkedList::display(){
	Node *ptr=last;
	if(last==NULL)
	{
		cout<<"Empty List!!"<<endl;
	}
	else
	{
		ptr=ptr->next;
		while(ptr!=last){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
	   }
	   cout<<ptr->data<<" "<<endl;	
    }
}

void LinkedList::addInEnd(Node *n1)
{
	if(this->last==NULL){
		this->last=n1;
		n1->next=n1;
	}
	else{
		n1->next=last->next;
		last->next=n1;
		last=n1;
	}
}

Node *LinkedList::search(int value)
{
	if(last==NULL)
	{
		return NULL;
	}
	
	//this is also true
	
	
//	else
//	{
//		Node *ptr = last;
//		ptr=ptr->next;
//		while(ptr != last)
//		{
//			if(ptr->data==value)
//			{
//				return ptr;
//			}
//			ptr=ptr->next;
//		}
//	}


//this is also true

	else
	{
		Node *ptr=last;
		do
		{
			if(ptr->data==value)
			{
				return ptr;
			}
			ptr=ptr->next;
		}while(ptr != last);
	}
	return NULL;
}

bool LinkedList::remove(int number)
{
	Node *prev= NULL;
	Node *curr=last;
	if(last==NULL)
	{
		return false;
	}
	else if (curr->next==last && curr->data==number)
	{
		last=NULL;
		return true;
	}
	else
	{
		do
		{
			if(curr->data==number)
		{
			if(curr == last)
			{
				do
				{
					prev=curr;
					curr=curr->next;
				}
				while(curr->next !=last);
				prev=curr;
				curr=curr->next;
				prev->next=curr->next;
				last=prev;
				return true;
			}
			else
			{
				prev->next=curr->next;
				return true;
			}
		}
			prev=curr;
			curr=curr->next;
		}
			while(curr !=last);	
			
	}
}


int main()
{
	LinkedList l1;
	Node *n1, *tomp;
	int number=0;
	int choice=0;
	while(1)
	{
		cout<<endl;
		cout<<"1. Insert item in the list: "<<endl;
		cout<<"2. Display iteam of the list: "<<endl;
		cout<<"3. Insert item in end of the list: "<<endl;
		cout<<"4. Insert iteam in mid of the list: "<<endl;
		cout<<"5. Remove element:"<<endl;
		
		cout<<"0. exit"<<endl;
		cout<<"Enter your choice: ";
		cin>> choice;
		
		switch(choice)
		{
			case 1:
				
				cout<<endl;
				cout<<"Insert an number: ";
				cin>>number;	
				n1=new Node(number);
				l1.add(n1);
				break;
			case 2:
				cout<<endl;
				l1.display();
				cout<<endl;
				break;
			case 3:
				while(1){
				cout<<endl;
				cout<<"Insert an number: (type 0-end)";
				cin>>number;
				if(number==0){
					break;
					}
				n1=new Node(number);
				l1.addInEnd(n1);
				}
				break;
			case 4:
				cout <<endl;
				cout <<"Insert after which number you want to add? ";
				cin >>number;
				tomp = l1.search(number);
				if(tomp == NULL){
					cout <<"Cant find the given number ....." <<endl;
					break;
				}
				cout <<endl;
				cout <<"Insert a number to insert:";
				cin >>number;
				n1 = new Node(number);
				n1->next =tomp->next;
				tomp->next=n1;
				cout<< endl;
				break;
			
			case 5:
				cout <<endl;
				cout <<"Insert  which number you want to remove? ";
				cin >>number;
				tomp = l1.search(number);
				if(tomp == NULL){
					cout <<"Cant find the given number ....." <<endl;
					break;
				}
				else
				{
					l1.remove(number);
					cout<<endl;	
					cout<<"Successfully deletd "<<number<<" from the end of the list.";
					break;
				}
				break;
			
			case 0:
				return 1;
			default:
				cout<<"Insert a valid number";
				break;
				
		}
	}
}











