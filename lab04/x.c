#include <stdio.h>
int main(void) {
    int number,row, col;
    printf("Enter size: ");
    scanf("%d", &number);

    row = 1;
    while (row <= number) {
        col = 1;
        while (col <= number) {
            if (col == row||col == number+1-row){
                printf("*");
            } else {
                printf("-");
            }
            col = col + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;
}



