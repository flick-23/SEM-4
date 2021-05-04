# Sort a given set of elements using the Quicksort method and determine the time required to sort the elements . Repaet the experiment to different
# values of n, the number of elements in the list to be sorted and plot a graph ,number of elemnts against time taken to execute

import random
import time


max = 10000


def get_data(array):
    for i in range(max):
        ele = random.randint(0, 80000)
        array.append(ele)


def partition(array, beg, end):
    pivot_index = beg
    pivot = array[pivot_index]

    while beg < end:
        while beg<len(array) and array[beg] <= pivot:
            beg += 1

        while array[end] > pivot:
            end -= 1

        if beg < end:
            array[beg], array[end] = array[end], array[beg]

    array[end], array[pivot_index] = array[pivot_index], array[end]

    return end


def quick_sort(array, beg, end):
    if beg < end:
        partition_index = partition(array, beg, end)

        quick_sort(array, beg, partition_index-1)
        quick_sort(array, partition_index+1, end)


array = []
get_data(array)

start_time = time.time()
quick_sort(array, 0, len(array)-1)
end_time = time.time()
print(f"time taken is :: {end_time - start_time} seconds")
