#include<iostream>

using namespace std;

class Node
{ 
	public:
	    int data;
	    Node *prev;
	    Node *next;
	    Node(){
	    	data=0;
	    	prev=NULL;
	    	next=NULL;
	    	
	}
	
	Node(int num){
		data=num;
		prev=NULL;
		next=NULL;
	}
};
class LinkedList{
	public:
		Node *head;
		Node *tail;
		void addinfront(Node *n);
		bool addafter(int prenum, int num);
		void addinlast(Node *n);
		Node* search(int num);
		bool del(int num);
		void display();
		void displayreverse();
		void reverse();
		
		LinkedList()
		{
			head=NULL;
			tail=NULL;
		}
};

void LinkedList::addinlast(Node *n)
{
	if(head == NULL)
	{
		head=n;
		tail=n;
	}
	else
	{
		tail->next=n;
		n->prev=tail;
		tail=n;
	}
}

void LinkedList::display()
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void LinkedList::addinfront(Node *n)
{
	if(head==NULL)
	{
		head=n;
		tail=n;
	}
	else
	{
		n->next=head;
		head->prev=n;
		head=n;
	}
}

void LinkedList::displayreverse()
{
	Node *ptr=tail;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->prev;
	}
	cout<<endl;
}

Node* LinkedList::search(int num)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		Node *ptr=head;
		while(ptr != NULL)
		{
			if(ptr->data==num)
			{
				return ptr;
			}
			ptr=ptr->next;
		}
	}
}

bool LinkedList::addafter(int prenum, int num)
{
	Node *tmp = this->search(prenum);
	if(tmp ==NULL)
	{
		return false;
	}
	else
	{
		Node *n1 = new Node(num);
		n1->next=tmp->next;
		n1->prev=tmp;
		tmp->next->prev=n1;
		tmp->next=n1;
		return true;
	}
} 


bool LinkedList::del(int num)
{
	//check if the list is empty
	Node *tmp=head;
	Node *data;
	if(tmp==NULL)
	{
		return false;
	}
	
	//check if the number exist on the list
	data=this->search(num);
	if(data==NULL)
	{
		return false;
	}
	else
	{
		if(data->prev==NULL && data->next==NULL)
		{
			head=NULL;
			tail=NULL;
			return true;
		}
		
		//if it is the first node
		if(data->prev==NULL)
		{
			data=data->next;
			data->prev=NULL;
			head=data;
			return true;
		}
		
		//if the last node
		if(data->next==NULL)
		{
			data->prev->next=NULL;
			tail=data->prev;
			return true;
		}
		
		//midle in the list
		data->next->prev=data->prev;
		data->prev->next=data->next;
		return true;
	}
}

void LinkedList::reverse()
{
	Node *ptr = head;
	Node *tmp;
	if(ptr == NULL)
	{
		return;
	}
	while(ptr !=NULL)
	{
		tmp=ptr->prev;
		ptr->prev=ptr->next;
		ptr->next=tmp;
		if(ptr->prev==NULL)
		{
			tail=head;
			head=ptr;
		}
		ptr=ptr->prev;
	}
}




int main()
{
	LinkedList l1;
	Node *n1, *tomp, *tmp, *prev;
	int num;
	int number=0;
	int number1=0;
	int choice=0;
	while(1)
	{
		cout<<"1. Insert item on the end of the List :"<<endl;
		cout<<"2. Display item of the list :"<<endl;
		cout<<"3. Insert item on the front of the list : "<<endl;
		cout<<"4. Display item of the list in reverse : "<<endl;
		cout<<"5. Search a item:"<<endl;
		cout<<"6. Insert item after an item :"<<endl;
		cout<<"7. Remove an item : "<<endl;
		cout<<"8. Reverse the list: "<<endl;		
		cout<<"0. exit"<<endl;
		cout<<"Enter your choice :"	;
		cin>> choice;
		
		
		switch(choice)
		{
			case 1:
				while(1)
				{
					cout<<endl;
					cout<<"Insert a number: (type 0-end)";
					cin>>number;
					if(number==0)
					{
						break;
					}
					n1=new Node(number);
					l1.addinlast(n1);
				}
				break;
			
			case 2:
				cout<<endl;
				l1.display();
				cout<<endl;
				break;
			
			case 3:
				cout<<endl; 
				cout<<"Insert a number: ";
				cin>>number;
				if(number==0)
				{
					break;
				}
				n1=new Node(number);
				l1.addinfront(n1);
				break;
				
			case 4:
				cout<<endl;
				l1.displayreverse();
				cout<<endl;
				break;
				
			case 5:
				cout <<endl;
				cout <<"Insert  which number you want to search? ";
				cin >>number;
				tomp = l1.search(number);
				if(tomp == NULL){
				cout <<"Can''t found the given number ....." <<endl;
				break;
			    }
			    else
			    {
			    cout <<" Found the given number ....." <<endl;
				break;
				}
				
			case 6:
				cout<<endl;
				cout<<"Insert after which item you want to add? ";
				cin>>number;
				cout<<"Insert the number you want to add: ";
				cin>>number1;
				if(l1.addafter(number, number1))
				{
					cout<<"Successfully inserted"<<endl;
				}
				else
				{
					cout<<"Can''t found the given number ....."<<endl;
					break;
				}
				break;
				
				
			case 7:
			    cout<<endl;
		        cout<<"Insert a number to be deleted:";
		        cin>>number;
				tmp = l1.head;
		          //check if the item is the first item
		        if(tmp->data == number){
			    l1.head = tmp->next; //just update the head.
			    cout << "successfully deleted "<<number<<" from the front of the list.";
			    break;
				}
				else
				{
					cout<<endl;
					cout<<"Does not found "<< number <<" in list.";
					cout<<endl;
					break;					
				}
		//		If node is the element in the middle of the list?
				while(tmp->next != NULL){
				if(tmp->data == number){	
				prev->next = tmp->next;			
				cout << "Successfully deleted "<< number << "from the middle of the list.";			
				cout<<endl;			
				break;			
				}
				else
				{
					cout<<endl;
					cout<<"Does not found "<< number <<" in list.";
					cout<<endl;
					break;					
				}		
				prev = tmp;
				tmp = tmp->next;
				}
				
				//if not in middle check if its the end ...
				if(tmp->next == NULL && tmp->data == number){
				prev->next = NULL;		
				cout<<"Successfully deletd "<<number<<" from the end of the list.";	
				break;	
				}
				else
				{
					cout<<endl;
					cout<<"Does not found "<< number <<" in list.";
					cout<<endl;
					break;					
				}
				break;
			    
			case 8:
				cout<<endl;
				l1.reverse();
				l1.display();
				cout<<endl;
				break;
			
			case 0:
				return 1;
				default:
					cout<<"Insert a valid number"<<endl;
				    break;
				
		}
	}
}
















