#include<iostream>

using namespace std;

class stack
{
	public:
	
		int *base;
		int top;
		int total_capacity;
	
	public:	
		stack(int size);
	//	~stack();
		
		void push(int x);
		int pop();
		int peek();
		int size();
		bool isEmpty();
		bool isFull();
	
};

stack::stack(int size)
{
	base=new int[size];
	total_capacity =size;
	top=-1;
}

int stack::size(){
	return top+1;
}

void stack::push(int x)
{
	if (isFull())
	{
		cout<<"Cannot insert new element as the stack is already full."<<endl;
		return;
	}
	++top;
	*(base+top) = x;
	cout<<"New Element inserted successfully."<<endl;
}

int stack::pop()
{
	if(isEmpty())
	{
		cout<<"Cannot pop as the stack is really empty. "<<endl;
		exit(-1);
	}
	int ret_value=*(base+top);
	top--;
	return ret_value;
}

int stack::peek()
{
	if(!isEmpty())
	{
		return *(base+top);
	}
	else
	{
		cout<<"The stack is empty hence cannot peek. "<<endl;
	}
}

bool stack::isFull(){
	if(size()==total_capacity){
		return true;
	}
	return false;
}


bool stack::isEmpty()
{
	if(top== -1)
	{
		return true;
	}
	return false;
}

int main()
{
	int choice, number;
	
	cout<<"Insert the size of stack: "<<endl;
	cin>> number;
	stack stk1(number);
	
	


	while(1)
	{
		cout<<endl;
		cout<<"1. Push item: "<<endl;
		cout<<"2. Pop item: "<<endl;
		cout<<"3. Peek item: "<<endl;
		cout<<"4. Size: "<<endl;
		
		cout<<"0. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>> choice;
		
		switch(choice)
		{
			case 1:
				while(1){
				
				cout<<endl;
				cout<<"Push an number: ";
				cin>>number;
				if(number==0){
				
					break;
				}
				stk1.push(number);
			    }
				break;
			
			case 2:
				cout<<"An element is poped, the value is: "<<stk1.pop();
				cout<<endl;
				break;
				
			case 3:
				cout<<"Element peeked without poping, the value is: "<<stk1.peek();
				cout<<endl;
				break;
				
			case 4:
				cout<<"The size is: "<<stk1.size()<<endl;
				break;
				
				
			case 0:
				return 1;
				break;
				
			default:
				cout<<"Insert a valid number.";
				break;
				
				
		}
	}
}





	
	
	
	


