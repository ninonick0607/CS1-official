#include <stdio.h>

int main(){
    int grid[4][2]={
        {5,6},
        {8,23},
        {22,9},
        {90,4},
    };
    int i,j;
    for(i=0;i<=3;i++){
        printf("\n");
        for(j=0;j<=1;j++)
            printf("%d ",*(*(grid+i)+j));
    }
}