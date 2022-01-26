CS333 - Project #6 - README
Ben Lawlor
05/04/2020

Directory Layout:

project06/
|
|__/linkedlist.h
|__/linkedlist.c
|__/wordcounter.c
|__/wctest.txt
|__/interruptHandler.c
|__/floatingpointHandler.c
|__/segfaultHandler.c

Run and build configuration for C:
macOS High Sierra Version 10.13.1

linkedlist.h
    This C header file contains the LinkedList and node structs as well as abstract functions
    for the linkedlist.c program. Some additional functions not included in the 
    project 05 linked list implementation were added for this project.

    Compile/Run/Output: N/A 

linkedlist.c
    This file implements all the functions in the linkedlist.h file.

    Compile/Run/Output: N/A

wordcounter.c
    This program reads in a text file and prints out the word counts of the 20 most
    frequent words in the file.

    Compile:
        gcc -o wordcounter wordcounter.c

    Run:
        ./wordcounter wctest.txt

    Output:
        --------------
        the: 17

        --------------
        of: 7

        --------------
        and: 6

        --------------
        was: 5

        --------------
        with: 4

        --------------
        in: 4

        --------------
        a: 3

        --------------
        windows: 3

        --------------
        central: 2

        --------------
        portion: 2

        --------------
        wings: 2

        --------------
        were: 2

        --------------
        broken: 2

        --------------
        but: 2

        --------------
        up: 2

        --------------
        had: 2

        --------------
        been: 2

        --------------
        building: 1

        --------------
        grey: 1

        --------------
        lichen-blotched: 1

        --------------
        stone: 1

        --------------
        high: 1

        --------------
        two: 1

        --------------
        curving: 1

        --------------
        like: 1

        --------------
        claws: 1

        --------------
        crab: 1

        --------------
        thrown: 1

        --------------
        out: 1

        --------------
        on: 1

        --------------
        each: 1

        --------------
        side: 1

        --------------
        one: 1

        --------------
        these: 1

        --------------
        blocked: 1

        --------------
        wooden: 1

        --------------
        boards: 1

        --------------
        while: 1

        --------------
        roof: 1

        --------------
        partly: 1

    wctest.txt
        This text file contains a paragraph on which to test the wordcounter implementation.

        Compile/Run/Output: N/A

    interruptHandler.c
        This program creates an infinite loop and handles a ctrl-C interruption.
        
        Compile:
            gcc -o intrHandler interruptHandler.c

        Run:
            ./intrHandler
            ctrl-C

        Output:
            looping infinitely :)

            looping infinitely :)

            looping infinitely :)
            ^CInterrupted! Caught signal: 2

    floatingpointHandler.c
        This program creates and handles a floating point error.

        Compile:
            gcc -o fltHandler floatingpointHandler.c

        Run:
            ./fltHandler

        Output:
            v2 = 0
            Interrupted! Caught signal: 8
            dividing by 2 instead
            a = 0.500000

    segfaultHandler.c
        This program creates and handles a segmentation fault.

        Compile:
            gcc -o segHandler segfaultHandler.c

        Run:
            ./segHandler

        Output:
            Interrupted! Caught segmentation fault: 11
