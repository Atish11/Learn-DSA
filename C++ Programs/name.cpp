#include <iostream>
#include <string>

using namespace std;

class Node{
	public:
		string data;
		Node *next;
		
	Node(){
		data='0';
		next=NULL;
	}
	Node(string name){
		data=name;
		next=NULL;
	}
};

class LinkedList{
	public:
    Node *head;
    void add(Node *n);
    void display();
    void addinFront(Node *n);
    Node *search(string value);
    void remove(string name);
    
    LinkedList(){
    	head=NULL;
	}
};

 void LinkedList::add(Node *n){
 	 	if(this->head==NULL)
 	{
 		this->head=n;
 		n->next=NULL;
	 }
	 else
	 {
	 	Node *ptr=this->head;
	 	while(ptr->next !=NULL)
	 	{
	 		ptr=ptr->next;
		 }
		 ptr->next=n;
	 }
 }
 
  void LinkedList::display(){
 	Node *ptr=head;
 	if(ptr==NULL){
 		cout<<"List is Empty";
	 }
 	while(ptr !=NULL){
 		cout<<ptr->data<<" ";
 		ptr=ptr->next;
 		cout<<endl;
	 }
 }
 
 void LinkedList::addinFront(Node *n){
 	n->next=head;
 	head=n;
 }
 
 Node *LinkedList::search(string value){
	
	if(head == NULL){
		return NULL;
	}
     Node *ptr=head;
    while(ptr->next != NULL){
			if(ptr->data == value){
				return ptr;
			}
			ptr = ptr->next;
		}
}
 
 void LinkedList::remove(string name){
	Node *tmp, *prev=NULL;
	tmp=this->head;
	//if the item is the first item
	if(tmp->data=="name"){
		this->head=tmp->next;
		cout<<"Successfully deleted"<<"name"<<"from the front of the list";
		cout<<endl;
		return;
	}
	
	//now lets traverse
	
	while(tmp->next!=NULL){
		if(tmp->data=="name"){
			prev->next=tmp->next;
			cout<<"Successfully deleted"<<"name"<<"from the middle of the list";
			cout<<endl;
		}
	}
}
 
 
 int main(){
 	Node *n1,*temp,*prev;
 	string name;
 	LinkedList l1;
 	int choice=0;
 	while(1)
 	{
 		cout<<endl;		
 		cout<<"1.Display all items in the list"<<endl;
 		cout<<"2.Search"<<endl;
 		cout<<"3.Insert name at the end of the list"<<endl;
 		cout<<"4.Insert name infront of the list"<<endl;
 		cout<<"5.Insert name in middle of the list"<<endl;
 		cout<<"6.Delete the node"<<endl;
 		cout<<"0.Exit"<<endl;
 		cout<<"Enter your choice:";
        cin>>choice;
        cout<<endl;
	 switch(choice)
	{
		
		case 1:
     		cout<< endl;
     		l1.display();
     		cout<<endl;
     		break;
     		
     	case 2:
		    cout<<endl;
		    cout<<"Search name:";
			cin>>name;
			temp=l1.search(name);
			if(temp==NULL){
				cout<<name<<" " "does not exist"<<endl;
				break;
			}
			else
			cout<<name<<" ""exist"<<endl;			
		
            break;
				
		case 3:
			while(1)
			{
				cout <<endl;
				cout <<" Insert name (or type '0' to go to main menu):";
				cin >>name;
				
				
				if(name=="0")
				{
					break;
				}
				n1 = new Node(name);
				l1.add(n1);
	    	}
			break;
			
		
     		
     	case 4:
     		cout<<endl;
     		cout<<"Insert a name:";
     		cin>>name;
     		
     		if(name=="0"){
     			break;
			 }
			 n1=new Node(name);
			 l1.addinFront(n1);
			 cout<<endl;
			 l1.display();
             break;
     		
			
		case 5:
		    cout<<endl;
		    cout<<"Insert after which name you want to add:";
			cin>>name;
			temp=l1.search(name);
			if(temp==NULL){
				cout<<name<<" ""does not exist"<<endl;
				break;
			}
			
            cout<<"Insert name to be added:";
            cin>>name;
            n1=new Node(name);
            n1->next=temp->next;
            temp->next=n1;
            cout<<endl;
            break;	
     		
     	case 6:
            cout<<endl;
        	cout<<"Insert a name to be deleted:";
            cin>>name;
		    temp = l1.head;
            //first item
            if(temp->data == name){
	        l1.head = temp->next;
	        cout << "successfully deleted "<<name<<" from the front of the list."<<endl;
	        break;
	    }
	       //second item
            while(temp->next != NULL){
	        if(temp->data == name){
		    prev->next = temp->next;
		    cout << "Successfully deleted "<< name << " from the middle of the list.";
		    cout<<endl;
		    break;
	   }
	       
	        prev = temp;
	        temp = temp->next;
   }

         if(temp->next == NULL && temp->data == name){
	     prev->next = NULL;
	     cout<<"Successfully deletd "<<name<<" from the end of the list."<<endl;
        }
        else
		    cout<<name<<" ""does not exist"<<endl;

            break; 
			
				
     	case 0:
          	return 1;
        	break;
        	
        default:
	         cout<<"insert valid option"<<endl;
	        break;		
        }
    }
}
 
