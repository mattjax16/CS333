/*
-Javascript
-project 5: Word Counter
-by Matt Bass
-2022

MORE INFO On File reader object: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes

MORE INFO READING FILES: https://web.dev/read-files/
                        https://nodejs.dev/learn/reading-files-with-nodejs
*/

//importing the fs module to read and write files
const fs = require('fs')


//Class for the word counter
class WordCounter{

    constructor(filepath = null) {
        this.filepath = filepath;
        //make a new map not objeect ({})
        this.word_map = new Map()
        this.total_wc = 0;
    }

    //runs the word counter on the current file path
    run_counter(){
        try{
            let data = fs.readFileSync(this.filepath, 'utf8')



            //prep all the words by spliting the entire document string
            let words = data.toString().toLowerCase().replace(/[^\w\s]|_/g, '').split(/\s+/)



            //for each loop
            // DONT DO THIS WAY BECAUSE OF WAY OBJECTS VS MAPS ARE
            //DO not set objects like this does not interact with the map in the proper way
            // MORE info click the link below (But that way of setting a property does not interact
            // with the Map data structure. It uses the feature of the generic object.)
            // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map#setting_object_properties
            /// THIS IS THE WRONG WAY (THIS IS SETTING OBJECT PROPERTY NOT MAP PROPERTY)
            // words.forEach((word)=>{
            //
            //     if(!this.word_map[word]){
            //
            //         this.word_map[word] = 0;
            //     }
            //     this.word_map[word] += 1
            //     this.total_wc += 1
            //     })

            words.forEach((word)=>{

                if(!this.word_map.has(word)){

                    this.word_map.set(word,0);
                    // this.word_map.set(word) =  {count:0};
                }
                // let update = this.word_map.get(word).count + 1
                let update = this.word_map.get(word) + 1
                // console.log(`update: ${update}`);
                this.word_map.set(word,update);
                this.total_wc += 1
            })
        }
        catch (err){
            throw err
        }
    }



    //runs the word counter on the current file path
    run_counter_func_Broken(){


        //read in the file (=> makes a function)
        //SOED NOT WORK WITH ANONOMOUS FUNCTION
        fs.readFileSync(this.filepath, 'utf8',  (err, data) => {

            //if an error throw an error
            if(err){
                // console.log("Error")
                throw err;
            }

            //prep all the words by spliting the entire document string
            //replace any character that is not a word or space globaly in the docuent
            // then split it based on the spaces
            let words = data.toString().toLowerCase().replace(/[^\w\s]|_/g, '').split(/\s+/)



            //for each loop
            // DONT DO THIS WAY BECAUSE OF WAY OBJECTS VS MAPS ARE
            //DO not set objects like this does not interact with the map in the proper way
            // MORE info click the link below (But that way of setting a property does not interact
            // with the Map data structure. It uses the feature of the generic object.)
            // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map#setting_object_properties
            /// THIS IS THE WRONG WAY (THIS IS SETTING OBJECT PROPERTY NOT MAP PROPERTY)
            // words.forEach((word)=>{
            //
            //     if(!this.word_map[word]){
            //
            //         this.word_map[word] = 0;
            //     }
            //     this.word_map[word] += 1
            //     this.total_wc += 1
            //     })

            words.forEach((word)=>{

                if(!this.word_map.has(word)){

                    this.word_map.set(word,0);
                    // this.word_map.set(word) =  {count:0};
                }
                // let update = this.word_map.get(word).count + 1
                let update = this.word_map.get(word) + 1
                // console.log(`update: ${update}`);
                this.word_map.set(word,update);
                this.total_wc += 1
            })
        })

        // console.log("done with wc")
    }

    //function to return a sorted array of the word count
    sort_by_count(){

        // The Array.from() static method creates a new, shallow-copied Array
        // instance from an array-like or iterable object.
        // More info:
        let sortedWC = Array.from(this.word_map, ([word, count]) => ({ word, count }));


        sortedWC.sort((a,b) =>{
            return b.count - a.count
        })

        return sortedWC
    }


    print_top_wc(top){
        let top_wc = this.sort_by_count()

        console.log("The top words are:")
        for(let i = 0; i < top; i++){
            console.log(`${i+1}. Word: ${top_wc[i].word}  Count: ${top_wc[i].count}`)
        }
    }
}




function count_files(){
    //Get files from files argument
    // let files_element = document.getElementById('files')
    // let files = document.getElementById('files').value
    let files = "/Users/matthewbass/Documents/School_Colby/Colby/CS333/Project06/C/tasks/src/wctest.txt"

    let word_counter_array = []

    //to do multiple files
    // for(i = 0; i<files.length -1; i++){
    //
    //     let wc = new WordCounter(files[i])
    //
    //     wc.run_counter()
    // }


    let wc = new WordCounter(files)

    //run the word counter
    wc.run_counter()

    wc.print_top_wc(20)
}



count_files()
