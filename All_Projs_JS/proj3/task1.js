/*
-Javascript
-project 3: Task 1 showing sytaxx of JS assighnments.
-by Matt Bass
-Sept 2021
*/

// https://stackoverflow.com/questions/1470488/what-is-the-purpose-of-the-var-keyword-and-when-should-i-use-it-or-omit-it

/*n JavaScript, all functions, classes, and variables need unique names to identify themselves. These unique names are called identifiers. JavaScript identifiers are case-sensitive, which means x and X are two different variables. The JavaScript identifiers cannot begin with a digit, contain no special symbols other than the dollar sign and underscore, and cannot be JavaScript keywords. Besides, JavaScript is a dynamically typed language, which means the variables defined with keyword var can switch to other data types when reassigned values or redeclared.

To declare a variable in JavaScript, three different keywords can be used. They are let , var , and const . Variables defined with let cannot be redeclared, while variables declared using var can be redeclared. Variables defined with const cannot be redeclared nor reassigned value. And they must be assigned a value when declared with const . However, variables declared using both let and var can be reassigned values. 
*/

/// DECLARING VARIABLES ////

/// Multiple ways to declare variables in JS

/*1. No decleration

You can declare
*/

π = Math.PI; // Global
console.log('π when not used with decalitor: ' + π) // this is really a string

// showing the types that result when adding different types
console.log('Type of string + π: ' + typeof('hhj'+ π))
console.log("Type of π + string: " + typeof(π + '12'))
// π;
// π = Math.PI; // this would not work

/*2. Var

This is considered the old way for declaring variables in JS

*/

var π
π = "3.14 something" // Global (notice how π can be reassighned)
console.log('π when not used var with decalitor: ' + π) 

var π = "cant be bothered";

console.log('π when not used var with decalitor changed : ' + π) 


/*3. Let

This is considered the more moderen way for declaring variables in JS that
can change value

*/

let foo\u200Cbar$dgi; // interesting the \ messes up some ide's (like vscode) too tips
                      // but not when it is compiled
foo\u200Cbar$dgi = 30; // can be named strange things with \ and $ (even emojis)

console.log("let foo\\u200Cbar$dgi = " + foo\u200Cbar$dgi );

// let foo\u200Cbar$dgi = 20;//will not work

foo\u200Cbar$dgi = 20 // This will work tho 
console.log("let foo\\u200Cbar$dgi = " + foo\u200Cbar$dgi );

//This will also work because JS is case sensitive:
let Foo\u200Cbar$dgi = "see it is case sensitive!!!";
console.log("let Foo\\u200Cbar$dgi = " + Foo\u200Cbar$dgi );


/*4. const

This is considered the more moderen way for declaring variables in JS that
can not change value

*/

// const \u006C\u006F\u006C\u0077\u0061\u0074;// will not work
// Throws error: SyntaxError: Missing initializer in const declaration
const \u006C\u006F\u006C\u0077\u0061\u0074 = 'some Url';

console.log("const \\u006C\\u006F\\u006C\\u0077\\u0061\\u0074 = " + \u006C\u006F\u006C\u0077\u0061\u0074 +'\n\n\n');

//\u006C\u006F\u006C\u0077\u0061\u0074 = 'another url'// This will not work
// will throw: TypeError: Assignment to constant variable.




/// Var vs Let vs Const part 2 

/*
As I have discuste earlier Var Let and Const can be initilized before
a value is declared (In fact they are all) this is known as
Hoisting (a JavaScript mechanism where variables and function declarations 
    are moved to the top of their scope before code execution. ).
*/
var t_var_1;
let t_let_1;
// const t_const_1; unlike a const which needs to be defined at declaration

console.log('t_var_1 (global) (unassighned) :  ' + t_var_1)
console.log('t_let_1 (global) (unassighned) :  ' + t_let_1)


//// Variable scope


/* JavaScript has three types of scope: block scope, function scope, and global scope. 
Variables defined with let and const have block scope, which means that these variables 
cannot be accessed outside of the block (Much like python and in my opinion is why it is prefered today),
 while variables defined with var cannot have block scope. Each function in JavaScript creates a new scope, 
since variables defined inside a function cannot be accessed outside of the function.
Variables defined with all three keywords inside a function have function scope,
and there is not a big difference with the choice of keyword in this case.
Similarly, variables defined with all three keywords have global scope when declared outside blocks and functions.
*/



const t_const_1 = "global const 1"
t_var_1 = "global var 1"
t_let_1 ="global let 1"

console.log('t_const_1 (global all) (outside all):  ' + t_const_1)
console.log('t_var_1 (global all) (outside all):  ' + t_var_1)
console.log('t_let_1 (global (func only)) (outside all):  ' + t_let_1)


///Difference in function vs block scoping (speciffical var vs let)

//this is considered a block
if(2 >1)
{
    console.log('\n\nEntering if(2>1) block scope')

    //the global variables can be used within the functin because they are in the scope
    // AS LONG AS THE FUNCTIONS INITILIZING THEM ARE NOT ADDED (except for var)
    console.log('\n\tt_var_1 (global all) (in if(2>1) block scope):  ' + t_var_1)
    // console.log('t_let_1 (global all) (in if(2>1) block scope):  ' + t_let_1) 
    // console.log('t_const_1 (global all) (in if(2>1) block scope):  ' + t_const_1)


    //first difference of let and var is see that 
    var t_var_1 = "if block var 1"
    let t_let_1 ="if block let 1"
    const t_const_1 = "if block const 1"
    console.log('\n\tt_var_1 (global all) (in if(2>1) block scope):  ' + t_var_1)
    console.log('\tt_let_1 (block scope) (in if(2>1) block scope):  ' + t_let_1)
    console.log('\tt_const_1 (block scope) (in if(2>1) block scope):  ' + t_const_1)

    
    
    
    //making different variables in block scope
    // const t_const_1 = "global const 1"
    var t_var_2 = "if block var 2"
    let t_let_2 = "if block let 2"
    let t_const_2 = "if block const 2"

    console.log('\n\tt_var_2 (block scope) (in if(2>1) block scope):  ' + t_var_2);
    console.log('\tt_let_2 (block scope) (in if(2>1) block scope):  ' + t_let_2);
    console.log('\tt_const_2 (block scope) (in if(2>1) block scope):  ' + t_const_2);




}

console.log('\n\nOutside all function and block scope again');
console.log('\tt_const_1 (global all) (outside all):  ' + t_const_1)
console.log('\tt_var_1 (global all) (outside all):  ' + t_var_1)// This one will be changed to if block let 1 bc var is acting as global
// this is why let is prefered over var in many cases to make sure you arent 
// changing data you dont mean to.
console.log('\tt_let_1 (global all) (outside all):  ' + t_let_1)


/// Looking at the variables produced in the if block

// var will work because var is function scoped
console.log('\n\tt_var_2 (global all) (outside all):  ' + t_var_2);
// let const wont work because they are block scoped
// console.log('\tt_let_2 (global all) (outside all):  ' + t_let_2);
// console.log('\tt_const_2 (global all) (outside all):  ' + t_const_2);



function func_scope(){

    console.log('\n\nEntering fun_scope()')

    //the global variables can be used within the functin because they are in the scope
    // console.log('\n\tt_const_1 (global) (in func_scope()):  ' + t_const_1)
    // console.log('\tt_var_1 (global) (in func_scope()):  ' + t_var_1)
    // console.log(']tt_let_1 (global) (in func_scope()):  ' + t_let_1)


}



func_scope()




console.log('\n\n\ndone with task 1 proj 3')
