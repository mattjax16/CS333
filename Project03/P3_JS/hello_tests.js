/*Write a "hello world" type of program for each language.
Do something more interesting than printing hello world
(i.e. don't just copy and paste a hello world example and do something more than print text).
A snapshot of your program and its outputs are the second section of the wiki page.*/

/*
-Javascript
-project 3: Hello tests
-by Matt Bass
-Sept 2021
*/



var global_hello = "global hello😄"

function hello(){

    var local_hello = "local hello"
    console.log("hello")
    console.log(global_hello)
    console.log(local_hello)
    console.log("notice ; doesn't need to be used")
}

hello()