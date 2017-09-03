#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>   
    char lowercase[27]= "abcdefghijklmnopqrstuvwxyz";  
    char uppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    char encrypt_lowercase[27]={'0'};  
    char encrypt_Uppercase[27]={'0'};  
    int key();  
    int main(int argc, char const *argv[]) {    
        char ch;  
        key(argv);  
        while ((ch=getchar())!=EOF) { 
            for (int i = 0; i < 26; ++i) {   
                if (encrypt_Uppercase[i]==ch ) {    
                    putchar(uppercase[i]);  
                }  
                if ( encrypt_lowercase[i]==ch) {  
                    putchar(lowercase[i]);  
                }  
            }  
            if (ispunct(ch)||ch==' '||ch=='\n') {  
                putchar(ch);  
            }  
        }  
        return 0;  
    }  
    int key(char const *argv[]){   
        for (int i = 0; i < 26; i++) {    
            encrypt_lowercase[i]=argv[1][i];  
            for (int j = 0; j < 26; j++) {    
                if (lowercase[j]==argv[1][i]) {    
                    encrypt_Uppercase[i]=uppercase[j];  
                }  
            }  
        }  
    }  

