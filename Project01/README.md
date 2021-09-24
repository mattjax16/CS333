# CS333 - Project 1 README
## Matthew Bass
## 09/03/2021

---

### Project Layout:

     Project1
            ├── C
            │   ├── exts
            │   │   ├── ext1.c
            │   │   ├── ext2.c
            │   │   ├── ext3.c
            │   │   ├── ext4.c
            │   │   └── ext5.c
            │   └── tasks
            │       ├── task1.c
            │       ├── task2.c
            │       ├── task3.c
            │       ├── task4.c
            │       └── task5.c
            └── README.md
    
---
<br>

### Run and build configuration for C:
    macOS Big Sur 11.3.1 - Apple clang version 12.0.5 (clang-1205.0.22.9)
---
<br>

### C:  
    Task 1.
        This task is to learn about how variables
        and different data types are stored in
        memory in C
        
        File: C/tasks/task1.c

        Compile: gcc -o C/bin/task1 C/tasks/task1.c

        Run: ./C/bin/task1

        Output:
            Char, Byte  0: 0F
            Unsigned Char, Byte  0: 10
            Short Int, Byte  0: 00
            Short Int, Byte  1: 01
            Int, Byte  0: 02
            Int, Byte  1: 00
            Int, Byte  2: 00
            Int, Byte  3: 10
            Long Int, Byte  0: 99
            Long Int, Byte  1: 00
            Long Int, Byte  2: 00
            Long Int, Byte  3: 00
            Long Int, Byte  4: 00
            Long Int, Byte  5: 00
            Long Int, Byte  6: 10
            Long Int, Byte  7: 00
            Float, Byte 0: 00
            Float, Byte 1: 00
            Float, Byte 2: 80
            Float, Byte 3: 41
            Double, Byte  0: 00
            Double, Byte  1: 00
            Double, Byte  2: 00
            Double, Byte  3: 00
            Double, Byte  4: 00
            Double, Byte  5: 00
            Double, Byte  6: 30
            Double, Byte  7: C0
        
        Observations:
            There are many observations I can make from this output first off the output of each variable matches as expected.

            Char: 
                output: Char, Byte  0: 0F

                This is ecpected becase in C a char is only one byte in size and in my code I assigned it the value 15 which is hexidecimal 0F
            

            Unsigned Char:
                output: Unsigned Char, Byte  0: 10
                
                Again it is expected for there to only be one byte and here the hexideciaml code is 10 because I assigned the value of 16 to that variable
            

            Short Int:
                output: Short Int, Byte  0: 00
                        Short Int, Byte  1: 01
                
                Here there are 2 bytes output because in C a short int is 2 bytes. Since a short int is one byte larger than a char or unsigned char I assigned a bigger nummerical value of 256 to the variable hence why the first byte it 00 and the second byte is 01 creating the hexidecimal number 0100 which is 256 when converted to base 10. Also sinco 01 is stored in the second byte of the short int I can tell that my apple M1 chip stores short ints with little-endian encoding, with the most significant byte being stored last (because the whole hex number is 0100)


            Int:
                output: Int, Byte  0: 02
                        Int, Byte  1: 00
                        Int, Byte  2: 00
                        Int, Byte  3: 10
                
                Here there are 4 bytes output because in C an int is 4 bytes. Since an int is larger than a short int or unsigned char I assigned a bigger nummerical value of 268435458 to the variable hence why the first byte it 02 the second and third bytes are 00 and the fourth and final byte is 10 creating the hexidecimal number 10000002 which is 268435458 when converted to base 10. From this since 10 is stored in the last byte of the int I can tell that my apple M1 chip stores ints with little-endian encoding, with the most significant byte being stored last and least significant first.


            Long Int:
                output: Long Int, Byte  0: 99
                        Long Int, Byte  1: 00
                        Long Int, Byte  2: 00
                        Long Int, Byte  3: 00
                        Long Int, Byte  4: 00
                        Long Int, Byte  5: 00
                        Long Int, Byte  6: 10
                        Long Int, Byte  7: 00
                
                Here there are 8 bytes output because in C a long int is 8 bytes  in size. Since an int is larger than an int I assigned a bigger nummerical value of 4503599627370649 to the variable. Again it is apparent that a long int is stored in little-endian encoding because the hexvalue of 4503599627370649 is 0010000000000099 so again the most significant bit 00 is store last in the eight bit.

            
            Float:
                output: Float, Byte 0: 00
                        Float, Byte 1: 00
                        Float, Byte 2: 80
                        Float, Byte 3: 41
                
                For a float as expected their are 4 bytes because that is the size of a float data type in C. Also again it is stored in little-endian encodiang because the most significant hex values of 41 are stored last. In particular 4 comes out to 0100 with 0 being the sign bit showing that the number is positive.

            Double:
                output: Double, Byte  0: 00
                        Double, Byte  1: 00
                        Double, Byte  2: 00
                        Double, Byte  3: 00
                        Double, Byte  4: 00
                        Double, Byte  5: 00
                        Double, Byte  6: 30
                        Double, Byte  7: C0
                
                For a Double as expected their are 8 bytes because that is the size of a double data type in C allowing for 53(52 stored) significant percision bits, 11 exponent bits and 1 sign bit. Also again it is stored in little-endian encodiang because the most significant hex values of C0 are stored last since I assighned the variable the value of -16. In particular C comes out to 1100 with 1 being the sign bit showing that the number is negetive.
    


    Task 2. 
        This task assign a pointer to itself and
        have it loop contiuosly through the computer's memory
        
        File: C/tasks/task2.c

        Compile: gcc -o C/bin/task2 C/tasks/task2.c

        Run: ./C/bin/task2

        Output: It runs through all the bits until it ends with this output at the 2014th byte (byte 2013)

            ...
            Ptr, Byte 2088: 6F
            Ptr, Byte 2089: 72
            Ptr, Byte 2090: 74
            Ptr, Byte 2091: 3D
            Ptr, Byte 2092: 00
            Ptr, Byte 2093: 00
            Ptr, Byte 2094: 00
            Ptr, Byte 2095: 00
            Ptr, Byte 2096: 00
            Ptr, Byte 2097: 00
            Ptr, Byte 2098: 00
            Ptr, Byte 2099: 00
            Ptr, Byte 2100: 00
            Ptr, Byte 2101: 00
            Ptr, Byte 2102: 00
            Ptr, Byte 2103: 00
            zsh: segmentation fault  ./task2 

        Observations:

            From here I can see that the pinter goes throught 2104 bytes of memory in my computer (which I would have though it would have gone through more than that as I haeve gb of memory on my machine) until the program ends with a segmentation fault error. This is because I have run out of memory assigned to the program (this is going through the stack memory)

    Task 3.

        This task was to write a program that repeatedly allocates a small amount of memory in a loop that goes on for a long time using a single variable which is bad practice and observe
        what happens.

        File: C/tasks/task3.c

        Compile: gcc -o C/bin/task3 C/tasks/task3.c

        Run: ./C/bin/task3

        Output:  Again It runs through all the bits until the loop ends at how ever many bites i said
        which is 90000000

            ...
            Byte 89999997
            Byte 89999998
            Byte 89999999

        Observations:

            From here I can see that I have created a memory leak in my program because the the terminal ends up taking up about 2.74 gb of ram in my activity monitor and the loop that is printing out what byte it is on is never terminated. This is because I use the command malloc to allocate memory to that heap int pointer. It is not untill I free the variable b (the heap pointer with the line "free(b)"). This frees the memory from its allocation and allows the momry ussage of the program (as seen in the activity monitor) decrease. Here I am going through the heap memory (all the memory of the computer) so that is why I can loop through a lot more bytes and why it uses up much more memory. (word alighnment)
    

    Task 4.

        This task was to write a program created a struct with 3-4 variables including a char and
        short type and make sure that the struct has an odd number of bits. I then used an usigned char to print out each bit of the struct and see how it is layed out in memory.

        File: C/tasks/task4.c

        Compile: gcc -o C/bin/task4 C/tasks/task4.c

        Run: ./C/bin/task4

        Output:
            This size of the Struct is 28
            Q4Struct1, Byte 0: 13
            Q4Struct1, Byte 1: 00
            Q4Struct1, Byte 2: 00
            Q4Struct1, Byte 3: 00
            Q4Struct1, Byte 4: B8
            Q4Struct1, Byte 5: 1E
            Q4Struct1, Byte 6: 65
            Q4Struct1, Byte 7: 40
            Q4Struct1, Byte 8: 4A
            Q4Struct1, Byte 9: 6F
            Q4Struct1, Byte 10: 65
            Q4Struct1, Byte 11: 20
            Q4Struct1, Byte 12: 4D
            Q4Struct1, Byte 13: 6F
            Q4Struct1, Byte 14: 6F
            Q4Struct1, Byte 15: 72
            Q4Struct1, Byte 16: 65
            Q4Struct1, Byte 17: 00
            Q4Struct1, Byte 18: 00
            Q4Struct1, Byte 19: 00
            Q4Struct1, Byte 20: 00
            Q4Struct1, Byte 21: 00
            Q4Struct1, Byte 22: 00
            Q4Struct1, Byte 23: 00
            Q4Struct1, Byte 24: 00
            Q4Struct1, Byte 25: 00
            Q4Struct1, Byte 26: 01
            Q4Struct1, Byte 27: 00

        Observations:

            First off what is different than expected is that when printing out the size of the struct it is saying it is 28 and 28 bytes are printed out even though with my calculations 2 short int (size of 2 bytes each) one float (4 bytes) and a char array of size 17 should have given me a struct with an odd size of 25. This however can be explained by the pading that is done to structs in my compiler to give each struch a size divisible by 4 because that is the word size of my CPU. Going through the output the short int of the age being 19 represented in hex by 13 is in the first byte but because a short int is only 2 bytes long it is padded with another 2 empty bytes until we reach the bytes representing the fload for the gpa of 3.58 with the hexidecimal value of 40651EB8 represented by bytes 4-7 (a float is 4 bytes large as mentioned earlier) The strinf starts at the next bit and goes from bytes 8-24 and the name joe more is represented by the hexcode 4a 6f 65 20 4d 6f 6f 72 65 in bytes 8-16 with 00 representing null space in the rest of the array. Byte 25 is another padding for the short int in bytes 26-27 with byte 26 being 01 representing 1 for the name_overflow short variable.


    Task 5.

        This task was to write a program created a struct with 3-4 variables including a char and
        short type and make sure that the struct has an odd number of bits. The same as task 4 but this time I am also asked to add a string to the struct using strcpy that is to big for the char array in the struct and see what happens. This is described as "hacked" in the project IE meaning the null space in the string char array as well as possibly other data in the struct contained in memory after the char arry is overwritten if the string added to the struct is to large.

        File: C/tasks/task5.c

        Compile: gcc -o C/bin/task5 C/tasks/task5.c

        Run: ./C/bin/task5

        Output:
            This size of the Struct is 28
            Q5Struct1, Byte 0: 4A
            Q5Struct1, Byte 1: 6F
            Q5Struct1, Byte 2: 65
            Q5Struct1, Byte 3: 20
            Q5Struct1, Byte 4: 4D
            Q5Struct1, Byte 5: 6F
            Q5Struct1, Byte 6: 6F
            Q5Struct1, Byte 7: 72
            Q5Struct1, Byte 8: 65
            Q5Struct1, Byte 9: 20
            Q5Struct1, Byte 10: 41
            Q5Struct1, Byte 11: 64
            Q5Struct1, Byte 12: 61
            Q5Struct1, Byte 13: 6D
            Q5Struct1, Byte 14: 20
            Q5Struct1, Byte 15: 32
            Q5Struct1, Byte 16: 00
            Q5Struct1, Byte 17: 00
            Q5Struct1, Byte 18: 13
            Q5Struct1, Byte 19: 00

            Safe!!!
            Q5Struct1, Byte 20: B8
            Q5Struct1, Byte 21: 1E
            Q5Struct1, Byte 22: 65
            Q5Struct1, Byte 23: 40
            Q5Struct1, Byte 24: 00
            Q5Struct1, Byte 25: 00
            Q5Struct1, Byte 26: 00
            Q5Struct1, Byte 27: 00
            zsh: trace trap  ./task5

        Observations:

            Again it priints out the struct this time saying it is safe when the 24th byte is 00 representing the null space that is supose to end the char array. So for the first struct I amde the string safe to it prints out safe but due to how my compiler is on my cpu when I try and use the struct with the unsafe string that is to long it throw an error "trace trap  ./task5"

---
<br>

### Javascript(JS):
    
    Description/Overview:
        Javascript , also know as JS, first officialy appeared in December of 1995 (with it originally being know as LiveScript when it shiped with the Navigator beta in september of that year). The creation of this language came form the desirve of NetScape to add a scripting language to their web-browser called "Navigator". At first NetScape tried collaborate with Sun Microsystems to embed java to their browser while at the same time also employing the help of Brendan Eich to try and embed Scheme into the browser. Both these attempts at a solution failed though so NetScape asked Brendan Eich to instead develop a new language (as well as interpreter for the language) that had synac more similar to that of Java instead of Scheme. (Eich claims that HyperTalk syntax and handler names influenced JS). Also while sharing similar names Javascript shares no relationship with Java the only reason that Javascript is called that is because Java was the hot language at the time so the naming was used as a sort of marketing ploy by the creaters of Javascript, Netscape. Javascript the name itself is a trade mark of Oracle but the programing langueage itself is "open sourced"(I would say it is an open standard) This open-standard is conforms to the ECMAScript which according to wikipedia is "is a general-purpose programming language, standardised by Ecma International according to the document ECMA-262. It is a JavaScript standard meant to ensure the interoperability of web pages across different web browsers.[2] ECMAScript is commonly used for client-side scripting on the World Wide Web, and it is increasingly being used for writing server applications and services using Node.js." (https://en.wikipedia.org/wiki/ECMAScript). This makes sense because Javascript as mentioned earlier was desighned to be a programing language to be run with web browsing software and it surley has achived its goal of adding more functionality and connectivity to the internet because as of now JS is used as a client side (meaning it is compiled locally on the users machine and not on the backend of the website on some servers) programming language for 97.6% of websites on the internet and basicly every web browser today has a dedicated javascript engine. Overall Javascript is a high-level, often just in time compiled multi-paradgim language. "It has curly-bracket syntax, dynamic typing, prototype-based object-orientation, and first-class functions."(https://en.wikipedia.org/wiki/JavaScript#Trademark). It also supports event-driven(meaning that certain responses are solicited based on user input, interaction with other programs, and or sensors), functional, and imperative programming styles. One of the biggest traits of Javascript is the DOM or Document Object Model which is "a cross-platform and language-independent interface that treats an XML or HTML document as a tree structure wherein each node is an object representing a part of the document"(https://en.wikipedia.org/wiki/Document_Object_Model) and its principle standardization was handeled by the World Wide Web Consortium. Other properties of JS is that it ahs similar syntax to C.((e.g., if statements, while loops, switch statements, do while loops, etc.). Javascript is also said to be weakly typed which means certain types are implicitly cast depending on the operation used. While being weakly typed thought JS is also said to be dynamicly typed(like most other scripting languages), where a type is associate with a value rather than an expression. With hoe much javascript is entied to the modern internet today I doubt we will see it disapearing anytime soon.
    

---
<br>

### Scala:
    
    Description/Overview:
        Scala intialy began its desighn process in 2001 by the École Polytechnique Fédérale de Lausanne in Lausanne, Switzerland by Martin Odersky. It comes off the work on this proigraming langueage called Funel whih cobined ideas of functional programing and Petri nets(one of several mathematical modeling languages for the description of distributed systems. It is a class of discrete event dynamic system. A Petri net is a directed bipartite graph that has two types of elements, places and transitions, depicted as white circles and rectangles, respectively.(https://en.wikipedia.org/wiki/Petri_net)). Scala was finally publicly released in early 2004 in Java platforms and its cretion was done to fix many of MArtin Odersky's critisims of Java.(such as including the implementation of generics, fored object oriented programing, its implementation of floating point arithmatic, ect..). Scala is a staticly typed (the program is guaranteed to satisfy some set of type safety properties for all possible inputs) general purpose programing language that amazingly supports both functional and object-oriented programing. It has many features of a functional programing language such as currying (the technique of converting a function that takes multiple arguments into a sequence of functions that each takes a single argument), imutability (creating unchangable objects and inherantly thread safe),lazy evaluation (an evaluation strategy which delays the evaluation of an expression until its value is needed and which also avoids repeated evaluations), and pattern matching. Some things that make it different from java as well is that Scala has operator overloading, optional parameters, named parameters, and raw strings. Scala also also for different kinds of syntax, allowing for curly brace syntax, and now also after the release of Scala 3 it also supports off-side rule syntax (the indentation syntax tha python uses, no endinf in ;!) and has also said to make the production of Scala 10% quicker.(https://www.youtube.com/watch?v=Z0w_pITUTyU). Another great aspect of Scala is it is a free and open source language released under the Apache liscense. My favorite part of scala by far though is that it can be complied down into java byte code and run in the JVM (java virual machine) and better than that is a compiler for Scala called Scala.Js which compiles Scala to Javascript making it possible to run Scala programs in a browser or Node.js (a Javascript framework).


---
<br>

### PostgreSQL:
    
    Description/Overview:
        
        PostgreSQL was originally stated as just Postgres (in reference to its inspiration from Ingres database) was developed at UC Berkeley until it became PostgreSQL when SQL (Structured Querey Langue) support was added on July 8 1995.(https://en.wikipedia.org/wiki/PostgreSQL). To start structured querey language is used to intereact with databases and really for managing data held in a relational database management system. Relational being key here. SQL's language syntax is divided into many element; clauses (constituent components of statements and queries), expressions (can produce either scalar values, or tables consisting of columns and rows of data), predicates (specify conditions that can be evaluated to SQL three-valued logic, True,False, and Indeterminate), queries (retrieve the data based on specific criteria), and statements (have a persistent effect on schemata and data, or may control transactions, program flow, connections, sessions, or diagnostics)(https://en.wikipedia.org/wiki/SQL). Overall PostgreSQL complies to 170 of the 179 mandatory features of SQL. One of postgreSQL's biggest "competitors" is mySQL which was intially free and opensource like PostgreSQL (open source under the PostgreSQL liscense), mySQL is in a bit more of a sticky situation because in 2010 sun microsystems the company that aquired mySQL was aqquired by Oracle. Oracle then precided to fork their own version of mySQL called MariaDB which means they ended up leaving alot of features out of mySQL and also causing some liscensing problems. PostgreSQL as I mentioned before is completly opensource and also provides much more functionality such as including table inheritance, function overloading,partial indexing, and much better concurrency due to  Multiversion Concurrency Control which alows it to scale very well. The only time mySQL might be better is if the database is mainly read intensive as there is much less overhead.(https://developer.okta.com/blog/2019/07/19/mysql-vs-postgres). I got to say though with my love of data analysis especially when it comes to racing what sells me on PostgreSQL is its ability to handle GIS (Geographic information system) data which comes from GPSs and is implemented in PostgreSQL through PostGis(https://postgis.net/).


---
<br>

### GO (extension):
    
    Description/Overview:
        
        Go was first designed in 2007 at Google, by Robert Griesemer, Rob Pike, and Ken Thompson(https://golang.org/doc/faq) and was released to the public in 2009.  While often called GoLang since its domain name is golang.org, the language's proper name is Go (https://tip.golang.org/doc/faq#go_or_golang).  Go is a statically typed, compiled programing language (compiled to machine code) that has syntax with a similar style to C, but with memory safety, garbage collection, structural typing(https://golang.org/doc/faq#implements_interface).  Go is also stated to be open source (https://opensource.google/projects/go). Go has some oh the nice features of higher-level languages like python while at the same time having better run time and finner control like a lower-level language such as C. Go also excels at concurrency (running operations in parallel) which makes it great for backend web development and other tasks where lots of concurrent computing is necessary. 





---
<br>

### Extensions:
    
    C Extension 1:
        
        For this extension I made it so that I could pass a string (specificly the name) into the struct for task 5 which then says wether the program has been hacked or not (wether the string is to long and has overwritten data and/or the null space byte after the string).
        
        This was accomplished with this snippet of code:

        I will show 3 different runs of the program one with no string, one with a string of a size that makes it safe, and finlly a run with a string that is to long, making it hacked.

        File: C/exts/ext1.c

        Compile: gcc -o C/bin/ext1 C/exts/ext1.c

        Run 1: .C/bin/ext1

        Output 1:
            
            Error there needs to be a string passed in the argument for the struct!


        Run 2: ./C/bin/ext1 JohnathanMore

        Output 2:

            This size of the Struct is 28
            EXT1Struct, Byte 0: 4A
            EXT1Struct, Byte 1: 6F
            EXT1Struct, Byte 2: 68
            EXT1Struct, Byte 3: 6E
            EXT1Struct, Byte 4: 61
            EXT1Struct, Byte 5: 74
            EXT1Struct, Byte 6: 68
            EXT1Struct, Byte 7: 61
            EXT1Struct, Byte 8: 6E
            EXT1Struct, Byte 9: 4D
            EXT1Struct, Byte 10: 6F
            EXT1Struct, Byte 11: 72
            EXT1Struct, Byte 12: 65
            EXT1Struct, Byte 13: 00
            EXT1Struct, Byte 14: 00
            EXT1Struct, Byte 15: 00
            EXT1Struct, Byte 16: 00
            EXT1Struct, Byte 17: 00
            EXT1Struct, Byte 18: 13
            EXT1Struct, Byte 19: 00

            Safe!!!
            EXT1Struct, Byte 20: B8
            EXT1Struct, Byte 21: 1E
            EXT1Struct, Byte 22: 65
            EXT1Struct, Byte 23: 40
            EXT1Struct, Byte 24: 00
            EXT1Struct, Byte 25: 00
            EXT1Struct, Byte 26: 00
            EXT1Struct, Byte 27: 00


        Run 3: .C/bin/ext1 JohnathanMoreAdam

        Output 3:
            zsh: trace trap  ./C/bin/ext1 JohnathanMoreAdam




    C Extension 2:
        
        For this extension I wanted to find a float in c that I could add 1 to and get back the same number. To do this I wrote a for loop to keep incrementing a float until it addeed one to it and value stayed the same.
        
        This was accomplished with this snippet of code:
    
        File: C/exts/ext2.c

        Compile: gcc -o C/bin/ext2 C/exts/ext2.c

        Run: .C/bin/ext2

        Output:
            The largest integer a float can hold is 16777216.0
            16777216.0 + 1.0 = 16777216.0



    C Extension 3:
        
        For this extension I wanted to find create a bus error in c. A bus error occurs when the program is trying to access memory that the CPU can not physically address (invalid memory address). Here in particular the bus error accors because my program is trying to modify a string literal.
    

        File: C/exts/ext3.c

        Compile: gcc -o C/bin/ext3 C/exts/ext3.c

        Run: .C/bin/ext3

        Output:
            zsh: bus error  ./C/bin/ext3
    

    C Extension 4:
        
        For this extension I wanted to find create a segmentation fault in c. I created a segmentation fault in this program by trying to read a derefrenced null pointer. A segmentation fault are a result of memory protection, and are usually caused by errors mwith pointers inparticular, illegal memory addressing. They differ from bus errors which are caused mainly by "physical memory addressing, or due to misaligned memory access – these are memory references that the hardware cannot address, rather than references that a process is not allowed to address." (https://en.wikipedia.org/wiki/Segmentation_fault)

        File: C/exts/ext4.c

        Compile: gcc -o C/bin/ext4 C/exts/ext4.c

        Run: .C/bin/ext4

        Output:

            zsh: segmentation fault  ./C/bin/ext4
    
    C Extension 5:
        
        For this extension I wanted to find demonstrate how one error that can be encounter in C is a type of integer overflow that results it wrong answers for operations because the data types can not hold the number big nough for the result. For this example I used short ints to preform 1000 squard however a short int can at max hold 16960

        File: C/exts/ext5.c

        Compile: gcc -o C/bin/ext5 C/exts/ext5.c

        Run: .C/bin/ext5

        Output:
            1000 * 1000 = 16960



    