#include <stdio.h>  
#include <stdlib.h>  

int main(int argc, char const *argv[]) {
    char lowercase[27]= "abcdefghijklmnopqrstuvwxyz";  
    char uppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   
    char ch;  
    int freq[26]={0};   
    int sum=0,i;
    double percent; 
    while ((ch=getchar())!=EOF) {   
        for (i = 0; i < 26; ++i) {  
            if (uppercase[i]==ch || lowercase[i]==ch) {   
                freq[i]++;  
                sum++;            
            }  
        }    
    }    
    for (int i = 0; i < 26; i++) {   
        percent=(double)freq[i]/sum;  
        printf("\'%c\' %f %d\n",lowercase[i],percent,freq[i] );  
    }  
    return 0;  
}  

