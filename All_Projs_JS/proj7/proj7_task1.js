/*
-Javascript
-project 7: task 1 memory manegmaent
-by Matt Bass
-2022

MORE INFO: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Memory_Management


https://blog.alexdevero.com/memory-life-cycle-heap-stack-javascript/


TIMING INFO: https://stackoverflow.com/questions/313893/how-to-measure-time-taken-by-a-function-to-execute
*/


/*
ALLOCATION:
--In order to not bother the programmer with allocations, JavaScript does it alongside with declaring values.
*/

// These are primative varibles stored on the stack
var mallocNumber =  1; // allocates memory for a number
var mallocString = 'a'; // allocates memory for a string


var mallocString2 = mallocString.substr(0, 2); // mallocString2 is a new string

// objects stored on the heap

/*
HEAP:
The second place where JavaScript can store data is memory heap.
This storage is more dynamic. When it comes to memory heap, JavaScript doesn’t allocate fixed amount of memory.
Instead, it allocates memory as needed at the moment.
This type of memory allocation is called “dynamic memory allocation”.


 */
string = 'hi'
var mallocObject = {
        a: 1,
        b: string}; // allocates memory for an object and contained values


var mallocArray = [1, null, 'abra']; // allocates memory for the array and contained values
var mallocArray2 = [3, 5]
var mallocArray3 = mallocArray.concat(mallocArray2); // the concatenation of the two arrays' elements

function mallocFunc(funcParameter) {
    return funcParameter + 1;
} // allocates a function (which is a callable object)




/* DEALLOCATION:
--Garbage collection
The main notion garbage collection algorithms rely on is the notion of reference.
An object is said to reference another object if the former has an access to the latter.
In this context, the notion of "object" is extended to something broader than regular JavaScript objects
and also contains function scopes. */

var newPointer = mallocObject.a;
mallocObject = mallocNumber; // the oringinal mallocObject can be garbage-collected when assigning to new value
// however, since it's a value is referenced by the newPointer, it will not be freed




/*
CIRCULAR REFERENCE PROBLEM

In following situation x references y, and y references x.
According to reference-counting algorithm, the local variable x and y cannot be garbage collected.
This will cause the memory leak. Thus, in 2012, all modern browser changed the garbage collection
from reference-routing to mark and sweep. This algorithm reduces the definition of "an object is no longer needed"
to "an object is unreachable" globally, which could handle the circular reference.
 */

function circ_ref(){
    let x = { }
    let y = { }

    x.a = y
    y.a = x

    return("done")
}
circ_ref()