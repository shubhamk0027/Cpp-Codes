void insertAtBottom(struct sNode** top_ref, 
                                 int item) 
{ 
    if (isEmpty(*top_ref)) 
        push(top_ref, item); 
    else
    { 
  
        // Hold all items in Function Call 
        // Stack until we reach end of the 
        // stack. When the stack becomes 
        // empty, the isEmpty(*top_ref)becomes 
        // true, the above if part is executed 
        // and the item is inserted at the bottom  
        int temp = pop(top_ref); 
        insertAtBottom(top_ref, item); 
  
        // Once the item is inserted  
        // at the bottom, push all 
        // the items held in Function  
        // Call Stack  
        push(top_ref, temp); 
    } 
} 
  
// Below is the function that  
// reverses the given stack using 
// insertAtBottom() 
void reverse(struct sNode** top_ref) 
{ 
    if (!isEmpty(*top_ref)) 
    { 
        // Hold all items in Function  
        // Call Stack until we 
        // reach end of the stack  
        int temp = pop(top_ref); 
        reverse(top_ref); 
  
        // Insert all the items (held in  
        // Function Call Stack) 
        // one by one from the bottom  
        // to top. Every item is 
        // inserted at the bottom  
        insertAtBottom(top_ref, temp); 
    } 
} 

/*Reverse Stack using recusion and
Inserting element at bottom
Basically using stack of functions :-p*/
