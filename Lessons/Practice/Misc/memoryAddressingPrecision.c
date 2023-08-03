#include <stdio.h>

struct MyRecord 
{
    int value;
    char text;
};

/** Print the contents of an array of ints with the given stride.
    Note that size_t is the correct type, as int can overflow. */
void print_some_ints(const int *arr, int length, size_t stride)
{
    int i;
    printf("Address\t\tValue\n");
    for (i=0; i < length; ++i) 
    {
        printf("%p\t%d\n", arr, arr[0]);
        arr = (int *)((unsigned char *)arr + stride);
    }
}

int main(void)
{
    int ints[2] = {100, 101};
    struct MyRecord records[2] = {{1, 'a'}, {2, 'b'}};

    print_some_ints(&ints[0], 2, sizeof ints[0]);
    print_some_ints(&records[0].value, 2, sizeof records[0]);
    return 0;
}