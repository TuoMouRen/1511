#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int ch, alph=26;
    if (argc < 2) {
        printf("Warning, no shift\n");
        return 1;
    }
	int shift = atoi(argv[1]);
	if(shift > alph || shift < -alph){
		shift = shift % alph;
	}
	ch = getchar();
	while(ch != EOF){
		if(ch <= 'Z' && ch >= 'A'){
			ch = ch + shift;
			if(ch > 'Z'){
				ch = ch - alph;
			}else if(ch < 'A'){
				ch = ch + alph;	
			}
		}
		if(ch <= 'z' && ch >= 'a'){
			ch = ch + shift;
			if(ch > 'z'){
				ch = ch - alph;
			}else if(ch < 'a'){
				ch = ch + alph;	
			}
		}
		putchar(ch);
		ch = getchar(); 
	}
	return 0;
}
