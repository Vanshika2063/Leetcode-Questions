#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};



/*This function will take the data inputs from user enter -1 to end the loop*/
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

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
/*this function is recursively calculating the length of the linked list*/
int length(Node*head){
    if(head==NULL){/*if the head is NULL it would simply return me the length as 0*/
        return 0;
    }
    return(1+length(head->next));/*else it would call it for next node and increment the current length by 1*/
}
Node *deleteNodeRec(Node *head, int pos) {
    if(head==NULL){
        return head;
    }
    if(pos==0){/*this checks that if we reached the desired node then the head at this moment is changed to 
    head=head->next and the current node is freed from memory*/
        Node*ptr=head;
        head=head->next;
        free(ptr);
        return head;/*the new head is returned in the recursive call*/
        
    }
    head->next=deleteNodeRec(head->next,pos-1);
    return head;
	//Write your code here
}

int main()
{
	
	
	Node *head = takeinput();
	int pos;
	cout<<"Enter the Nth node to be deleted from the end:\n";
	cin >> pos;
	int len=length(head)-pos;
	head = deleteNodeRec(head, len);
	cout<<"LL after deletion of node:\n";
	print(head);
	

	return 0;
}