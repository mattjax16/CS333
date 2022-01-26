/*Write a "hello world" type of program for each language.
Do something more interesting than printing hello world
(i.e. don't just copy and paste a hello world example and do something more than print text).
A snapshot of your program and its outputs are the second section of the wiki page.*/

/*
-Javascript
-project 2: Helloworld
-by Matt Bass
-Sept 2021
*/

function msg1() {
    alert("This is a serious Hello World >:|");
    }

function msg2(){
    alert("This is a happy Hello World :)");
}

function submitMe(value) {
    alert(value);
}


// //second version: using node.js

// // Loading the http module from node.js
// //  requred is a built in function from n.js
// //  like import in python kinda
// const http = require('http');


// const hostname = '127.0.0.1';
// const port = 3000;

// const server = http.createServer((req, res) => {
//     res.statusCode = 200;
//     res.setHeader('Content-Type', 'text/plain');
//     res.end('(using node js)This is a neutral Hello World :|\n');
// });

// server.listen(port, hostname, () => {
// console.log('Server running at http://${hostname}:${port}/^');
// });
    