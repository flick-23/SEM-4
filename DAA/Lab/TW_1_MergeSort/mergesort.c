#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
void getdata(int arr[])
{
    int i;
    //generating random numbers
    for (i = 0; i < MAX; i++)
    {
        arr[i] = rand();
    }
}

void sort(int arr[], int low, int mid, int high)
{
    int i, j, k, l, b[MAX];
    l = low;

    i = low;
    j = mid + 1;
    while ((l <= mid) && (j <= high))
    {
        if (arr[l] <= arr[j])
        {
            b[i] = arr[l];
            l++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (l > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = l; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}

void partition(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        sort(arr, low, mid, high);
    }
}
int main(int argc, char *argv[])
{
    int array[MAX];
    int n, i;
    getdata(array);
    clock_t t;
    t = clock();

    partition(array, 0, MAX - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
