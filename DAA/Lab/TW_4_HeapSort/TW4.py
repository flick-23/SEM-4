import random
import time


max = 10000

#for generating random numbers
def get_data(array):
    for i in range(max):
        ele = random.randint(0, 80000)
        array.append(ele)


def heapify(array, array_length ,i):
    #initializing the indexes
    parent_index = i
    left_child_index = 2*i +1 
    right_child_index = 2*i +2 

    #checking if left child of root exists and if it is greater than root 
    if left_child_index < array_length and array[parent_index] < array[left_child_index]:
        parent_index = left_child_index
        
    #checking if right child of root exists and if it is greater than root 
    if right_child_index < array_length and array[parent_index] < array[right_child_index]:
        parent_index = right_child_index
    
    #checking if any chnages has been made to parent_index 
    if parent_index != i:
        array[i], array[parent_index] = array[parent_index], array[i] 
        
        heapify(array, array_length, parent_index)


def heapSort(array):
        array_length = len(array)   
        
        #Building the heap for given array
        for i in range((array_length//2 )-1, -1, -1):
            heapify(array, array_length, i)

        #extracting one by one elements
        for i in range(array_length-1, 0, -1):
            array[i], array[0] = array[0], array[i]
            heapify(array, i, 0)



array = []
get_data(array)
start_time = time.time()
heapSort(array)
end_time = time.time()
print(f"time taken is :: {end_time - start_time} seconds")
