//
//  binary_searches.swift
//  P3_swift
//
//  Created by Matthew Bass on 12/1/21.
//

import Foundation


func binarySearchIterOneFuncGeneric(arr: Array<Any>, target: Any, mid_method: String) {
    // Itterative Binary search in swift using a loop
    // and all the different methods for finding the mid point are used
    
    var min = 0
    var max = arr.count - 1
    
    // Initilize the middle variable
    var mid : Int
    
    switch mid_method {
    case "bitshift":
        mid = max - min >> 1
        
    case "round":
        mid = max - min >> 1
        
    case "floor":
        mid = Int((max - min)/2)
    
    case "Int":
        mid = Int((max - min)/2)
    
    // default will b fastest with bitshifr
    default:
        mid = max - min >> 1
    }
    
    
    
    
}




//function to test binary search one function
func testBinarySearchIterOneFuncGeneric(arr_size : Int, target : Int, mid_method : String){
    
    let currentDateTime = Date()
    
    var ordered_int_arr = createOrderedArrayInt(arr_size: arr_size)
    
    
    print("It took \(Date().timeIntervalSinceReferenceDate) for the Itterative Binary search to run with the mid method \(mid_method)")
    
    
}




func createOrderedArrayInt(arr_size : Int) ->[Int]{
    
    var ordered_int_arr = Array<Int>()
    ordered_int_arr.reserveCapacity(arr_size)
    for i in 0 ... arr_size-1 {
        ordered_int_arr[i] = i
    }
    return ordered_int_arr
}












// A function to test how arrays grow
//func testArrayGrowth(let arr_size : Int){
func testArrayGrowth(arr_size : Int){
   
    var test_arr = Array<Int>()

    
//     testing strings
    //    var test_string = "test"
//    print(test_string.count)
    
    print("The Count of the Array is \(test_arr.count) and the Capacity of the Array is \(test_arr.capacity)")
    
    
    for i in 1 ... arr_size {
        test_arr += [i]
        print("The Count of the Array is \(test_arr.count) and the Capacity of the Array is \(test_arr.capacity)")
    }

    
}

// to use control statements need to be in function
func mainTest(){


    // declaring constant variables for forming the arrays
    // notice how i did t nwwd to decalre the type this is
    // because since i assigned a value to the variable right when
    // it was declared Swift can use Type Inference to infer the
    // type when compiling the code
    let array_sizes = 100
    let target = 2


    // Long way to make an int array (any array)
    // The colon is not necessary but can be used after
    // a variable to strictly define the type of the variable
    var test_array_1 : Array<Int> = Array<Int>()


    // Long hand way without the semi colon and a generic array
    var test_array_2  = Array<Any>()


    // This is the short hand way to make an integer array
    var test_array_3 : [Int] = []


    // This is the short hand way to make a generic array
    // short hand for declaring data type
    var test_array_4 : [Any] = []
        
        
        
        // initilizing using array intilization syntax in Swift
    var test_array_5 = Array(repeating: 1, count: array_sizes)

        
    for var i in 0 ... array_sizes {
        test_array_1.append(i)
        test_array_2[i] = i
        test_array_3.append(i)
        test_array_4[i] = i
        
        // Multiplying values of test array 5
        test_array_5[i] = test_array_5[i] * i
    }
        
        print(test_array_1)
        
        print(test_array_1.capacity, test_array_1.count)
        
        print(test_array_2)
        print(test_array_2.capacity,test_array_2.count)
    
}

