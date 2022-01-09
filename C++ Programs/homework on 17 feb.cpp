#include <iostream>
#include <string.h>
 
using namespace std;
 
struct Node
	{
	    string stu_name;
	    Node *next;
	};
	
Node *head=NULL;
 
void mainMenu()
{
	cout<<endl;
	cout<<"           Main Menu         "<<endl;
	cout<<"   Choose from the following:   "<<endl;
	cout<<"[A]dd a name"<<endl;
	cout<<"[V]iew all names"<<endl;
	cout<<"[Q]uit"<<endl;
	cout<<endl;
}	
 
void addName()
{
	cout<<endl;
	Node *temp, *alt;
	temp= new Node;
	
	cout<<"What is the student's name:";
	cin>>temp->stu_name;
	temp->next=NULL;
	if(head==NULL)
	    head=temp;
	else
	{
		alt=head;
		while(alt->next !=NULL)
		{
			alt=alt->next;
		}
		alt->next=temp;
	}
}

void viewName()
{
	cout<<endl;
	cout<<"All Names:";
	cout<<endl;
	
	Node *temp;
	temp=head;
	do
	{
		if(temp==NULL)
		   cout<<"Nothing follows."<<endl;
		else
		{
			cout<<"Name: "<<temp->stu_name;
			cout<<endl;
			temp=temp->next;
		}
	}
	while(temp !=NULL);
}


int main(string*)
{
	char choice;
	do
	{
		mainMenu();
		cout<<"Command?: ";
		if(cin>>choice)
		   switch(choice)
		   {
		   	case 'A':
		   		addName();
		   		break;
		   	case 'V':
		   		viewName();
		   		break;
		   }
	}
	while(choice != 'Q');
		cout<<endl;
		cout<<"Terminating.."<<endl;
	system("PAUSE");
	return 0;
}
