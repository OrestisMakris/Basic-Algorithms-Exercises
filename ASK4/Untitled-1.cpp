#include <iostream>
using namespace std;

struct Node
{
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;        // create new "node" struct and a pointer named head
void put(int newdata)        //the function "put" creates a new node and stores the new number
{
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));  //Allocates a "node" structure size block of memory, returning a pointer to the beginning of the block.
   (*newnode).data = newdata;
   (*newnode).prev = NULL;
   (*newnode).next = head;
   if(head != NULL)
   (*head).prev = newnode ;
   head = newnode;
}
void print()           // displays the list
{
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL)
   {
      cout<< (*ptr).data <<" ";
      ptr = (*ptr).next;
   }
   cout<<"\n ";
}

 void swap(int n1){  

    Node *prevNode1 = NULL, *node = head, *temp1 = NULL , *temp2 = NULL; 
      
    //Checks if list is empty  
    if(head == NULL) {  
        return;  
    }  
          
    //Search for node1  
    while(node != NULL && node->data!= n1){  
        prevNode1 = node; 
        node = node->next;  

    } 

    temp1 = (*node).next ;
    temp2 = (*node).prev ;

    (*node).next = (*((*node).next).next; 
    (*node).prev = (*((*node).prev).prev;
    (*((*node).next).next = temp1 ;
    (*((*node).prev).prev = temp2;

}  

int main() {
   put(17);
   put(62);
   put(5);
   put(34);
   put(22);
   put(46);
   cout<<"The stored numbers  in the linked list are\n ";
   print();
   int x;
 cout << "Give the number you want to find";
 cin >> x;
   swap(x);
   print();
   return 0;
}