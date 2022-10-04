/*Remove Duplicates From Sorted Linked List*/

#include <iostream>
using namespace std;
/*Creating a node class with data as int ans a pointer to next Node*/
class Node
{
public:
	int data;
	Node *next;
	Node(int data)/*constructor*/
	{
		this->data = data;
		this->next = NULL;
	}
};



/*this function takes the input value from the user and if the input is -1 function ends */
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;/*bth head and tail are initialised with NULL
	head will be fixed but tail would chnage after every new addition*/
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
/*this function takes the head of sorted LL*/
Node*remove_duplicates(Node*head){
    Node*ptr=head;
    while(ptr->next!=NULL){/*this loop will run till the next node*/
        if(ptr->data==ptr->next->data){
            /*If the current node data and the data of the next node are same then the current node i
            is connected to current->next->next and the node just next to current is freed from memory*/
            Node*temp=ptr->next;
            ptr->next=ptr->next->next;
            free(temp);
        }
        else{
            ptr=ptr->next;
        }
    }
    return head;
}

/*printing the node's data*/
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node *head = takeinput();
	
	cout<<"Linked List Before Removing Duplicates\n";
	print(head);
	head=remove_duplicates(head);
	cout<<"Linked List after Removing Duplicates\n";
	print(head);

	return 0;
}