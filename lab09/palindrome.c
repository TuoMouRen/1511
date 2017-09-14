#include<stdio.h>
#define MAX_LINE_LENGTH 4096
int main(void){
    int length=0;
    char line[MAX_LINE_LENGTH];    
    printf("Enter a string: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    for (int i=0; line[i]!='\n';i++) {
        length=i;  
    }
//counted the input length of strings   


    int pal_match = length/2;   // find the mid point
    int match=0;
    for (int i=0; i<pal_match;i++){
        if (line[i]==line[length-i]){
            match++;            
        }
    }
    //printf("%d\n",match);
//counted the number of matched forward and backward letters   


    if (match==pal_match){
        printf("String is a palindrome\n");
    }else{
        printf("String is not a palindrome\n");        
    }

    return 0;
}

