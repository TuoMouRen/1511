#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]){
    char line[MAX_LINE_LENGTH];
    int N_lines=0;
    char *name;
// check the number of argc    
    if (argc == 2){
        name = argv[1];
        N_lines = 10;    
    }else if (argc == 4){
        name = argv[3];
        N_lines = atoi(argv[2]);
    }

// file stream
    FILE* file = fopen(name,"r");
    for (int i=0; i<N_lines; i++){
        if (fgets(line,MAX_LINE_LENGTH,file) != NULL){
            printf("%s",line);
        }
    }
    fclose(file);
    
    return 0;
}
