# Implement Insertion Sort algorithim and determine the time required to sort the elements .
# Repeat the experiment for different values of n,
# the number of elements in the list to be sorted and plot a graph of time taken versus n
import random
import time


max = 10000


def get_data(array):  # function to generate numbers and store in "array" variable
    for i in range(max):
        ele = random.randint(0, 80000)
        array.append(ele)


def InsertionSort(array):  # main insertion sort function
    for i in range(1, max):  # loop to traverse through all elements of "array"
        num = array[i]

        j = i-1  # to get index of prev element in "array" that has to be compared first
        # loops and swaps until the number finds its proper position
        while j >= 0 and num < array[j]:
            array[j+1] = array[j]
            j -= 1  # reducing the index to get the prev number in array to be compared
        array[j+1] = num  # placing the number in its proper location


array = []
get_data(array)
start_time = time.time()
InsertionSort(array)
end_time = time.time()
print(f"time taken is :: {end_time - start_time} seconds")
