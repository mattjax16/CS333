/*
-Javascript
-project 3: Task 3 showing Primative data of JS.
-by Matt Bass
-2022
*/

/**
 * Resources:
 *          https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures
 */
 
/* 
In JavaScript, users do not have to define the type of variable on their own. 
Instead, JS will do the job. It will also automatically convert the types if necessary.
This is what it means when it is said that JS is a dynamicaly typed languege.
*/

/// Primative data types ////
/*All primitives are immutable, i.e., they cannot be altered. 
It is important not to confuse a primitive itself with a variable assigned a primitive value. 
The variable may be reassigned a new value, but the existing value can not be changed in the ways 
that objects, arrays, and functions can be altered. 


Syntax:

primatite data types for the most part (except for symbols,null, and undefinded) can be created 
created with either with a call to their type ie Number(3) or their short hand ie 3

*/
console.log("\nJS Primative Data Types:")

// 1. null
/*
null is not only a value but also a built-in type in JavaScript.
*/

let n = null;

console.log("\n\t(null) n = " + n)
console.log("\t(null) typeof(n) = " + typeof(n)) // interestinging how it shows type of object
// console.log("\t(null) n.valueOf() = " + n.valueOf())
console.log("\t(null) n + 32 = " + (n+32) + "(null is treated as 0)") //notice how it operates in the parentheses first
console.log("\t(null) However n == 0 = " + (n == 0) + " , But n == null = " + (n == null)) 

// 2. undefined
/*
null is not only a value but also a built-in type in JavaScript.
*/

let u;

console.log("\n\t(undefined) u = " + u)
console.log("\t(undefined) typeof(u) = " + typeof(u)) 
console.log("\t(undefined) u + 32 = " + (u+32) + " (NaN stands for not a number but is a data type of " 
            + typeof((u+32)) + ')') // returns NaN

// console.log("\t(undefined) u.valueOf() = " + u.valueOf()) wont work 
// TypeError: Cannot read properties of undefined (reading 'valueOf')



// 3. Boolean
/*
All info found here: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Boolean
*/

let b_T = true;
let b_F = false;

console.log("\n\t(Boolean) b_T = " + b_T)
console.log("\t(Boolean) b_F = " + b_F)
console.log("\t(Boolean) typeof(b_T) = " + typeof(b_T)) 
console.log("\t(Boolean) typeof(b_F) = " + typeof(b_F)) 
console.log("\t(Boolean) b_T.valueOf() = " + b_T.valueOf() + " ")//(.valueOf() is what == uses to compare this is why n == 0 is 
                                                                // false but n == null is true)

console.log("\t(Boolean) b_F.valueOf() = " + b_F.valueOf())

console.log("\t(Boolean) b_T+8 = " + (b_T+8) + " (true is treated as 1 with numbers)") 
console.log("\t(Boolean) b_F+8 = " + (b_F+8) + " (false is treated as 0 with numbers)") 
console.log("\t(Boolean) b_T == 1 = " + (b_T == 1) + " ( shows == checks only value)") 
console.log("\t(Boolean) b_F == 0 = " + (b_F == 0) + " ( shows == checks only value)")
console.log("\t(Boolean) b_T === 1 = " + (b_T === 1) + " ( shows === checks value and data type)") 
console.log("\t(Boolean) b_F === 0 = " + (b_F === 0) + " ( shows === checks value and data type)")
console.log("\t(Boolean) b_T === true = " + (b_T === true) + " ( shows === checks value and data type)") 
console.log("\t(Boolean) b_F === false = " + (b_F === false) + " ( shows == checks only value and data type)") 


//////SHOW STEPHANIE
// let b_f_tt = new Boolean('false')
// console.log("\n\t(Boolean) b_f_tt = " + b_f_tt)




// 4. Number type
/*
The Number type is a double-precision 64-bit binary format IEEE 754 value (numbers between -(2^53 − 1) 
and 2^53 − 1). In addition to representing floating-point numbers, the number type 
has three symbolic values: +Infinity, -Infinity, and NaN ("Not a Number").

More info here: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#number_type
*/

let num_1 =  Number(12)
let num_2 = 12324
let num_float =  1.23242112
let inf = +Infinity

console.log("\n\t(number) inf = " + inf)
console.log("\t(number) typeof(inf) = " + typeof(inf)) 
console.log("\t(number) inf.valueOf() = " + inf.valueOf()) 

console.log("\n\t(number) num_1 = " + num_1)
console.log("\t(number) typeof(num_1) = " + typeof(num_1)) 
console.log("\t(number) num_1.valueOf() = " + num_1.valueOf()) 

console.log("\n\t(number) num_2 = " + num_2)
console.log("\t(number) typeof(num_2) = " + typeof(num_2)) 
console.log("\t(number) num_2.valueOf() = " + num_2.valueOf()) 

console.log("\n\t(number) num_float = " + num_float)
console.log("\t(number) typeof(num_float) = " + typeof(num_float)) 
console.log("\t(number) num_float.valueOf() = " + num_float.valueOf()) 



// 5. BigInt
/*
The BigInt type is a numeric primitive in JavaScript that can represent integers with arbitrary precision. 
With BigInts, you can safely store and operate on large integers even beyond the safe integer limit for Numbers.
A BigInt is created by appending n to the end of an integer or by calling the constructor.



More info here: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#bigint_type
*/

let big_1 =  BigInt(12)
let big_2 = 12324n

let big_3= 12n



console.log("\n\t(BigInt) big_1 = " + big_1)
console.log("\t(BigInt) typeof(big_1) = " + typeof(big_1)) 
console.log("\t(BigInt) big_1.valueOf() = " + big_1.valueOf()) 

console.log("\n\t(BigInt) big_2 = " + big_2)
console.log("\t(BigInt) typeof(big_2) = " + typeof(big_2)) 
console.log("\t(BigInt) big_2.valueOf() = " + big_2.valueOf()) 


console.log("\n\t(BigInt) big_3 = " + big_3)
console.log("\t(BigInt) typeof(big_3) = " + typeof(big_3)) 
console.log("\t(BigInt) big_3.valueOf() = " + big_3.valueOf())



//comparators
console.log("\tComparators big_1 == num_1 = " + (big_1== num_1))
console.log("\tComparators big_2 === num_2 = " + (big_2 === num_2))


/**You can obtain the largest safe value that can be incremented with Numbers by using the 
 * constant Number.MAX_SAFE_INTEGER. With the introduction of BigInts, 
 * you can operate with numbers beyond the Number.MAX_SAFE_INTEGER. */
//  let big_4= Number.MAX_SAFE_INTEGER *10n 
//  console.log("\n\t(BigInt) big_4 = " + big_4)
// console.log("\t(BigInt) typeof(big_4) = " + typeof(big_4)) 
// console.log("\t(BigInt) big_4.valueOf() = " + big_4.valueOf())

/// wont work because big ints and only be operated on with themselves.



// 6. String
/*
JavaScript's String type is used to represent textual data. It is a set of "elements" of 16-bit unsigned integer values. 
Each element in the String occupies a position in the String. The first element is at index 0, the next at index 1, and so on. 
The length of a String is the number of elements in it.

Unlike some programming languages (such as C), JavaScript strings are immutable. 
This means that once a string is created, it is not possible to modify it.

However, it is still possible to create another string based on an operation on the original string. For example:

A substring of the original by picking individual letters or using String.substr().
A concatenation of two strings using the concatenation operator (+) or String.concat().


More info here: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#string_type
*/


let str_1 = "string 1"
console.log("\n\t(String Primative) str_1 = " + str_1)
console.log("\t(String Primative) typeof(str_1) = " + typeof(str_1)) 
console.log("\t(String Primative) str_1.valueOf() = " + str_1.valueOf()) 

str_1 = "new string 1"
console.log("\n\t(String Primative) str_1 = " + str_1)
console.log("\t(String Primative) typeof(str_1) = " + typeof(str_1)) 
console.log("\t(String Primative) str_1.valueOf() = " + str_1.valueOf()) 

let str_2 = new String("string 2")
console.log("\n\t(String Object) str_2 = " + str_2)
console.log("\t(String Object) typeof(str_2) = " + typeof(str_2)) 
console.log("\t(String Object) str_2.valueOf() = " + str_2.valueOf()) 

console.log("\t(String Primative) str_1.slice(0,9) = " + str_1.slice(10,200)) //wraps primative with string object code
                                                                            // when using . notation
console.log("\t(String Object)  str_2.slice(0,9) = " + str_2.slice(4,200)) 



// 7. String
/*
A value having the data type Symbol can be referred to as a "Symbol value". In a JavaScript runtime environment, 
a symbol value is created by invoking the function Symbol, which dynamically produces an anonymous,
 unique value. A symbol may be used as an object property.

Symbol can have an optional description, but for debugging purposes only.


!!!!!! Main purpose of sybol is to act as a unique object description

More info here: https://developer.mozilla.org/en-US/docs/Glossary/Symbol
*/

let symb1 = Symbol("symb1")
let symb2 = Symbol("symb2")
let symb3 = Symbol()
let symb4 = Symbol("symb1")

// console.log("\n\t(Symbol) symb1 = " + symb1) // This wont work have to use toString with symbol
console.log("\n\t(Symbol) symb1 = " + symb1.toString())
console.log("\t(Symbol) typeof(symb1) = " + typeof(symb1)) 
console.log("\n\t(Symbol) symb2 = " + symb2.toString())
console.log("\t(Symbol) typeof(symb2) = " + typeof(symb2)) 
console.log("\n\t(Symbol) symb3 = " + symb3.toString())
console.log("\t(Symbol) typeof(symb3) = " + typeof(symb3)) 
console.log("\t(Symbol) symb1 === symb4 " + (symb1 === symb4))





/// Object data types ////

/**
 * The other kind of data types in JS other than primative data types are objects
 * 
 * 
 * In JavaScript, objects can be seen as a collection of properties. 
 * With the object literal syntax, a limited set of properties are initialized; 
 * then properties can be added and removed. 
 * 
 * Property values can be values of any type, including other objects, which enables building complex data structures. 
 * 
 * Properties are identified using key values. A key value is either a String value or a Symbol value.
 * 
 * 
 * More Info Here: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#objects
 * 
 * 
 * Normal Objects and Functions 
 * 
 * A JavaScript object is a mapping between keys and values. Keys are strings (or Symbols), and values can be anything. 
 * This makes objects a natural fit for hashmaps.
 * 
 * 
 * Functions are regular objects with the additional capability of being callable.
 * 
 */
