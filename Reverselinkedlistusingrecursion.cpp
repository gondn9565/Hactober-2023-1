#include <iostream>
 
using namespace std;
 
//Declare node 
struct node{
    int num;
    node *next;
    node(int n){
        num=n;
        next=NULL;
    }
};
 
//Starting (Head) node
 
//Insert node at start
void insert_Node(struct node* &head,int n){
    struct node *new_node=new node(n);
    new_node->next=head;
    head=new_node;
}
void reverse(node* &head,node* &curr,node* &prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }
    node* forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
node* reverselinkedlist(node* &head){
    node* curr=head;
    node* prev=NULL;
    reverse(head,curr,prev);
    return head;
}




//Display all nodes
void display_all_nodes(node* head)
  {
	struct node *temp = head;
    while(temp!=NULL){
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
 
int main(){
    struct node *head=NULL;
    insert_Node(head,1);
    insert_Node(head,3);
    insert_Node(head,5);
    insert_Node(head,7);
    insert_Node(head,9);
    insert_Node(head,11);
    cout<<"Original Linked list:\n";
	display_all_nodes(head);
	cout<<"\nReverse Linked list:\n";
  reverselinkedlist(head);
    display_all_nodes(head);
    return 0;
}
