#include<stdio.h>
int main(void){
    char ch = getchar();
    while (ch!=EOF){
        if (ch != 'a'&&ch != 'e'&&ch != 'i'&&ch != 'o'&&ch != 'u'){
            putchar(ch);        
        }
        ch = getchar();        
    }   
    return 0;
}

        

