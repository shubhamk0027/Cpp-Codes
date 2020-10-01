#include <iostream> 
using namespace std; 
  
// Structure for a Singly Linked List 
struct node { 
    char data; 
    node* next; 
}; 
  
// Function to add a new node to the Linked List 
node* add(char data) 
{ 
    node* newnode = new node; 
    newnode->data = data; 
    newnode->next = NULL; 
    return newnode; 
} 
  
// Function to convert the string to Linked List. 
node* string_to_SLL(string text, node* head) 
{ 
    head = add(text[0]); 
    node* curr = head; 
  
    // curr pointer points to the current node 
    // where the insertion should take place 
    for (int i = 1; i < text.size(); i++) { 
        curr->next = add(text[i]); 
        curr = curr->next; 
    } 
    return head; 
} 
  
// Function to print the data present in all the nodes 
void print(node* head) 
{ 
    node* curr = head; 
    while (curr != NULL) { 
        cout << curr->data << " -> "; 
        curr = curr->next; 
    } 
} 
  
// Driver code 
int main() 
{ 
  
    string text = "GEEKS"; 
  
    node* head = NULL; 
    head = string_to_SLL(text, head); 
  
    print(head); 
    return 0; 
} 
