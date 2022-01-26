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
z

Data types for the most part (except for symbols,null, and undefinded) can be created 
created with either with a call to theit type ie Number(3) or their short hand ie 3

*/



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



//Literal way to create Object

//objects can be made as consts and have their variables changes




const sandwich_starter = {

    bread : "wheat",
    cheese : "american",
    meat : "turkey",
    veggies : "lettuce",
    price : 8.67,
    // to_string_broken : console.log("a sandwich on " + this.bread +
    // " with " + this.meat + " ," + this.cheese + " ," + "and " + this.veggies + " and comes out to $" + this.price),

    to_string_working : function(){return "a  starter sandwich on " + this.bread +
    " with " + this.meat + " ," + this.cheese + " ," + "and " + this.veggies + " and comes out to $" + this.price}
};



// console.log( "\n\n" + sandwich_starter.to_string_broken)
console.log( "\n\n" + sandwich_starter.to_string_working())



//wantts to chang bread
sandwich_starter.bread = "white"
console.log( "\n\n" + sandwich_starter.to_string_working())




//// Another way to create objects a bit tider

let medieum_sandwich = new Object();

medieum_sandwich.bread = "rye"
medieum_sandwich.cheese = "swiss"
medieum_sandwich.meat = ["ham", " salami"]
medieum_sandwich.veggies = ["lettuce", "onions"]
medieum_sandwich.price = 10.12


medieum_sandwich.get_veggies_str = function(){ 

    let veggies_str = ""
    for(let i = 0; i < medieum_sandwich.veggies.length;i++){
        veggies_str += (" ," + medieum_sandwich.veggies[i])
    }
    return veggies_str
 };

 medieum_sandwich.get_meats_str = function(){ 

    let meats_str = ""
    for(let i = 0; i < medieum_sandwich.meat.length;i++){
        meats_str += (" ," + medieum_sandwich.meat[i])
    }
    return meats_str
 };


 medieum_sandwich.to_str = function(){ return "a sandwich on " + medieum_sandwich.bread +
 " with " + medieum_sandwich.get_meats_str()  + ", "+ this.cheese + " ," + "and " + medieum_sandwich.get_veggies_str() + " and comes out to $" + this.price
 };




console.log( "\n\n" + medieum_sandwich.to_str())




/// other ways to creat objects 
const object1 = Object.create({});

Object.defineProperty(object1, 'property1', {
  value: 42,
  writable: true
});

object1.property1 = 77;
// throws an error in strict mode

console.log(object1.property1);
// expected output: 42


///More info here https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/defineProperty
