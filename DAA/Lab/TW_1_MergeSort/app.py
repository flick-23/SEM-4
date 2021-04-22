# implement merge-sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the exp for different values of n
import random
import time


max = 100000


def get_data(array):
    for i in range(max):
        ele = random.randint(0, 80000)
        array.append(ele)


def mergesort(array):
    if len(array) > 1:
        mid = len(array) // 2
        left_sub = array[:mid]
        right_sub = array[mid:]

        mergesort(left_sub)  # recursive call to left sub array
        mergesort(right_sub)  # recursive call to right sub array

        i = j = k = 0  # creating 3 index objects for sorting

        while i < len(left_sub) and j < len(right_sub):
            if left_sub[i] < right_sub[i]:
                array[k] = left_sub[i]
                i += 1  # incremneting left sub array index
            else:
                array[k] = right_sub[j]
                j += 1  # incrementiny right sub array index
            k += 1  # incrementing main array index

        # if any left sub array elemnts were left copying remaning int main array
        while i < len(left_sub):
            array[k] = left_sub[i]
            i += 1
            k += 1

        # if any right sub array elemnts were left copying remaning into main array
        while j < len(right_sub):
            array[k] = right_sub[j]
            j += 1
            k += 1


array = []
# for i in range(20):
get_data(array)
start_time = time.time()
mergesort(array)
end_time = time.time()
print(f"time taken is :: {end_time - start_time} seconds")
