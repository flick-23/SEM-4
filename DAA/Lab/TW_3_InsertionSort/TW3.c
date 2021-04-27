// Implement Insertion Sort algorithim and determine the time required to sort the elements .
// Repeat the experiment for different values of n,
// the number of elements in the list to be sorted and plot a graph of time taken versus n

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void getdata(int arr[])
{
    int i;
    //generating random numbers
    for (i = 0; i < MAX; i++)
    {
        arr[i] = rand();
    }
}
void insertion_sort(int *x)
{
    int temp, i, j;

    for (i = 1; i < MAX; i++)
    {
        temp = x[i];
        j = i - 1;
        while (temp < x[j] && j >= 0)
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = temp;
    }
}
int main(int argc, char *argv[])
{
    int a[MAX];
    getdata(a);
    clock_t t;

    t = clock();
    insertion_sort(a);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}