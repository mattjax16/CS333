/*
-Javascript
-project 3: Scopping
-by Matt Bass
-Sept 2021

This is a file to test out the scoping of variables
in javascript
*/

var var1 = "Global Var1"

function  testScopeVar(){
    var var1 = "Local Var1 Test1"
    console.log(var1)
}

function  testScopeLet(){
    let var1 = "Local Var1 Test2"
    let var2 = "Local Var2 Test2"
    console.log(var1)
}

testScopeVar()
testScopeLet()
console.log(var1)
console.log(var2)

