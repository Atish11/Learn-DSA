#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Node
{ 
	public:
	    int data;
	    Node *next;
	    Node(){
	    	data=0;
	    	next=NULL;
	}
	
	Node(int num){
		data=num;
		next=NULL;
	}
};
 class LinkedList{
	 public:
	 	Node * head;
	 	void add(Node *n);
	 	void display();
	 	void addInFront(Node *n);
	 	Node *search(int value);
	 	void addend(Node *n);
	 	void remove(int number);
		void selectionsort();	
		void insertionsort();
		void bubblesort();

	 	
	 	LinkedList(){
	 		head=NULL;
		 }
 };
 
 void LinkedList::addInFront(Node *n)
 {
 	n->next = head;
 	head=n;
 }
 

void LinkedList::add(Node *n){  // :: scope resolutio operator
	if(this->head==NULL){
		this->head=n;
		n->next=NULL;
	}
	else{
		Node *ptr=this->head;
		while(ptr->next !=NULL){
			ptr=ptr->next;
		}
		ptr->next=n;
	}
}

void LinkedList::display(){
	Node *ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
   }
   cout<<endl;	
} 

Node *LinkedList::search(int value){
	if(head==NULL){
		return NULL;
	}
	else
	{
		Node *ptr=head;
		while(ptr->next!=NULL)
		{
			if(ptr->data==value)
			{
				return ptr;
			}
			ptr=ptr->next;
		}
	}
	return NULL;
}

void LinkedList::remove(int number){
	Node *tmp, *prev=NULL;
	tmp=this->head;
	//if the item is the first item
	if(tmp->data==number){
		this->head=tmp->next;
		cout<<"Successfully deleted"<<number<<"from the front of the list";
		cout<<endl;
		return;
	}
	
	//now lets traverse
	
	while(tmp->next!=NULL){
		if(tmp->data==number){
			prev->next=tmp->next;
			cout<<"Successfully deleted"<<number<<"from the middle of the list";
			cout<<endl;
		}
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp->next==NULL && tmp->data ==number)
	{
		prev->next=NULL;
		cout<<"Successfully deletd"<<number<<"from the end of the list.";
	}
}
void LinkedList::selectionsort()
{
	Node *temp = new Node();
	Node *min = new Node();
	Node *ptr = new Node();
	Node *curr_ptr = new Node();
	ptr = head;
	
	while(ptr->next !=NULL)
	{
		min = ptr;
		curr_ptr = ptr->next;
		while(curr_ptr !=NULL)
		{
			if(min->data > curr_ptr->data)
			{
				min = curr_ptr;			
			}
			curr_ptr = curr_ptr->next;
		}
		temp->data = min->data;
		min->data = ptr->data;
		ptr->data = temp->data;
		ptr = ptr->next;
	}
}

void LinkedList::insertionsort()
{
	Node *ptr = head;
	int i=0;
	int j;
	while(ptr != NULL)
	{
		Node *tmp = head;
		for(j=0; j<i; j++)
		{
			if(ptr->data < tmp->data)
			{
				int temp = ptr->data;
				ptr->data = tmp->data;
				tmp->data=temp;
			}
			tmp = tmp->next;
		}
		i++;
		ptr=ptr->next;
	}
}

void LinkedList::bubblesort()
{
	Node *base, *cur;
	Node *ptr =this->head;
	while(ptr->next != NULL)
	{
		base = this->head;
		cur= this->head->next;
		while(cur !=NULL)
		{
			if(base->data > cur->data)
			{
				int temp =base->data;
				base->data = cur->data;
				cur->data = temp;
			}
			base = cur;
			cur = cur->next;
		}
		ptr = ptr->next;
	}
}



int main()
{
	LinkedList l1;
	Node *n1,*tomp, *temp, *prev;
	int number=0;
	int choice=0;
	while(1){
		cout<<"1. Insert item on the end of the List:"<<endl;
		cout<<"2. Display item of the list:"<<endl;
		cout<<"3. Insert item on the front of the list:"<<endl;
		cout<<"4. Insert nuber in middle:"<<endl;
		cout<<"5. Romove element:"<<endl;
		cout<<"6. Sort the list using selection sort: "<<endl;
		cout<<"7. Sort the list using insertion sort: "<<endl;
		cout<<"8. Sort the list using bubble sort: "<<endl;
		cout<<"0. exit"<<endl;
		cout<<"Enter your choice :"	;
		cin>> choice;

switch(choice){
	case 1:
		while(1){
			cout<<endl;
			cout<<"Insert an number: (type 0-end)";
			cin>>number;
			if(number==0){
				break;
			}
		    n1=new Node(number);
			l1.add(n1);
		}
	    break;	
	case 2:
		cout <<endl;
		l1.display();
		cout << endl;
		break;
	case 3:
		cout <<endl;
		cout<<"Insert a number:";
		cin>>number;
		if(number==0){
			break;
		}
		n1=new Node(number);
		l1.addInFront(n1);
		break;
		
	case 4:
		cout <<endl;
		cout <<"Insert after which number you want to add?";
		cin >>number;
		tomp = l1.search(number);
		if(tomp == NULL){
			cout <<"Cant find the given number ....." <<endl;
			break;
		}
		cout << tomp->data<<endl;
		cout << "Insert a number to insert:";
		cin >>number;
		n1 = new Node(number);
		n1->next =tomp->next;
		tomp->next=n1;
		cout<< endl;
		break;
	
	case 5:
	    cout<<endl;
        cout<<"Insert a number to be deleted:";
        cin>>number;
		temp = l1.head;
          //check if the item is the first item
        if(temp->data == number){
	    l1.head = temp->next; //just update the head.
	    cout << "successfully deleted "<<number<<" from the front of the list.";
	    break;
		}
//		If node is the element in the middle of the list?
		while(temp->next != NULL){
		if(temp->data == number){			
		prev->next = temp->next;			
		cout << "Successfully deleted "<< number << "from the middle of the list.";			
		cout<<endl;			
		break;			
		}
		prev = temp;
		temp = temp->next;
		}
		//if not in middle check if its the end ...
		if(temp->next == NULL && temp->data == number){
		prev->next = NULL;		
		cout<<"Successfully deletd "<<number<<" from the end of the list.";	
		break;	
		}
		break;
		
	case 6:
		l1.selectionsort();
		cout<<"Sorting Complete using selection sort."<<endl;
		break;
		
	case 7:
		l1.insertionsort();
		cout<<"Sorting Complete using insertionsort sort."<<endl;
		break;
		
	case 8:
		l1.bubblesort();
		cout<<"Sorting Complete using bubble sort."<<endl;
		break;

	
	case 0:
		return 1;
	default:
		cout<<"Insert a valid number";
		break;
		
  }
 }
}


