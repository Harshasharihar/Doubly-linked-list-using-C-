#include<iostream>
using namespace std;
#define null 0
class Dlist
{
	private: struct dnode
				{	struct dnode *prev;
					int data;
					struct dnode *next;
				}*start;
				
	public:
		Dlist();
		void create_append(int);
		void add_at_begin(int);
		void insert_node(int ,int);
		void delete_node(int);
		void display();
		void counter();
		~Dlist();
};

Dlist::Dlist()
{
	start = null;	
}

void Dlist::create_append(int num)
{
	struct dnode *temp,*k;
	if(start == null)
	{
		temp = new struct dnode;
		if(temp == null)
		{
			cout<<"node creation failed\n";
			exit(0);
		}
		temp->prev = null;
		temp->data = num;
		temp->next = null;
		start = temp;
		cout<<"---------------------\n";
	}
	else
	{
		temp = start;
		while(temp->next != null)
		{
			temp = temp->next;
		}	
		k = new struct dnode;
		if(k == null)
		{
			cout<<"node creation failed\n";
			exit(0);
		}
		k->prev = temp;
		k->data = num;
		temp->next = k;
		k->next = null;
		cout<<"---------------------\n";
		
	}
}

void Dlist::add_at_begin(int num)
{
	struct dnode *k;
	k = new struct dnode;
	if(k == null)
	{
			cout<<"node creation failed\n";
			exit(0);
	}
	k->prev = null;
	k->data = num;
	k->next = start;
	start->prev=k;
	start = k;
}

void Dlist::display()
{
	struct dnode *temp;
	temp = start;
	while(temp !=null)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

void Dlist::counter()
{
	struct dnode *temp;
	int count = 0;
	temp = start;
	while(temp!=null)
	{
		count++;
		temp = temp->next;
		
	}
	cout<<"The totla number of nodes present in a doubly linked list are "<<count<<endl;
}
void Dlist::insert_node(int num,int pos)
{
	struct dnode *temp,*k;
	int i;
	temp = start;
	for(i = 0;i< pos;i++)
	{
		temp = temp->next;
	if(temp == null)
	{
		cout<<"no of nodes is less than "<<pos<<endl;
		exit(0);
	}
	
	
		k = new struct dnode;
		if(k == null)
		{
			cout<<"Node creation failed\n";
			exit(0);
		}
		k->next = temp->next;
		temp->next->prev = k;
		temp->next = k;
		k->prev=temp;
		k->data = num;
		
	}
}

void Dlist::delete_node(int num)
{
	struct dnode *k;
	k = start;
	while(k!=null)
	{
		if(k->data == num)
		{
			if(k == start)//first node
			{
				start = start->next;
				start->prev = null;
			}
			else
			{
				if(k->next == null)//last node
				{
					k->prev->next = null;
				}
				else//any other node
				{
					k->prev->next = k->next;
					k->next->prev = k->prev;
				}
			delete k;
			}
			return;
		}
		k = k->next;
	}
	cout<<"no node found\n";
}

Dlist::~Dlist()
{
	struct dnode *temp;
	temp = start;
	while(start !=null)
	{
		start = start->next;
		start->prev = null;
		delete temp;
	}
}
int main()
{
	int num = 0,pos =0,choice = 0;
	Dlist l;
while(1)
{
	    cout<<"Enter the choice\n";
        cout<<"1 create/append\n";
        cout<<"2 add at beginning\n";
        cout<<"3 insert\n";
        cout<<"4 delete\n";
        cout<<"5 display the elements of each node\n";
        cout<<"6 count the number of nodes\n";
        cout<<"7 exit\n";
        cin>> choice;

        switch(choice)
        {
        case 1: cout<<"Enter the element\n";
                cin>>num;
                l.create_append(num);
                break;
        case 2: cout<<"Enter the element\n";
                cin>>num;
                l.add_at_begin(num);
                break;
        case 3: cout<<"Enter the element\n";
                cin>>num;
                cout<<"Enter the position\n";
                cin>>pos;
                l.insert_node(num,pos);
                break;
        case 4: cout<<"Enter the element\n";
                cin>>num;
                l.delete_node(num);
                break;
        case 5: l.display();
                break;
        case 6: l.counter();
                break;
        case 7: cout<<"Exiting now...\n";
                exit(0);
        default :cout<<"Wrong input plz try again\n";
        }
    }
	
	return 0;
}
