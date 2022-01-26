/*
-Javascript
-project 3: Task 3 showing functions in  JS.
-by Matt Bass
-2022



More info: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Functions


*/


// all functions have an assighnments object

function Sum(){
    if(arguments[0].length <=0){
        console.log("Error sum needs arguments")
        return
    }

    let sum = 0
    for(let i = 0; i < arguments[0].length-1;i++){
        
        sum += arguments[0][i]
    }
    return sum
}

function map(f, a) {
    let result = []; // Create a new Array
    let i; // Declare variable
    for (i = 0; i != a.length; i++) // different way to write for loop
      result[i] = f(a[i]);
    return result;
  }
  
  const cubed = function(x) {
     return x * x * x;
  }
  let numbers = [0, 1, 2, 5, 10];
  let cubed_numbers = map(cubed,numbers);
  let summed_numbers = Sum(numbers);
  console.log(numbers + " cubed = " + cubed_numbers);
  console.log(numbers + " summed = " +summed_numbers);

  