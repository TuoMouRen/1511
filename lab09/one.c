#include<stdio.h>
#define MAX_LINE_LENGTH 4096
int main(void){
    
    char line[MAX_LINE_LENGTH];    
    printf("Enter a string: ");
    
    if (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        for (int i=0;line[i]!='\n';i++) {        
            printf("%c\n",line[i]);
        }
    }
    
    return 0;
}

