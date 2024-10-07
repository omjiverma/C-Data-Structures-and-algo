#include <stdio.h>
#define N 10 // Maximum size of the queue

// Initialize the queue by setting front and rear to 0 (empty queue)
void initQueue(int *front, int *rear)
{
    *front = 0;
    *rear = 0;
}

// Add an element to the queue (enqueue operation)
void enqueue(int *arr, int *rear, int element)
{
    arr[*rear] = element;  // Add the element to the rear of the queue
    *rear = *rear + 1;     // Increment rear to point to the next empty position
}

// Remove an element from the queue (dequeue operation)
void dequeue(int *arr, int *rear, int *element)
{
    int i;
    *element = arr[0]; // Store the element at the front of the queue (first element)

    // Shift all elements to the left to fill the empty space at the front
    for (i = 0; i < *rear - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *rear = *rear - 1; // Decrease the rear index after dequeue
}

// Check if the queue is empty by verifying if rear is 0
int isEmptyQueue(int rear)
{
    if (rear == 0)
    {
        return 1; // Return 1 if the queue is empty
    }
    return 0; // Return 0 if the queue is not empty
}

// Check if the queue is full by verifying if rear has reached the maximum size
int isfullQueue(int rear)
{
    if (rear == N)
    {
        return 1; // Return 1 if the queue is full
    }
    return 0; // Return 0 if the queue is not full
}

// Print the elements in the queue from front to rear
void printQueue(int *arr, int rear)
{
    int i;
    if (rear != 0) // If the queue is not empty
    {
        for (i = 0; i < rear; i++)
        {
            printf("%d ", arr[i]); // Print each element in the queue
        }
    }
    else
    {
        printf("Empty Queue"); // Print a message if the queue is empty
    }
    printf("\n"); // Newline for formatting output
}

int main()
{
    int front, rear, element;
    int arr[N]; // Declare the queue array with size N

    initQueue(&front, &rear); // Initialize the queue (set front and rear to 0)
    
    enqueue(arr, &rear, 10); // Enqueue element 10
    enqueue(arr, &rear, 20); // Enqueue element 20
    enqueue(arr, &rear, 30); // Enqueue element 30

    printQueue(arr, rear); // Print the queue: 10 20 30

    dequeue(arr, &rear, &element); // Dequeue the front element (10)
    printQueue(arr, rear); // Print the queue: 20 30

    dequeue(arr, &rear, &element); // Dequeue the front element (20)
    dequeue(arr, &rear, &element); // Dequeue the front element (30)

    // Check if the queue is empty and print the result (1 for true, 0 for false)
    printf("%d\n", isEmptyQueue(rear)); // Output: 1 (queue is empty)

    // Check if the queue is full and print the result (1 for true, 0 for false)
    printf("%d\n", isfullQueue(rear)); // Output: 0 (queue is not full)
}
