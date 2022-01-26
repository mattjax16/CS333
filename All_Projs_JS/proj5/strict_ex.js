/*
-Javascript
-project 5: Example to show what 'use strict' does
-by Matt Bass
-2022

 Strict mode simplifies how variable names map to particular variable definitions in the code.
 Many compiler optimizations rely on the ability to say that variable X is stored in that location:
  this is critical to fully optimizing JavaScript code. JavaScript sometimes makes this basic mapping of
   name to variable definition in the code impossible to perform until runtime. Strict mode removes most
   cases where this happens, so the compiler can better optimize strict mode code.

MORE INFO: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode
*/



x = 17

console.log("x = " + x)

function strict_var(args){
    'use strict'

    //y = 12 // gives error ReferenceError: y is not defined
    // let y = 0122 gives error SyntaxError: Octal literals are not allowed in strict mode.
    let y = 12
    console.log("y = " + y)

    // let x = 3.14;
    // delete x; error Delete of an unqualified identifier in strict mode.



    let cobj = {
        prop1:1,
        prop2:2
    }
    console.log(cobj.prop1)
    delete cobj.prop1
    console.log(cobj.prop1)



}

strict_var(2323,232)