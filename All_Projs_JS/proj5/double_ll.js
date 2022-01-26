/*
-Javascript
-project 5: Double linked list
-by Matt Bass
-2022

Classes are prototypes of classes
classes can be shown



MORE INFO: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes
*/


let single_node = class{
    //constructor is example of prototype method
    constructor(data = null){
        this.data = data;
        this.next = null;
    }
}

//double node class
class double_node extends single_node{

    //constructor is example of prototype method
    constructor(data = null){
        super(data)
        this.prev = null;
    }
}

//linked list class

 class Double_LL {

     constructor() {
         this.head = null;
         this.tail = this.head;
         this.name = null

         //could make size but will use static method instead
         // this.size = 0
     }

     //gets the size of the list
     get size() {

         let size = 0;

         let curr_node = this.head;
         while (curr_node != null) {
             size++
             curr_node = curr_node.next
         }
         return size
     }

     // adds an element at the end
     // of list
     append(data) {

         let new_node = new double_node(data)

         //if the list is empty
         if (!this.head) {
             this.head = new_node
             this.tail = this.head
         } else {
             this.tail.next = new_node;
             new_node.previous = this.tail;
             this.tail = new_node;
         }


     }

     printList() {
         let array = [];
         let currentList = this.head;
         while (currentList != null) {
             array.push(currentList.data);
             currentList = currentList.next;
         }

         console.log(array.join(' , '));
     }

     to_string() {
         let array = [];
         let currentList = this.head;
         while (currentList !== null) {
             array.push(currentList.data);
             currentList = currentList.next;
         }

         return array.join(',');
     }

     // Insert node at the start of the list
     push(data) {
         let new_node = new double_node(data);

         new_node.next = this.head;
         this.head.previous = new_node;
         this.head = new_node;

     }

     // Insert node at a given index
     insert(index, data) {
         if (!Number.isInteger(index) || index < 0 || index > this.size ) {
             console.log(`Invalid index. Current length is ${this.size}.`); //cool way to do f string
             return this;
         }

         // If index is 0, prepend
         if (index == 0) {
             this.push(data);
             return this;
         }

         // If index is equal to this.length, append
         if (index == this.size) {
             this.append(data);
             return this
         }

         // Reach the node at that index
         let new_node = new double_node(data);
         let prev_node = this.head;

         for (let k = 0; k < index - 1; k++) {
             prev_node = prev_node.next;
         }

         let next_node = prev_node.next;

         new_node.next = next_node;
         prev_node.next = new_node;
         new_node.previous = prev_node;
         next_node.previous = new_node;

     }

     //removes node from start of list
     pop(){
         if(!this.head){
             console.log('Error list is empty')
         }
         let ret_data = this.head.data

         this.head = this.head.next;


         this.head.previous = null;
         return ret_data
     }

     //removes node from end of list
     deque(){
         if(!this.head){
             console.log('Error list is empty')
         }
         let ret_data = this.tail.data

         this.tail = this.tail.previous;


         this.tail.next = null;
         return ret_data
     }

     // Remove a node
     remove(index) {
         if (!Number.isInteger(index) || index < 0 || index > this.size-1) {
             console.log(`Invalid index. Current length is ${this.size}.`);
             return;
         }

         // Remove head
         if (index === 0) {

             return this.pop();
         }

         // Remove tail
         if (index === this.size - 1) {

             return this.deque();
         }

         // Remove node at an index
         let prev_node = this.head;

         for (let k = 0; k < index - 1; k++) {
             prev_node = prev_node.next;
         }
         let delete_node = prev_node.next;
         let next_node = delete_node.next;

         prev_node.next = next_node;
         next_node.previous = prev_node;


         return delete_node.data;
     }

     clear(){this.head = null;
         this.tail = this.head;
         this.name = null}


     //example of static function with mapping
     static mapLL(ll,func){

         if(!ll.head){
             console.log('Error list is empty')
         }

         ll.head.data = func(ll.head.data)

         let curr_node = ll.head
         while (curr_node.next){
             curr_node = curr_node.next
             curr_node.data = func(curr_node.data)
         }

     }
 }


 module.exports = Double_LL