#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if (argc < 4) {
        fprintf(stderr, "Usage: \" %s \" was wrong.\n", argv[0]);
        return 1;
    }
    int start=atoi(argv[1]);
    int   end=atoi(argv[2]);

//file stream    
    FILE* file = fopen(argv[3],"w");    
    for (int i=start; i <= end; i++){
        fprintf(file,"%d\n",i);
    }
    fclose(file);

    return 0;
}

