#include <stdio.h>

void swap(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = *a;
}

int main(void)
{
   int a = 4;
   int b = 2;

   printf("Before Swap\n");
   printf("a : %d\n",a);
   printf("b : %d\n",b);

   swap(&a,&b);

   printf("After Swap\n");
   printf("a : %d\n",a);
   printf("b : %d\n",b);
   



}