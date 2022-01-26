/*
-Javascript
-project 7: task 2 garbage  collecting timing (seeing when a sweep takes place)
-by Matt Bass
-2022

MORE INFO: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Memory_Management


https://blog.alexdevero.com/memory-life-cycle-heap-stack-javascript/


TIMING INFO: https://stackoverflow.com/questions/313893/how-to-measure-time-taken-by-a-function-to-execute
*/


// //importing the module to write a csv file to handle the timings,
// const fs = require('fs')
// const Console = require("console");
//
// //importing modulte to do math/
const math = require('mathjs')

function create_delete(){

    for(let i = 0; i<100; i++){
        //creating a variable then deleting it
        let a = 10
        delete a// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/delete
        // console.log(a) //shows delete does nothing
    }
}

function test_1(){

    for(let i = 0; i<=10000; i++){

        // const t0 = performance.now();
        Console.time(`Round ${i+1} took `)
        create_delete()
        Console.timeEnd(`Round ${i+1} took `)
        // const t1 = performance.now();

        // let total_time = t1 - t0
        //
        // let avg_time = total_time/100
        //
        // console.log(`Round ${i+1} avg time: ${avg_time}`)
    }
}



function garbage_detect(){
    let arr = []
    let N = 100000

    //create the large array
    for(let i = 0; i<N;i++){
        arr.push(i)
    }

    //clearing the memory by setting the array to null
    arr = null
}


function garbage_detect_random(){
    let arr = []
    let N = 1000000

    //create the large array
    for(let i = 0; i<N;i++){
        arr.push(math.random().toFixed(20))
    }

    //clearing the memory by setting the array to null
    arr = null
}


function time_math_random(){
    for(let i = 0; i < 10000; i++){
        const t0 = performance.now();
        let a = math.random().toFixed(20)
        const t1 = performance.now();
        let total_time = t1 - t0

        console.log(`Round ${i+1} time: ${total_time}`)

    }

}

function main_test_time(){

    let N = 10000
    for(let i = 0; i < N; i++){
        Console.time(`Round ${i+1} took`)
        garbage_detect()
        Console.timeEnd(`Round ${i+1} took`)
    }
}


function main_test_preformance(){

    console.log(`Time to run in ms,`)

    let N = 10000
    for(let i = 0; i < N; i++){
        const t0 = performance.now();
        garbage_detect()
        const t1 = performance.now();
        let total_time = t1 - t0
        // console.log(`Round ${i+1} avg time: ${total_time} ms`)
        console.log(`${total_time},`)
    }
}




function main_garbage_detect(){


    let N = 100000
    let time_arr = []
    for(let i = 0; i < (N+1000); i++){

        const t0 = performance.now();
        garbage_detect()
        const t1 = performance.now();
        let total_time = t1 - t0


        time_arr.push(total_time)
        // for the first 1000 rounds get data to make the standard deviation
        if(i>=1000){
            let time_std = math.std(time_arr)
            let time_avg = math.mean(time_arr)

            if(total_time >= time_avg+(time_std*2)){
                console.log(`Garbage collection at round ${i+1}`)
            }
        }

    }
}

main_garbage_detect()