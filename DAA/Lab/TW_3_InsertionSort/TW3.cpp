// Implement Insertion Sort algorithim and determine the time required to sort the elements .
// Repeat the experiment for different values of n,
// the number of elements in the list to be sorted and plot a graph of time taken versus n
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#define MAX 10000
void getdata(int array[])
{
    int i;
    //generating random numbers
    for (i = 0; i < MAX; i++)
    {
        array[i] = rand();
    }
}

void InsertionSort(int array[])
{
    int i, num, j;
    for (i = 1; i < MAX; i++)
    {
        num = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > num)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = num;
    }
}

int main()
{
    int array[MAX];
    getdata(array);
    clock_t start, end;

    /* Recording the starting clock tick.*/
    start = clock();

    InsertionSort(array);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec " << endl;
    return 0;
}
