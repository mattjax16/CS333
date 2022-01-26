
1.  Define a regular expression to express strings that start with an a,
have one or more b symbols and end with an a. Note that you should test
regular expressions using the terminal command egrep. You can use the
attached ABA test file. There are three lines that match the proper
specification.


egrep "^a[b]+a$" testaba.txt


2. Using Clite syntax, generate a parse tree for the following statement.

a = b * ( 5 + c );

3. What is the output of the following C program? Why do you get this
output? How can you modify the code to get the output to be "3".

#include <stdio.h>

int main () {
     int i = 3;
     int *ptr;
     *ptr = (int)&i;
     printf("%u\n", *ptr);
}


int main () {
     int i = 3;
     int *ptr;
     ptr = (int*)&i;
     printf("%u\n", *ptr);
}
