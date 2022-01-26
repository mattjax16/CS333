/*
-Javascript
-project 5: Double linked list Test file
-by Matt Bass
-2022

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array

INFOR ON EXPORTS AND IMPORTS https://stackoverflow.com/questions/57492546/what-is-the-difference-between-js-and-mjs-files
*/


//Create a double linked list
const Double_LL  = require('./double_ll.js'); //how to import in node js since no standard way
// import { Double_LL } from './double_ll.js';



//initilize linked list
let ll = new Double_LL()

console.log("JS Object and poly properties")
console.log("Size of new link list: " + ll.size)

//wont work because no setter makes it so size cant be changed
ll.size=12

console.log("Size of new link list: " + ll.size)


//dont need getter or setters with properties already preated
console.log("Name of new link list: " + ll.name)
ll.name = 'First Test List'
console.log("Name of new link list: " + ll.name)

//can add properties tho if no getter specified
ll.second_name = "sec name"
console.log("Second Name of new link list: " + ll.second_name)




//////LINKED LIST FUNCTIONALITY
console.log("\n\nLinked list functionality")

//can add strings and numbers any data type because JS is dynamicl typed
ll.append(343)
ll.append('4')
ll.append(true)

ll.push(233)
ll.insert(3,499)

console.log("Size of link list: " + ll.size)

ll.printList()

ll.push(1)
ll.push(1)
ll.push(1)
ll.push(2)


console.log("Size of link list: " + ll.size)
ll.printList()


console.log(`Last item removed ${ll.remove(8)}.`);//Temperate literal vs string more found https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Template_literals
ll.printList()

console.log(`4th item removed ${ll.remove(3)}.`);
ll.printList


let num_ll = new Double_LL()

for(i = 0; i <=10; i++){
    num_ll.append(i)
}
console.log("\n\n Number testing (maping)")
num_ll.printList()

let cubed = function(x) {
    return x * x * x;
}

Double_LL.mapLL(num_ll, cubed)
console.log(`The cubed numbers ${num_ll.to_string()} `)


console.log("clearing list")
num_ll.clear()
console.log("Size of link list: " + num_ll.size)
num_ll.printList()

let built_arr = new Array()

built_arr.push(3,34,5,324,"1232")

console.log(`Built in array ${built_arr}`)



