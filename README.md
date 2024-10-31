# 0x1B. C - Sorting algorithms & Big O
## Resources
- [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Big O notation](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
- [15 sorting algorithms in 6 minutes](https://www.youtube.com/watch?v=kPRA0W1kECg&ab_channel=TimoBingmann) (WARNING: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)
- [CS50 Algorithms explanation in detail by David Malan](https://www.youtube.com/watch?v=yb0PY3LX2x8&t=2s&ab_channel=CS50)
- [All about sorting algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)

## Learning Objectives
<details>
<summary>Basics of Selection Sort Algorithm</summary>

### Basics of Selection Sort Algorithm
**Selection sort** is an in-place comparison sorting algorithm with the following steps:
1. Start with the first element in the array.
2. Find the smallest element in the remaining array and swap it with the first element.
3. Move to the next position and repeat until the entire array is sorted.

#### Complexity Analysis of Selection Sort
**- Time Complexity: O(n2)** ,as there are two nested loops:
    + One loop to select an element of Array one by one = O(n)
    + Another loop to compare that element with every other Array element = O(n)
    + Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n2)
**- Auxiliary Space: O(1)** as the only extra memory used is for temporary variables. (in-place sorting)

**Usage:** Suitable for small data sets or cases where memory usage is critical.

#### Selection Sort Implementation in C
```c
#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        
        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            print_array(array, size);  // Print after each swap (for debugging or step-by-step view)
        }
    }
}
```
**Usage Example**
```c
#include "sort.h"

int main(void)
{
    int array[] = {64, 25, 12, 22, 11};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting:\n");
    print_array(array, size);
    
    selection_sort(array, size);
    
    printf("Array after sorting:\n");
    print_array(array, size);

    return 0;
}
```
#### Applications in Real Life
Selection sort is ideal for simple systems where limited memory is available, such as:
**- Embedded Systems:** When only a few items need sorting, and memory space is restricted.
**- Small Data Sets:** Appropriate for sorting small lists where an O(n²) complexity is manageable.
For doubly linked lists, selection sort can be modified to iterate over nodes, although other sorting algorithms like merge sort are often more efficient for linked list structures.
</details>
<details>
<summary>Basics of Bubble Sort Algorithm</summary>

### Basics of Bubble Sort Algorithm
Bubble Sort is a simple, stable sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. It has a best-case time complexity of O(n) for already sorted lists but generally performs at O(n²) due to repeated comparisons and swaps.
#### Steps:
1. Traverse the array from start to end.
2. Compare each pair of adjacent elements; if they are in the wrong order, swap them.
3. Continue this process until the array is sorted (no swaps in a pass indicates sorting is complete).
#### Complexity:
**- Time Complexity: O(n²)** (average and worst-case), O(n) (best-case for already sorted array).
**- Space Complexity: O(1)** (in-place sorting).
#### Bubble Sort Implementation in C
```c
#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
                print_array(array, size); // Print after each swap
            }
        }
        if (!swapped)
            break;  // Optimized: If no elements were swapped, array is sorted
    }
}
```
#### Advantages of Bubble Sort:
- Bubble sort is easy to understand and implement.
- It does not require any additional memory space.
- It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.
#### Disadvantages of Bubble Sort:
- Bubble sort has a time complexity of O(n²) which makes it very slow for large data sets.
- Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.
#### Applications in Real Life
Bubble sort is generally used for small data sets or educational purposes due to its simplicity. Practical applications include:
- Early Education: Bubble sort helps introduce sorting concepts because of its visual simplicity.
- Minor Dataset Sorting: Sometimes used when dataset size is small, and performance isn’t critical.
- Real-Time Systems: Rare but possible in embedded systems for small, unordered lists with very low memory capacity.
</details>
<details>
<summary>Basics of Insertion Sort Algorithm</summary>

### Basics of Insertion Sort Algorithm
Insertion Sort builds a sorted array one element at a time by repeatedly inserting new elements into their correct position within the sorted portion. It’s efficient for small data sets and partially sorted arrays, with a best-case time complexity of O(n) when the list is already sorted.

#### Steps:
1. Start from the second element, considering the first element as a sorted subarray.
2. Pick each subsequent element and insert it into the sorted portion of the array by shifting elements as needed.
3. Repeat until the entire array is sorted.
#### Complexity Analysis of Insertion Sort :
**- Time Complexity of Insertion Sort**
    **+ Best case: O(n)** , If the list is already sorted, where n is the number of elements in the list.
    **+ Average case: O(n²)** , If the list is randomly ordered
    **+ Worst case: O(n²)** , If the list is in reverse order
**- Space Complexity of Insertion Sort**
    **+ Auxiliary Space: O(1)**, Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.
#### Advantages of Insertion Sort:
- Simple and easy to implement.
- Stable sorting algorithm.
- Efficient for small lists and nearly sorted lists.
- Space-efficient as it is an in-place algorithm.
- Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.
#### Disadvantages of Insertion Sort:
- Inefficient for large lists.
- Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.
#### Applications of Insertion Sort:
Insertion sort is commonly used in situations where:
- The list is small or nearly sorted.
- Simplicity and stability are important.
- Used as a subroutine in Bucket Sort
- Can be useful when array is already almost sorted (very few inversions)
Since Insertion sort is suitable for small sized arrays, it is used in Hybrid Sorting algorithms along with other efficient algorithms like Quick Sort and Merge Sort. When the subarray size becomes small, we switch to insertion sort in these recursive algorithms. For example IntroSort and TimSort use insertions sort.
#### Insertion Sort Implementation in C
```c
#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort - Sorts an array of integers in ascending order
 *                  using the Insertion sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void insertion_sort(int *array, size_t size)
{
    size_t i, j;
    int key;

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i;

        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        print_array(array, size); // Print each step to visualize sorting process
    }
}
```

</details>
<details>
<summary>Basics of Merge Sort Algorithm</summary>

### Basics of Merge Sort Algorithm
Merge Sort is a **divide-and-conquer** algorithm that splits an array into halves, sorts each half recursively, and then merges the two sorted halves into a single sorted array. This makes it highly efficient and stable, especially for large datasets.

#### Steps:
**1. Divide** the array into two halves until each sub-array contains only one element.
**2. Conquer** by recursively sorting each half.
**3. Combine** the two sorted halves by merging them into a single sorted array.
#### Complexity Analysis of Merge Sort:
- **Time Complexity:**
    + **Best Case: O(n log n)**, When the array is already sorted or nearly sorted.
    + **Average Case: O(n log n)**, When the array is randomly ordered.
    + **Worst Case: O(n log n)**, When the array is sorted in reverse order.
- **Auxiliary Space: O(n),** Additional space is required for the temporary array used during merging.
#### Merge Sort Implementation in C
The implementation consists of two parts:
1. ``merge_sort`` function: Recursively divides and sorts the array.
2. ``merge function``: Merges two sorted sub-arrays.
```c
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two halves of an array in sorted order
 * @array: The original array containing the two halves
 * @left: Pointer to the left half
 * @right: Pointer to the right half
 * @left_size: Number of elements in the left half
 * @right_size: Number of elements in the right half
 */
void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];
    
    while (j < right_size)
        array[k++] = right[j++];

    print_array(array, left_size + right_size); // Print after merging
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    for (size_t i = 0; i < mid; i++)
        left[i] = array[i];
    for (size_t i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, mid, right, size - mid);

    free(left);
    free(right);
}
```
#### Applications in Real Life
Merge sort is particularly suited for sorting large datasets due to its efficient and predictable performance, and it’s often used in:
**- Database Sorting:** Ideal for external sorting (sorting data that doesn’t fit into memory), where data is divided, sorted, and then merged.
**- Inversion Count Problem:** Used to count how far an array is from being sorted, which is helpful in some statistical analyses.
**- Large-Scale Data Processing:** Often used in distributed systems where data needs to be sorted across different servers and merged.
**- Stable Sorting:** Merge sort maintains the relative order of equal elements, which is essential in many applications.

Merge Sort’s efficiency and stability make it widely used in large-scale applications and distributed environments where predictable performance and low memory usage are critical.

#### Advantages of Merge Sort:
**- Stability:** Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
**- Guaranteed worst-case performance:** Merge sort has a worst-case time complexity of **O(N logN)** , which means it performs well even on large datasets.
**- Simple to implement:** The divide-and-conquer approach is straightforward.
**- Naturally Parallel:** We independently merge subarrays that makes it suitable for parallel processing.
#### Disadvantages of Merge Sort:
- Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
- Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
- Slower than QuickSort in general. QuickSort is more cache friendly because it works in-place.
</details>
<details>
<summary>Basics of Quick Sort Algorithm</summary>

### Basics of Quick Sort Algorithm
Quick Sort is another efficient, **divide-and-conquer** algorithm, similar to Merge Sort, but it works differently by partitioning the array around a "pivot" element. After each partition, elements less than the pivot are placed on the left, and elements greater than the pivot are on the right. It then recursively sorts the sub-arrays to produce a fully sorted array.
#### Steps:
**1. Select a Pivot:** Choose an element to serve as the pivot (often the last element).
**2. Partitioning:** Rearrange the array so that all elements less than the pivot are on the left, and those greater are on the right.
**3. Recursion:** Apply the same logic to the sub-arrays on either side of the pivot.
#### Choice of Pivot
There are many different choices for picking pivots.
**- Always pick the first (or last) element as a pivot**. The below implementation is picks the last element as pivot. The problem with this approach is it ends up in the worst case when array is already sorted.
**- Pick a random element as a pivot.** This is a preferred approach because it does not have a pattern for which the worst case happens.
**- Pick the median element is pivot.** This is an ideal approach in terms of time complexity as *we can find median in linear time* and the partition function will always divide the input array into two halves. But it is low on average as median finding has high
#### Partition Algorithm
The key process in quickSort is a ``partition()``. There are three common algorithms to partition. All these algorithms have **O(n)** time complexity.
**1. Naive Partition:** Here we create copy of the array. First put all smaller elements and then all greater. Finally we copy the temporary array back to original array. This requires O(n) extra space.
**2. Lomuto Partition:** We have used this partition in this article. This is a simple algorithm, we keep track of index of smaller elements and keep swapping. We have used it here in this article because of its simplicity.
**3. Hoare’s Partition:** This is the fastest of all. Here we traverse array from both sides and keep swapping greater element on left with smaller on right while the array is not partitioned. Please refer [Hoare’s vs Lomuto](https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/) for details.
#### Complexity Analysis of Quick Sort
**- Time Complexity:**
    **+ Best Case: (Ω(n log n))**, Occurs when the pivot element divides the array into two equal halves.
    **+ Average Case (θ(n log n))**, On average, the pivot divides the array into two parts, but not necessarily equal.
    **+ Worst Case: (O(n²))**, Occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).
**- Auxiliary Space: O(n)**, due to recursive call stack
#### Quick Sort Implementation in C
To implement Quick Sort, you need two main functions:
- ``quick_sort``: Recursively applies the quick sort.
- ``partition``: Arranges elements around the pivot and returns the pivot's index.

**quick_sort.c**
The code below implements the Quick Sort algorithm for an integer array, with ``print_array`` used to display each pass.
```c
#include "sort.h"
#include <stdio.h>

/**
 * partition - Partitions the array around a pivot
 * @array: The array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high]; // Pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Place pivot in correct position
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    print_array(array, high - low + 1); // Print the array at each partition
    return i + 1; // Return the pivot index
}

/**
 * quick_sort_recursive - Recursively applies the quick sort algorithm
 * @array: The array to sort
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
```
#### Explanation of Key Functions
**1. ``partition`` Function:**
**- Pivot:** We use the last element (``array[high]``) as the pivot.
**- Loop:** The loop goes from ``low`` to ``high - 1``. If ``array[j] < pivot``, we increment ``i`` (to track smaller elements) and then swap ``array[i]`` with ``array[j]``.
**- Placing Pivot:** After the loop, ``array[i + 1]`` is the correct position for the pivot, so we swap ``array[i + 1]`` with ``array[high]``.
**- Return:** The index ``i + 1`` is returned as the new pivot index, dividing the array into elements less than the pivot and those greater than it.

**2. ``quick_sort_recursive`` Function:**
This function applies the recursive quick sort. After partitioning, it sorts the left sub-array (``low`` to ``pivot_index - 1``) and the right sub-array (``pivot_index + 1`` to ``high``).
**3. ``quick_sort`` Function:**
This is the main function that initiates the recursive sorting by calling ``quick_sort_recursive``.

#### Advantages of Quick Sort
- It is a divide-and-conquer algorithm that makes it easier to solve problems.
- It is efficient on large data sets.
- It has a low overhead, as it only requires a small amount of memory to function.
- It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary array.
- Fastest general purpose algorithm for large data when stability is not required.
- It is tail recursive and hence all the tail call optimization can be done.
#### Disadvantages of Quick Sort
- It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
- It is not a good choice for small data sets.
- It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).
#### Applications of Quick Sort in Real Life
Quick Sort is commonly used in:
**- Databases:** Often used for sorting data that fits in memory, as it’s efficient in terms of time complexity.
**- File Sorting:** Useful in situations where data needs to be sorted in-place without extra memory usage, like organizing file indexes.
**- Search Algorithms:** Sometimes used to pre-sort arrays, making searches faster.
**- Memory Management:** Helps in efficient memory allocation by quickly sorting memory addresses or indexes.
**- Data Analytics:** Preprocessing data by sorting before running analytics.

Quick Sort is ideal for situations requiring efficient in-place sorting, especially when memory usage is a concern.
</details>

At least four different sorting algorithms
What is the Big O notation, and how to evaluate the time complexity of an algorithm
How to select the best sorting algorithm for a given input
What is a stable sorting algorithm

## More Info
### Data Structure and Functions
- For this project you are given the following ``print_array``, and ``print_list`` functions:
```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```
```c
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```
- Our files ``print_array.c`` and ``print_list.c`` (containing the ``print_array`` and ``print_list`` functions) will be compiled with your functions during the correction.
- Please declare the prototype of the functions ``print_array`` and ``print_list`` in your ``sort.h`` header file
- Please use the following data structure for doubly linked list:
```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```
Please, note this format is used for Quiz and Task questions.
- ``O(1)``
- ``O(n)``
- ``O(n!)``
- n square -> ``O(n^2)``
- log(n) -> ``O(log(n))``
- n * log(n) -> ``O(nlog(n))``
- n + k -> ``O(n+k)``
- …

Please use the “short” notation (don’t use constants). Example: ``O(nk)`` or ``O(wn)`` should be written ``O(n)``. If an answer is required within a file, all your answers files must have a newline at the end.

### Tests
Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://www.random.org/integer-sets/)

## Tasks
### 0. Bubble sort
Write a function that sorts an array of integers in ascending order using the [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
- Prototype: ``void bubble_sort(int *array, size_t size);``
- You’re expected to print the ``array`` after each time you swap two elements (See example below)

Write in the file ``0-O``, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble
$ ./bubble
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 71, 13, 52, 99, 96, 73, 86, 7
19, 48, 71, 13, 52, 96, 99, 73, 86, 7
19, 48, 71, 13, 52, 96, 73, 99, 86, 7
19, 48, 71, 13, 52, 96, 73, 86, 99, 7
19, 48, 71, 13, 52, 96, 73, 86, 7, 99
19, 48, 13, 71, 52, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 73, 96, 86, 7, 99
19, 48, 13, 52, 71, 73, 86, 96, 7, 99
19, 48, 13, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 7, 73, 86, 96, 99
13, 19, 48, 52, 7, 71, 73, 86, 96, 99
13, 19, 48, 7, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 1. Insertion sort
Write a function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) algorithm
- Prototype: ``void insertion_sort_list(listint_t **list);``
- You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
- You’re expected to print the ``list`` after each time you swap two elements (See example below)

Write in the file ``1-O``, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 1-main.c 1-insertion_sort_list.c print_list.c -o insertion
$ ./insertion
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 13, 71, 99, 52, 96, 73, 86, 7
19, 13, 48, 71, 99, 52, 96, 73, 86, 7
13, 19, 48, 71, 99, 52, 96, 73, 86, 7
13, 19, 48, 71, 52, 99, 96, 73, 86, 7
13, 19, 48, 52, 71, 99, 96, 73, 86, 7
13, 19, 48, 52, 71, 96, 99, 73, 86, 7
13, 19, 48, 52, 71, 96, 73, 99, 86, 7
13, 19, 48, 52, 71, 73, 96, 99, 86, 7
13, 19, 48, 52, 71, 73, 96, 86, 99, 7
13, 19, 48, 52, 71, 73, 86, 96, 99, 7
13, 19, 48, 52, 71, 73, 86, 96, 7, 99
13, 19, 48, 52, 71, 73, 86, 7, 96, 99
13, 19, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 7, 73, 86, 96, 99
13, 19, 48, 52, 7, 71, 73, 86, 96, 99
13, 19, 48, 7, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 2. Selection sort
Write a function that sorts an array of integers in ascending order using the [Selection sort](https://en.wikipedia.org/wiki/Selection_sort) algorithm
- Prototype: ``void selection_sort(int *array, size_t size);``
- You’re expected to print the ``array`` after each time you swap two elements (See example below)

Write in the file ``2-O``, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 
2-main.c 2-selection_sort.c print_array.c -o select
$ ./select
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 13, 99, 71, 48, 52, 96, 73, 86, 19
7, 13, 19, 71, 48, 52, 96, 73, 86, 99
7, 13, 19, 48, 71, 52, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 73, 96, 86, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 3. Quick sort
Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm
- Prototype: ``void quick_sort(int *array, size_t size);``
- You must implement the ``Lomuto`` partition scheme.
- The pivot should always be the last element of the partition being sorted.
- You’re expected to print the ``array`` after each time you swap two elements (See example below)

Write in the file ``3-O``, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 3-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o quick
$ ./quick
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 13, 99, 71, 48, 52, 96, 73, 86, 19
7, 13, 19, 71, 48, 52, 96, 73, 86, 99
7, 13, 19, 71, 48, 52, 73, 96, 86, 99
7, 13, 19, 71, 48, 52, 73, 86, 96, 99
7, 13, 19, 48, 71, 52, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 4. Shell sort - Knuth Sequence
Write a function that sorts an array of integers in ascending order using the [Shell sort](https://en.wikipedia.org/wiki/Shellsort) algorithm, using the ``Knuth sequence``
- Prototype: ``void shell_sort(int *array, size_t size);``
- You must use the following sequence of intervals (a.k.a the Knuth sequence):
    + ``n+1 = n * 3 + 1``
    + ``1, 4, 13, 40, 121, ...``
- You’re expected to print the ``array`` each time you decrease the interval (See example below).

**No big O notations of the time complexity of the Shell sort (Knuth sequence) algorithm needed - as the complexity is dependent on the size of array and gap**
```bash
$ cat 100-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 100-main.c 100-shell_sort.c print_array.c -o shell
$ ./shell
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

13, 7, 96, 71, 19, 48, 99, 73, 86, 52
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 5. Cocktail shaker sort
Write a function that sorts a doubly linked list of integers in ascending order using the [Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort) algorithm
- Prototype: ``void cocktail_sort_list(listint_t **list);``
- You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
- You’re expected to print the ``list`` after each time you swap two elements (See example below)

Write in the file ``101-O``, the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 101-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 101-main.c 101-cocktail_sort_list.c print_list.c -o cocktail
$ ./cocktail
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 71, 13, 52, 99, 96, 73, 86, 7
19, 48, 71, 13, 52, 96, 99, 73, 86, 7
19, 48, 71, 13, 52, 96, 73, 99, 86, 7
19, 48, 71, 13, 52, 96, 73, 86, 99, 7
19, 48, 71, 13, 52, 96, 73, 86, 7, 99
19, 48, 71, 13, 52, 96, 73, 7, 86, 99
19, 48, 71, 13, 52, 96, 7, 73, 86, 99
19, 48, 71, 13, 52, 7, 96, 73, 86, 99
19, 48, 71, 13, 7, 52, 96, 73, 86, 99
19, 48, 71, 7, 13, 52, 96, 73, 86, 99
19, 48, 7, 71, 13, 52, 96, 73, 86, 99
19, 7, 48, 71, 13, 52, 96, 73, 86, 99
7, 19, 48, 71, 13, 52, 96, 73, 86, 99
7, 19, 48, 13, 71, 52, 96, 73, 86, 99
7, 19, 48, 13, 52, 71, 96, 73, 86, 99
7, 19, 48, 13, 52, 71, 73, 96, 86, 99
7, 19, 48, 13, 52, 71, 73, 86, 96, 99
7, 19, 13, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 6. Counting sort
Write a function that sorts an array of integers in ascending order using the [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) algorithm
- Prototype: ``void counting_sort(int *array, size_t size);``
- You can assume that ``array`` will contain only numbers ``>= 0``
- You are allowed to use ``malloc`` and ``free`` for this task
- You’re expected to print your counting array once it is set up (See example below)
    + This array is of size ``k + 1`` where ``k`` is the largest number in ``array``

Write in the file ``102-O``, the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 102-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 102-main.c 102-counting_sort.c print_array.c -o counting
$ ./counting
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 7. Merge sort
Write a function that sorts an array of integers in ascending order using the [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
- Prototype: ``void merge_sort(int *array, size_t size);``
- You must implement the ``top-down`` merge sort algorithm
    + When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. ``{1, 2, 3, 4, 5}`` -> ``{1, 2}, {3, 4, 5}``
    + Sort the left array before the right array
- You are allowed to use ``printf``
- You are allowed to use ``malloc`` and ``free`` only once (only one call)
- Output: see example

Write in the file ``103-O``, the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 103-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 103-main.c 103-merge_sort.c print_array.c -o merge
$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 8. Heap sort
Write a function that sorts an array of integers in ascending order using the [Heap sort](https://en.wikipedia.org/wiki/Heapsort) algorithm
- Prototype: ``void heap_sort(int *array, size_t size);``
- You must implement the ``sift-down`` heap sort algorithm
- You’re expected to print the ``array`` after each time you swap two elements (See example below)

Write in the file ``104-O``, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 104-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 104-main.c 104-heap_sort.c print_array.c -o heap
$ ./heap
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 86, 13, 52, 96, 73, 71, 7
19, 86, 99, 48, 13, 52, 96, 73, 71, 7
19, 86, 99, 73, 13, 52, 96, 48, 71, 7
99, 86, 19, 73, 13, 52, 96, 48, 71, 7
99, 86, 96, 73, 13, 52, 19, 48, 71, 7
7, 86, 96, 73, 13, 52, 19, 48, 71, 99
96, 86, 7, 73, 13, 52, 19, 48, 71, 99
96, 86, 52, 73, 13, 7, 19, 48, 71, 99
71, 86, 52, 73, 13, 7, 19, 48, 96, 99
86, 71, 52, 73, 13, 7, 19, 48, 96, 99
86, 73, 52, 71, 13, 7, 19, 48, 96, 99
48, 73, 52, 71, 13, 7, 19, 86, 96, 99
73, 48, 52, 71, 13, 7, 19, 86, 96, 99
73, 71, 52, 48, 13, 7, 19, 86, 96, 99
19, 71, 52, 48, 13, 7, 73, 86, 96, 99
71, 19, 52, 48, 13, 7, 73, 86, 96, 99
71, 48, 52, 19, 13, 7, 73, 86, 96, 99
7, 48, 52, 19, 13, 71, 73, 86, 96, 99
52, 48, 7, 19, 13, 71, 73, 86, 96, 99
13, 48, 7, 19, 52, 71, 73, 86, 96, 99
48, 13, 7, 19, 52, 71, 73, 86, 96, 99
48, 19, 7, 13, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
19, 13, 7, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 9. Radix sort
Write a function that sorts an array of integers in ascending order using the [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) algorithm
- Prototype: ``void radix_sort(int *array, size_t size);``
- You must implement the ``LSD`` radix sort algorithm
- You can assume that array will contain only numbers ``>= 0``
- You are allowed to use ``malloc`` and ``free`` for this task
- You’re expected to print the ``array`` each time you increase your ``significant digit`` (See example below)
```bash
$ cat 105-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 105-main.c 105-radix_sort.c print_array.c -o radix
$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
### 10. Bitonic sort
Write a function that sorts an array of integers in ascending order using the [Bitonic sort](https://en.wikipedia.org/wiki/Bitonic_sorter) algorithm
- Prototype: ``void bitonic_sort(int *array, size_t size);``
- You can assume that size will be equal to ``2^k``, where ``k >= 0`` (when ``array`` is not ``NULL`` …)
- You are allowed to use ``printf``
- You’re expected to print the ``array`` each time you swap two elements (See example below)
- Output: see example

Write in the file ``106-O``, the big O notations of the time complexity of the Bitonic sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 106-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bitonic_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 106-main.c 106-bitonic_sort.c print_array.c -o bitonic
$ ./bitonic
100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13

Merging [16/16] (UP):
100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13
Merging [8/16] (UP):
100, 93, 40, 57, 14, 58, 85, 54
Merging [4/16] (UP):
100, 93, 40, 57
Merging [2/16] (UP):
100, 93
Result [2/16] (UP):
93, 100
Merging [2/16] (DOWN):
40, 57
Result [2/16] (DOWN):
57, 40
Result [4/16] (UP):
40, 57, 93, 100
Merging [4/16] (DOWN):
14, 58, 85, 54
Merging [2/16] (UP):
14, 58
Result [2/16] (UP):
14, 58
Merging [2/16] (DOWN):
85, 54
Result [2/16] (DOWN):
85, 54
Result [4/16] (DOWN):
85, 58, 54, 14
Result [8/16] (UP):
14, 40, 54, 57, 58, 85, 93, 100
Merging [8/16] (DOWN):
31, 56, 46, 39, 15, 26, 78, 13
Merging [4/16] (UP):
31, 56, 46, 39
Merging [2/16] (UP):
31, 56
Result [2/16] (UP):
31, 56
Merging [2/16] (DOWN):
46, 39
Result [2/16] (DOWN):
46, 39
Result [4/16] (UP):
31, 39, 46, 56
Merging [4/16] (DOWN):
15, 26, 78, 13
Merging [2/16] (UP):
15, 26
Result [2/16] (UP):
15, 26
Merging [2/16] (DOWN):
78, 13
Result [2/16] (DOWN):
78, 13
Result [4/16] (DOWN):
78, 26, 15, 13
Result [8/16] (DOWN):
78, 56, 46, 39, 31, 26, 15, 13
Result [16/16] (UP):
13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100

13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100
```
### 11. Quick Sort - Hoare Partition scheme
Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm
- Prototype: ``void quick_sort_hoare(int *array, size_t size);``
- You must implement the ``Hoare`` partition scheme.
- The pivot should always be the last element of the partition being sorted.
- You’re expected to print the ``array`` after each time you swap two elements (See example below)

Write in the file ``107-O``, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```bash
$ cat 107-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort_hoare(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 107-main.c 107-quick_sort_hoare.c print_array.c -o quick
$ ./quick
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 19, 99, 71, 13, 52, 96, 73, 86, 48
7, 19, 13, 71, 99, 52, 96, 73, 86, 48
7, 13, 19, 71, 99, 52, 96, 73, 86, 48
7, 13, 19, 48, 99, 52, 96, 73, 86, 71
7, 13, 19, 48, 71, 52, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 86, 73, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
Another example of output:
```bash
$ ./quick_2
87, 65, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 38

38, 65, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 87
38, 8, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 65, 45, 87
38, 8, 28, 36, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 69, 62, 13, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 13, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 6, 36, 21, 16, 11, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 6, 11, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
11, 8, 6, 13, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 28, 26, 27, 30, 24, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 28, 26, 27, 24, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 45, 59, 42, 39, 52, 93, 75, 63, 71, 65, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 45, 59, 42, 39, 52, 65, 75, 63, 71, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 71, 87, 58, 45, 59, 42, 39, 52, 65, 75, 63, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 71, 63, 58, 45, 59, 42, 39, 52, 65, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 65, 71, 63, 58, 45, 59, 42, 39, 52, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 65, 52, 63, 58, 45, 59, 42, 39, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 65, 52, 63, 58, 45, 59, 42, 62, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 62, 52, 63, 58, 45, 59, 42, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 62, 52, 42, 58, 45, 59, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 59, 52, 42, 58, 45, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 45, 52, 42, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 45, 42, 52, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 88, 92, 93

6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 88, 92, 93
```
### 12. Dealer
Write a function that sorts a deck of cards.
- Prototype: void sort_deck(deck_node_t **deck);
- You are allowed to use the C standard library function qsort
- Please use the following data structures:
```c
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;
```
- You have to push you ``deck.h`` header file, containing the previous data structures definition
- Each node of the doubly linked list contains a card that you cannot modify. You have to swap the nodes.
- You can assume there is exactly ``52`` elements in the doubly linked list.
- You are free to use the sorting algorithm of your choice
- The deck must be ordered:
    + From ``Ace`` to ``King``
    + From Spades to Diamonds
    + See example below
```bash
$ cat 1000-main.c
#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

void print_deck(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

deck_node_t *init_deck(const card_t cards[52])
{
    deck_node_t *deck;
    deck_node_t *node;
    size_t i;

    i = 52;
    deck = NULL;
    while (i--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->card = &cards[i];
        node->next = deck;
        node->prev = NULL;
        if (deck)
            deck->prev = node;
        deck = node;
    }
    return (deck);
}

int main(void)
{
    card_t cards[52] = {
        {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND}, {"Queen", HEART}, {"5", HEART}, {"5", SPADE}, {"10", HEART}, {"6", HEART}, {"5", DIAMOND}, {"6", SPADE}, {"9", HEART}, {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND}, {"9", CLUB}, {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND}, {"10", CLUB}, {"King", SPADE}, {"8", CLUB}, {"9", SPADE}, {"6", CLUB}, {"Ace", CLUB}, {"3", SPADE}, {"8", SPADE}, {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND}, {"6", DIAMOND}, {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND}, {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB}, {"4", SPADE}, {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB}, {"Queen", SPADE}, {"Queen", DIAMOND}, {"7", CLUB}, {"7", HEART}, {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB}, {"King", HEART}, {"Ace", HEART},
    };
    deck_node_t *deck;

    deck = init_deck(cards);
    print_deck(deck);
    printf("\n");
    sort_deck(&deck);
    printf("\n");
    print_deck(deck);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 1000-main.c 1000-sort_deck.c -o deck
$ ./deck
{Jack, C}, {4, H}, {3, H}, {3, D}, {Queen, H}, {5, H}, {5, S}, {10, H}, {6, H}, {5, D}, {6, S}, {9, H}, {7, D}
{Jack, S}, {Ace, D}, {9, C}, {Jack, D}, {7, S}, {King, D}, {10, C}, {King, S}, {8, C}, {9, S}, {6, C}, {Ace, C}, {3, S}
{8, S}, {9, D}, {2, H}, {4, D}, {6, D}, {3, C}, {Queen, C}, {10, S}, {8, D}, {8, H}, {Ace, S}, {Jack, H}, {2, C}
{4, S}, {2, S}, {2, D}, {King, C}, {Queen, S}, {Queen, D}, {7, C}, {7, H}, {5, C}, {10, D}, {4, C}, {King, H}, {Ace, H}


{Ace, S}, {2, S}, {3, S}, {4, S}, {5, S}, {6, S}, {7, S}, {8, S}, {9, S}, {10, S}, {Jack, S}, {Queen, S}, {King, S}
{Ace, H}, {2, H}, {3, H}, {4, H}, {5, H}, {6, H}, {7, H}, {8, H}, {9, H}, {10, H}, {Jack, H}, {Queen, H}, {King, H}
{Ace, C}, {2, C}, {3, C}, {4, C}, {5, C}, {6, C}, {7, C}, {8, C}, {9, C}, {10, C}, {Jack, C}, {Queen, C}, {King, C}
{Ace, D}, {2, D}, {3, D}, {4, D}, {5, D}, {6, D}, {7, D}, {8, D}, {9, D}, {10, D}, {Jack, D}, {Queen, D}, {King, D}
```