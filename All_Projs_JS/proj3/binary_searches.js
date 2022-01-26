/*
-Javascript
-project 3: Binary Searches
-by Matt Bass
-Sept 2021
*/



function binarySearchItterativeBitShift(arr, target){
    /*
    Iterative binary search function. Requres array to be pre sorted
    This puts all the methods of finding the mid into one function

    This is the seperate bitshift itterative function to see function start up time
    */
    let min = 0
    let max = arr.length - 1

    while(min <= max){

        //initilizse the mid variable
        let mid = (max + min) >> 1

        // If element is present at mid, return True
        if (arr[mid]==target){
            return true;
        }
        // Else look in left or right half accordingly
        else if (arr[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return false

}

function binarySearchItterativeRound(arr, target){
    /*
    Iterative binary search function. Requres array to be pre sorted
    This puts all the methods of finding the mid into one function

    This is the seperate round itterative function to see function start up time
    */
    let min = 0
    let max = arr.length - 1

    while(min <= max){

        //initilizse the mid variable
        let mid = Math.round((max + min) / 2)

        // If element is present at mid, return True
        if (arr[mid]==target){
            return true;
        }
        // Else look in left or right half accordingly
        else if (arr[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return false
}

function binarySearchItterativeFloor(arr, target){
    /*
    Iterative binary search function. Requres array to be pre sorted
    This puts all the methods of finding the mid into one function

    This is the seperate floor itterative function to see function start up time
    */
    let min = 0
    let max = arr.length - 1

    while(min <= max){

        //initilizse the mid variable
        let mid = Math.floor((max + min) / 2)

        // If element is present at mid, return True
        if (arr[mid]==target){
            return true;
        }
        // Else look in left or right half accordingly
        else if (arr[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return false
}





function binarySearchItterativeOneFunc(arr, target, mid_method){
    /*
    Iterative binary search function. Requres array to be pre sorted
    This puts all the methods of finding the mid into one function

    There are seperate functions for this two that are being used to test the first
    start up time of a function in node js
    */
    
    let min = 0
    let max = arr.length - 1


    while(min <= max){
        
        //initilizse the mid variable
        let mid

        // get the middle index
        switch(mid_method){
            
            // case bitshift should be a bit quicker
            case "bitshift":
                mid = (max + min) >> 1
                break
            
            case "floor":
                mid = Math.floor((max + min) / 2)
                break

            case "ceiling":
                mid = Math.ceil((max + min) / 2)
                break

            case "round":
                mid = Math.round((max + min) / 2)
                break

            // default slower method round
            default:
                mid = Math.round((max + min) / 2)
        }


         // If element is present at mid, return True
         if (arr[mid]==target){
             return true;
         }
         // Else look in left or right half accordingly
         else if (arr[mid] < target)
              min = mid + 1;
         else
              max = mid - 1;
    }
    return false

}

function createdOrderedArray(size){

    let ordered_array = []
    for(let i = 0; i <= size; i++){
        ordered_array.push(i)
    }
    return ordered_array
}


function testBinarySearchIterBitshift(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with bitshift
    console.time("Binary Search Itterative Bitshift")
    let test_res_bitshift = binary_search(arr,target,"bitshift")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Itterative Bitshift")
}

function testBinarySearchIterRound(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with bitshift
    console.time("Binary Search Itterative Round")
    let test_res_bitshift = binary_search(arr,target,"round")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Itterative Round")
}


function testBinarySearchIterFloor(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with bitshift
    console.time("Binary Search Itterative Floor")
    let test_res_bitshift = binary_search(arr,target,"floor")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Itterative Floor")
}


function testBinarySearchIterCeil(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with Ceiling
    console.time("Binary Search Itterative Ceiling")
    let test_res_bitshift = binary_search(arr,target,"ceiling")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Itterative Ceiling")
}



function weirdRunTimes(){

    let test_arr_1 = []
    let test_arr_2 = []
    let test_arr_3 = []

    let target_1 = 1
    let target_2 = 2
    let target_3 = 3

    const size = 10000

    for(let i = 0; i <= size; i++){
        test_arr_1.push(i)
        test_arr_2.push(i+1)
        test_arr_3.push(i+2)
    }

    // testing the binary search with bitshift
    console.time("Binary Search Itterative Bitshift")
    let test_res_bitshift = binary_search(test_arr_1,target_1,"bitshift")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Itterative Bitshift")

    // testing the binary search with Ceiling
    console.time("Binary Search Itterative Ceiling")
    let test_res_ceiling = binary_search(test_arr_2,target_2,"ceiling")

    console.log(test_res_ceiling)
    console.timeEnd("Binary Search Itterative Ceiling")

    // testing the binary search with Ceiling
    console.time("Binary Search Itterative Rounding")
    let test_res_rounding = binary_search(test_arr_3,target_3,"rounding")

    console.log(test_res_rounding)
    console.timeEnd("Binary Search Itterative Rounding")

}



function seperateRunTimes(){
    let test_arr_1 = []
    let test_arr_2 = []
    let test_arr_3 = []

    let target_1 = 1
    let target_2 = 2
    let target_3 = 3

    const size = 10000

    for(let i = 0; i <= size; i++){
        test_arr_1.push(i)
        test_arr_2.push(i+1)
        test_arr_3.push(i+2)
    }

    // testing the binary search with bitshift
    console.time("Seperate Binary Search Itterative Bitshift")
    let test_res_bitshift = binarySearchItterativeBitShift(test_arr_1,target_1)

    console.log(test_res_bitshift)
    console.timeEnd("Seperate Binary Search Itterative Bitshift")

    // testing the binary search with Ceiling
    console.time("Seperate Binary Search Itterative Floor")
    let test_res_ceiling = binarySearchItterativeFloor(test_arr_2,target_2)

    console.log(test_res_ceiling)
    console.timeEnd("Seperate Binary Search Itterative Floor")

    // testing the binary search with Ceiling
    console.time("Seperate Binary Search Itterative Rounding")
    let test_res_rounding = binarySearchItterativeRound(test_arr_3,target_3)

    console.log(test_res_rounding)
    console.timeEnd("Seperate Binary Search Itterative Rounding")

}


////// Recursive Binary Searches
function binarySearchRecursiveOneFunc(arr, target, mid_method,min ,max){
    /*
    Iterative binary search function. Requres array to be pre sorted
    This puts all the methods of finding the mid into one function

    There are seperate functions for this two that are being used to test the first
    start up time of a function in node js
    */

        //base condition
    if (min > max) return false

    else{

        //initilizse the mid variable
        let mid

        // get the middle index
        switch(mid_method){

            // case bitshift should be a bit quicker
            case "bitshift":
                mid = (max + min) >> 1
                break

            case "floor":
                mid = Math.floor((max + min) / 2)
                break

            case "ceiling":
                mid = Math.ceil((max + min) / 2)
                break

            case "round":
                mid = Math.round((max + min) / 2)
                break

            // default slower method round
            default:
                mid = Math.round((max + min) / 2)
        }


        // If element is present at mid, return True
        if (arr[mid]==target){
            return true
        }
        // Else look in left or right half accordingly
        else if (arr[mid] < target)
           return binarySearchRecursiveOneFunc(arr,target,mid_method,mid+1,max)
        else
           return binarySearchRecursiveOneFunc(arr,target,mid_method,min,mid-1)
    }

}


function testBinarySearchRecBitshift(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with bitshift
    console.time("Binary Search Recursive Bitshift")
    let test_res_bitshift = binarySearchRecursiveOneFunc(arr,target,"bitshift")

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Recursive Bitshift")
}

function testBinarySearchRecRound(arr_size, target){

    //make array
    let arr = createdOrderedArray(arr_size)

    // testing the binary search with bitshift
    console.time("Binary Search Recursive Round")
    let test_res_round = binarySearchRecursiveOneFunc(arr,target,"round")

    console.log(test_res_round)
    console.timeEnd("Binary Search Recursive Round")
}


function testRecRunTimes(){
    let test_arr_1 = []
    let test_arr_2 = []
    // let test_arr_3 = []

    let target_1 = 1
    let target_2 = 2
    // let target_3 = 3

    const size = 100000

    for(let i = 0; i <= size; i++){
        test_arr_1.push(i)
        test_arr_2.push(i+1)
        // test_arr_3.push(i+2)
    }

    // testing the binary search with bitshift
    console.time("Binary Search Recursive Bitshift")
    let test_res_bitshift = binarySearchRecursiveOneFunc(test_arr_1,target_1,"bitshift",0,size)

    console.log(test_res_bitshift)
    console.timeEnd("Binary Search Recursive Bitshift")

    // testing the binary search with Ceiling
    console.time("Binary Search Recursive Rounding")
    let test_res_rounding = binarySearchRecursiveOneFunc(test_arr_2,target_2,"rounding",0,size)

    console.log(test_res_rounding)
    console.timeEnd("Binary Search Recursive Rounding")

}







testRecRunTimes()