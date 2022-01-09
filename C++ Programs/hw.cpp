#include<iostream>
#include <string.h>

using namespace std;

class Node
{ 
	public:
	    string data;
	    Node *next;
	    Node(){
	    	data=' ';
	    	next=NULL;
	}
	
	Node(string nam){
		data=nam;
		next=NULL;
	}
};
 class LinkedList{
	 public:
	 	Node * head;
	 	void add(Node *n);
	 	void display();
	 	void addInFront(Node *n);
	 	Node *search(string value);
	 	void addend(Node *n);
	 	void remove(string name);	

	 	
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

Node *LinkedList::search(string value){
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

void LinkedList::remove(string name){
	Node *tmp, *prev=NULL;
	tmp=this->head;
	//if the item is the first item
	if(tmp->data==name){
		this->head=tmp->next;
		cout<<"Successfully deleted"<<name<<"from the front of the list";
		cout<<endl;
		return;
	}
	
	//now lets traverse
	
	while(tmp->next!=NULL){
		if(tmp->data==name){
			prev->next=tmp->next;
			cout<<"Successfully deleted"<<name<<"from the middle of the list";
			cout<<endl;
		}
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp->next==NULL && tmp->data ==name)
	{
		prev->next=NULL;
		cout<<"Successfully deletd"<<name<<"from the end of the list.";
	}
}



int main()
{
	LinkedList l1;
	Node *n1,*tomp, *temp, *prev;
	string name;
	char choice=' ';
	while(1){
		cout<<"[I] Insert item on the end of the List: "<<endl;
		cout<<"[D] Display item of the list: "<<endl;
		cout<<"[F] Insert item on the front of the list: "<<endl;
		cout<<"[S] Insert name by searching: "<<endl;
		cout<<"[R] Romove element: "<<endl;
		cout<<"[E] exit"<<endl;
		cout<<"Enter your choice : "	;
		cin>> choice;

switch(choice){
	case 'I':
		while(1){
			cout<<endl;
			cout<<"Insert name: (type E-end)";
			cin>>name;
			if(name[0]=='E'){
				break;
			}
		    n1=new Node(name);
			l1.add(n1);
		}
	    break;	
	case 'D':
		cout <<endl;
		l1.display();
		cout << endl;
		break;
	case 'F':
		cout <<endl;
		cout<<"Insert a name:";
		cin>>name;
		if(name[0]=='E'){
			break;
		}
		n1=new Node(name);
		l1.addInFront(n1);
		break;
		
	case 'S':
		cout <<endl;
		cout <<"Insert after which name you want to add?";
		cin >>name;
		tomp = l1.search(name);
		if(tomp == NULL){
			cout <<"Cant find the given name ....." <<endl;
			break;
		}
		cout << tomp->data<<endl;
		cout << "Insert a name to add:";
		cin >>name;
		n1 = new Node(name);
		n1->next =tomp->next;
		tomp->next=n1;
		cout<< endl;
		break;
	
	case 'R':
	    cout<<endl;
        cout<<"Insert a name to be deleted:";
        cin>>name;
		temp = l1.head;
          //check if the item is the first item
        if(temp->data == name){
	    l1.head = temp->next; //just update the head.
	    cout << "successfully deleted "<<name<<" from the front of the list.";
	    break;
		}
//		If node is the element in the middle of the list?
		while(temp->next != NULL){
		if(temp->data == name){			
		prev->next = temp->next;			
		cout << "Successfully deleted "<< name << "from the middle of the list.";			
		cout<<endl;			
		break;			
		}
		prev = temp;
		temp = temp->next;
		}
		//if not in middle check if its the end ...
		if(temp->next == NULL && temp->data == name){
		prev->next = NULL;		
		cout<<"Successfully deletd "<<name<<" from the end of the list.";	
		break;	
		}
		break;

	
	case 'E':
		return 1;
	default:
		cout<<"Insert a valid name";
		break;
		
  }
 }
}


