#include <iostream>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#define MAX 1500
void getdata(int array[])
{
    int i;
    //generating random numbers
    for (i = 0; i < MAX; i++)
    {
        array[i] = rand();
    }
}

void heapify(int array[], int n, int i){
    int parent_index = i;
    int left_child_index = (2*i) + 1;
    int right_child_index = (2*i) + 2;

    if(left_child_index < n && array[left_child_index] > array[parent_index]){
        parent_index = left_child_index;
    }

    if(right_child_index < n && array[right_child_index] > array[parent_index]){
        parent_index = right_child_index;
    }

    if(parent_index != i){
        swap(array[i], array[parent_index]);

        heapify(array, n, parent_index);
    }
}


void HeapSort(int array[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(array, n, i);
    }
    
    for(int i = n-1; i > 0; i--){
        swap(array[0],array[i]);
        
        heapify(array, i, 0);
    }
}

int main(){
    int array[MAX];
    getdata(array);
    clock_t start, end;
    /* Recording the starting clock tick.*/
    start = clock();

    HeapSort(array, MAX);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec " << endl;
    return 0;
}