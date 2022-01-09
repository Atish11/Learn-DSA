#include<iostream>

using namespace std;

class queue
{
	public:
		int *base;
		int front;
		int rear;
		int total_capacity;
		
	public:
		~queue();
		queue(int size);
		void enqueue(int x);
		int dequeue();
		int size();
		int peek();
		bool isEmpty();
		bool isFull();
		void display();
		
};

queue::queue(int size)
{
	base=new int[size];
	total_capacity=size;
	front=0;
	rear=-1;
};

void queue::enqueue(int x)
{
	if(isFull())
	{
		cout<<"Queue is already full cannot enqueue new items.\n";
	}
	else
	{
		cout<<"Inserting "<<x<<" on the queue\n";
		rear++;
		*(base+rear)=x;
	}
}

int queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty and has no elements to dequeue.\n";
		exit(-1);
	}
	int ret_val= *(base+front);
	front++;
	return ret_val;
}

int queue::size()
{
	return(rear-front+1);
}

int queue::peek()
{
	if(!isEmpty())
	{
		return *(base+front);
	}
	else
	{
		cout<<"The Queue is empty hence cannot peek. "<<endl;
	}
}

bool queue::isEmpty()
{
	if(front>rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queue::isFull()
{
	if(this->size()>=total_capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void queue::display()
{
	int i;
	if(!this->isEmpty())
	{
		for(i=front; i<=rear; i++)
		{
			if(i==front)
			{
				cout<<"(F)";
			}
			cout<<(int) *(base+i)<<"<-";
			if(i==rear)
			{
				cout<<"(R)";
			}
		}
	}
	else
	{
		cout<<"Queue Empty"<<endl;
	}
}

queue::~queue()
{
	delete base;
}
	
	
int main()
{
	int choice, number;
	cout<<"Insert the size of Queue: "<<endl;
	cin>>number;
	queue que1(number);
	
	while(1)
	{
		cout<<endl;
		cout<<"1. Enqueue an item: "<<endl;
		cout<<"2. Dequeue an item: "<<endl;
		cout<<"3. Peek item: "<<endl;
		cout<<"4. Size: "<<endl;
		cout<<"5. Display queue: "<<endl;
		
		cout<<"0. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>> choice;
		
		switch(choice)
		{
			case 1:
				while(1)
				{
					cout<<endl;
					cout<<"Enqueue an number: ";
					cin>>number;
					if(number==0)
					{
						break;
					}
					que1.enqueue(number);
				}
				break;
				
			case 2:
				cout<<endl;
				cout<<"An element is dequeued, the value is: "<<que1.dequeue();
				cout<<endl;
				break;
				
			case 3:
				cout<<endl;
				cout<<"Element peeked without dequeing, the value is: "<<que1.peek();
				cout<<endl;
				break;
				
			case 4:
				cout<<endl;
				cout<<"The size is: "<<que1.size()<<endl;
				cout<<endl;
				break;
				
			case 5:
				cout<<endl;
				que1.display();
				cout<<endl;
				break;
						
			case 0:
				return 1;
				break;
			
			default:
				cout<<endl;
				cout<<"Insert a valid number.";
				break;		
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
