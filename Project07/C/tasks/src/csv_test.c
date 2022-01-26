//
// Created by Matthew Bass on 1/12/22.
//

//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//
//#define MAXCHAR 1000
//
//int main(){
//
//    FILE *fp;
//    char row[MAXCHAR];
//
//    fp = fopen("/Users/matthewbass/Documents/School_Colby/Colby/CS333/Project07/Data/grades.csv","r");
//
//    ;
//
//    while (feof(fp) != true)
//    {
//        fgets(row, MAXCHAR, fp);
//        printf("Row: %s", row);
//    }
//
//
//    return 0;
//}

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}
