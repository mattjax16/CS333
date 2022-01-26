/*
-Javascript
-project 4: Task 3 showing quick in  JS.
-by Matt Bass
-2022

*/


function swap(arr, left, right){
    let temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

function partition(arr, left, right,comp) {
    //rem that left and right are pointers.
  
    let mid = arr[Math.floor((right + left) / 2)],
      i = left, //left pointer
      j = right; //right pointer
  
      while (i <= j) {

          let left_mid_comp = comp(arr[i], mid)
          while (left_mid_comp < 0) {
            i++;
              left_mid_comp = comp(arr[i], mid);
            }
          let right_mid_comp = comp(arr[j], mid)
          while (right_mid_comp > 0) {
                j--;
              right_mid_comp = comp(arr[j], mid)
            }
            if (i <= j) {
                swap(arr, i, j); //swap two elements
                i++;
                j--;
            }
        }
    return i;
}


function qsort_inplace(arr, left, right, comp){

    //if the left index is less than the right one run the function
    if(left<right){
        let index = partition(arr, left, right, comp)
        qsort_inplace(arr, left, index - 1, comp)
        qsort_inplace(arr, index+1, right, comp)
    }
}




function qsort_inplace_copy(arr, left, right, comp){

    //declare the index
    let index;
    
    // check that the arr length is greater than 1
    if(arr.length > 1){
        index = partition(arr, left, right, comp)

        //more elements on the left side
        if (left < (index - 1)) {

            qsort_inplace_copy(arr, left, index - 1, comp);
          }
      //more elements on the right side
        if (right > index+1) {
            qsort_inplace_copy(arr, index+1, right, comp);
          }

    }

    //return the array
    return arr
}



function comp_dec(a,b){
    if(a <= b)
        return 1
    else
        return -1
}

function comp_inc(a,b) {

    let swithc_var = (a <= b)
    switch (swithc_var) {
        case true:
            return -1
        // if not returning need a break statemnet so default doesnt run
        default:
            return 1
    }

}
//main test function
function main(){

    let numbers = [0, 432,23,39,5,2,100];
    let numbers2 = [0, 432,3023,332,5,2,100];
    // let numbers = [0, 432,3023,332,5,2,100];



    console.log("Number unsorded: " + numbers)
    qsort_inplace(numbers,0,numbers.length-1 ,comp_inc)
    console.log("Number sorded increasing (qsort_inplace): " +  numbers)
    // console.log("Number sorded increasing: " +  sorted_nums2)

    ///testing first qsort
    numbers = [0, 432,23,39,5,2,100];
    numbers2 = [0, 432,3023,332,5,2,100];
    let sorted_numbers = qsort_inplace_copy(numbers,0,numbers.length-1,comp_inc)
    console.log("Number sorded increasing (qsort_inplace_copy): " +  sorted_numbers)
    console.log("Numberssorded increasing(qsort_inplace_copy): " +  numbers)





    numbers = [0, 432,23,39,5,2,100]
    numbers2 = [0, 432,3023,332,5,2,100]

    qsort_inplace(numbers,0,numbers.length-1 ,comp_dec)
    console.log("Number sorded decreasing (qsort_inplace): " +  numbers)

    console.log("Number sorded decreasing (built in sort with comp dec): " +  numbers.sort(comp_dec))
    console.log("Number sorded incresing (built in sort with comp inc): " +  numbers.sort(comp_inc))
    console.log("Number sorded (built in sort no func): " +  numbers.sort())

    console.log("Number2 sorded decreasing (built in sort with comp dec): " +  numbers2.sort(comp_dec))
    console.log("Number2 sorded incresing (built in sort with comp inc): " +  numbers2.sort(comp_inc))
    console.log("Number2 sorded (built in sort no func): " +  numbers2.sort())







}

main()