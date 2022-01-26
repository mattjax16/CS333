//
// Created by Matthew Bass on 11/17/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"


//creates a new LinkedList struct, initializes it, and returns it
LinkedList* ll_create(){
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->size = 0;
    return ll;
}

//adds a node to the front of the list, storing the given data in the node.
void ll_push(LinkedList *l, void *data){
    
    // making the temp node to be added
    Node* temp = (Node*)malloc(sizeof(Node));
    
    //making the temp nodes data
    temp->data = data;
    temp->next = l->head;
    temp->prev = NULL;
    
    
    //updating the previous head node if it is there
    if(l->head != NULL){
        l->head->prev = temp;
    }

    //updating the head to the temp node
    l->head = temp;

    //increment the  of the size of the list by one
    l->size++;
}

//removes the node at the front of the list and returns the associated data.
void* ll_pop(LinkedList *l){

//    see if the linked list is empty
    if (l->head == NULL) {
        return NULL;
    }

//   else make a temp pointer for data and node
    else {

        //get the data from the head
        void* data = l->head->data;

         l->head = l->head->next;

        //preventing a memory link
        free(l->head->prev);
        //make the heads previous node null
        l->head->prev = NULL;

        //decrement the size of the lisr
        l->size--;

        return data;
    }
}

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data){


    Node* curr = l->head;
    Node* temp = (Node*)malloc(sizeof(Node));
    
    // if the list is empty
    if(l->head == NULL) {

        //setting up the temp node to be added
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        //making the temp node thd head
        l->head = temp;

        //incrementing the size by 1
        l->size++;





    
    //if the list is not empty
    } else {
        while (curr -> next != NULL) {

            curr = curr -> next;
        }
        
        //making the temp nodes data
        temp->data = data;
        temp->next = NULL;
        temp->prev = curr;

        //updating the last node
        curr->next = temp;

        //incrementing the size by 1
        l->size++;


    }
}



//adds a node to the postion of the list specified, 
//storing the given data in the node.
void ll_insert(LinkedList* l, void* data, int index){



    //if wanted at the front of the list
    if(index == 0){
        ll_push(l, data);
    }
    
    // if it is wanted to be added at the end of the list
    else if (index == (ll_size(l)-1))
    {
        ll_append(l, data);
    }

    // if the value is not inserted in a correct postion
    else if (index > (ll_size(l)-1) || index<0)
    {
        printf("\nError index %d is an invalid index for list of size %d!!!!\n", index,ll_size(l));
        return;
    }

    //Else add the node in the index specified
    else{
        Node* curr = l -> head;
        Node* temp = (Node*)malloc(sizeof(Node));
        
        // linearly traverse to selected index
        for(int i = 0; i<(index-1); i++){
            
            curr = curr->next;
        }

        //set up new node
        temp->data = data;
        temp->next = curr->next;
        temp->prev = curr;

        //connect the previous node
        curr->next->prev = temp;

        //take care of node before
        curr->next = temp;
    }
}
    
    





//removes the first node in the list whose data matches target given the comparison function.
// The function returns the pointer to the data.
void* ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
    Node* curr_node = l -> head;
    if(!curr_node) {
        return NULL;
    }

    //int flag to see if it is head
    int pos = -1;

    while (curr_node != NULL) {
        pos++;
        //if the target matches
        if (compfunc(target, curr_node->data)==0){
            

            
            //update attachments of the node
            //if there was an attachment to this node after

            if(curr_node->next){
                curr_node->next->prev = curr_node->prev;

            }
            //if there was an attachment to this node after
            if(curr_node->prev){
                curr_node->prev->next = curr_node->next;

            }

            //if it was the head node
            if(pos == 0){
                l->head = curr_node->next;
            }

            free(curr_node);

            //decrement the size
            l->size--;
            
            return curr_node->data;
        }
        curr_node = curr_node -> next;
    }
    return NULL;
}




/* checks to see if the list already contains a node with value field equal to target 
    if target is returns the index of the first occurence if it does
    if target does not it returns -1
*/
int ll_contains(LinkedList *l, void* target, int (*compfunc)(void*, void*)) {

    Node *temp = l->head;

    int index = -1;
    while (temp != NULL) {

        //increment the index by one
        index++;

        if (compfunc(target, temp->data)==0) {

            return index;
        }
        temp = temp->next;
    }
    //if target is not found in list

    return -1;
}


//updates a node (index) currently in the linked list.
void ll_update(LinkedList *l, void *data, int index){

    //checking that the index is valid
    if(index<0 || index > (ll_size(l)-1))
        printf("\nError index %d is an invalid index for list of size %d!!!!\n", index,ll_size(l));
    //Else update the node in the index specified
    else{
        Node* curr = l -> head;

        // linearly traverse to selected index
        for(int i = 0; i<index; i++){

            curr = curr->next;
        }

        //free the data to prevent a memory leak
        free(curr->data);

        //replace the nodes data
        curr->data = data;
    }
}

//returns the size of the list.
int ll_size(LinkedList *l){
    int size = 0;
    Node* temp = l->head;
    while (temp->next != NULL) {
        size += 1;
        temp = temp->next;
    }
    size += 1;
    return size;
}

//removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    void (*fun_ptr)(void*) = freefunc;
    Node* temp = l->head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        fun_ptr(temp);
        temp = next;
    }
    l->head = NULL;
}

//traverses the list and applies the given function to the data at each node.
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    Node* temp = l->head;
    void (*fun_ptr)(void*) = mapfunc;

    //changing this to debug
    while (temp != NULL) {
        void* data = temp -> data;
        fun_ptr(data);
        temp = temp->next;
    }
//        for (int i = 0; i < l->size; i++) {
//            void* data = temp -> data;
//            fun_ptr(data);
//            temp = temp->next;
//    }
}




/////////////////////
// Functions for list
/////////////////////



///
///Printing Functions
///

// function that prints an integer
void printInt(void *i) {
	int *a = (int *)i;

	printf("value: %d\n", *a);
}

// function that prints a char
void printChar(void *i) {
    char *a = (char *)i;

    printf("value: %c\n", *a);
}


// function that prints a str
void printStr(void *i) {
    char *a = (char *)i;

    printf("value: %s\n",a);

}


///
///Compare Functions
///


// function that compares two integers and returns 0 if they are equal
// -1 if the first int is of lower value than the second
// 1 if the other way around
int compInt(void *i, void *j) {
	int *a = (int *)i;
	int *b = (int *)j;

	if(*a == *b){
        return 0;
    }
    else if (*a < *b){
        return -1;
    }
    else{
        return 1;
    }

}


// function that compares two strings and returns 0 if they are equal 
// < 0 if the first string is of lower value than the second
// > 0 if the other way around 
// refer to https://www.cplusplus.com/reference/cstring/strcmp/
int compStr(void *a, void *b) {
    char *strA = (char*)a;
	char *strB = (char*)b;
    int ret = strcmp(strA, strB);

	return ret;
}


///
///More List Manipulation Functions
///

/* splits the linkedlist into a linked list of lists
 * Creates a new linked list */
LinkedList* ll_Split(LinkedList *l){

    //create the 2 new link lists needed
    LinkedList *split_lists, *half_list;
    split_lists = ll_create();
    half_list = ll_create();

    //get the head of the original list
    Node* curr = l->head;

    //base case if the size is 0 or 1
    // return the list
    if(l->size == 0 ||l->size == 1){
        return l;
    }

    //else if the list is of even size split it evenly
    else if(l->size%2 == 0){

        //get to the halfway node
        for(int i = -1; i <= l->size/2; i++){
            curr = curr->next;
        }


        //split the links
        curr->prev->next = NULL;
        curr->prev = NULL;

        //add curr to the new list

        ll_push(half_list,curr);

        //set the size of the half list and original list
        half_list->size=l->size/2;
        l->size=l->size/2;

        //add them to the splitlist and return them
        ll_push(split_lists,half_list);
        ll_push(split_lists,l);

        return split_lists;
    }
        //else if the list is of odd size split it so the firt list has one more
    else if(l->size%2 == 1){

        //get to the halfway node
        for(int i = -1; i <= l->size/2+1; i++){
            curr = curr->next;
        }


        //split the links
        curr->prev->next = NULL;
        curr->prev = NULL;

        //add curr to the new list

        ll_push(half_list,curr);

        //set the size of the half list and original list
        half_list->size=l->size/2+1;
        l->size=l->size/2;

        //add them to the splitlist and return them
        ll_push(split_lists,half_list);
        ll_push(split_lists,l);

        return split_lists;
    }
}



/////
/////Sorting Functions
/////
//
//
///* sorts the linkedlist based on  the compFunc */
//void ll_mergeSort(LinkedList *l, int (*compfunc)(void*, void*)){
//
//    //create the 2 new link list pointers needed
//    LinkedList *split_lists, *half_list;
//
//    split_lists = ll_Split(l);
//
//
//}




