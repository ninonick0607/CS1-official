#include <stdio.h>

int main(void)
{
   int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   float floatArr[] = {1.1, 1.2, 1.3, 1.4, 1.5};
   double doubleArr[10];

   int*    intPtr      = intArr;
   int     intAddr     = (int) intPtr;
   int     nextIntAddr = (int) (intPtr + 1);
   float*  floatPtr    = &floatArr[0];
   int     floatAddr   = (int) floatPtr;
   int     nextFloatAddr = (int) (floatPtr + 1);
   double* doublePtr   = &doubleArr[0];
   int     doubleAddr   = (int) doublePtr;
   int     nextDoubleAddr = (int) (doublePtr + 1);
  
   printf("Address of intArr[0] : %u\n",&intArr[0]);
   printf("Address of intPtr    : %u\n",intAddr);
   printf("Address of intPtr+1  : %u\n",nextIntAddr);
   printf("size of intPtr       : %u\n",nextIntAddr - intAddr);
   printf("\n");

   printf("Address of floatArr[0] : %u\n",floatArr);
   printf("Address of floatPtr    : %u\n",floatAddr);
   printf("Address of floatPtr+1  : %u\n",nextFloatAddr);
   printf("size of floatPtr       : %u\n",nextFloatAddr - floatAddr);
   printf("\n");

   printf("Address of doubleArr[0] : %u\n",&doubleArr[0]);
   printf("Address of doublePtr    : %u\n",doubleAddr);
   printf("Address of doublePtr+1  : %u\n",nextDoubleAddr);
   printf("size of doublePtr       : %u\n",nextDoubleAddr - doubleAddr);
   printf("\n");
   return 1;
}