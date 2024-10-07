// Linear Queue Implementation

/*
Front: Index of the first filled location in the queue
Rear: Index of the next available position in the queue
*/

#include <stdio.h>
#define N 10  // Defining the maximum size of the queue

// Function to initialize the front and rear of the queue
void initQueue(int *front, int *rear)
{
    *front = 0;  // Front is initialized to 0
    *rear = 0;   // Rear is also initialized to 0
}

// Function to add an element to the queue
void enqueue(int *arr, int *rear, int element)
{
    arr[*rear] = element;  // Insert the element at the rear index
    *rear = *rear + 1;     // Increment rear to point to the next empty position
}

// Function to remove an element from the queue (dequeue)
void dequeue(int *arr, int *rear, int *element)
{
    int i;
    *element = arr[0];  // Remove the first element (at index 0)
    
    // Shift all the elements one position to the left
    for (i = 0; i < *rear - 1; i++)
    {
        arr[i] = arr[i + 1];  // Move each element forward
    }
    *rear = *rear - 1;  // Decrement the rear pointer after dequeue
}

// Function to check if the queue is empty
int isEmptyQueue(int rear)
{
    if (rear == 0)
    {
        return 1;  // Return 1 if the queue is empty
    }
    return 0;  // Otherwise, return 0
}

// Function to check if the queue is full
int isfullQueue(int rear)
{
    if (rear == N)
    {
        return 1;  // Return 1 if the queue is full
    }
    return 0;  // Otherwise, return 0
}

// Function to print the elements of the queue
void printQueue(int *arr, int rear)
{
    int i;
    
    // If the queue is not empty, print the elements
    if (rear != 0)
    {
        for (i = 0; i < rear; i++)
        {
            printf("%d ", arr[i]);  // Print each element in the queue
        }
    }
    else
    {
        printf("Empty Queue");  // If the queue is empty, print this message
    }
    printf("\n");
}

int main()
{
    int front, rear, element;
    int arr[N];  // Declaring the queue array of size N

    initQueue(&front, &rear);  // Initialize the queue
    
    // You can uncomment these lines to test enqueue and dequeue operations
    // enqueue(arr, &rear, 10);  // Enqueue element 10
    // enqueue(arr, &rear, 20);  // Enqueue element 20
    // enqueue(arr, &rear, 30);  // Enqueue element 30
    
    printQueue(arr, rear);  // Print the queue
    
    // Uncomment to test dequeue
    // dequeue(arr, &rear, &element);  // Dequeue an element
    // printQueue(arr, rear);  // Print the queue after dequeue
    // dequeue(arr, &rear, &element);  // Dequeue another element
    // dequeue(arr, &rear, &element);  // Dequeue another element
    
    // Check if the queue is empty or full
    printf("%d\n", isEmptyQueue(rear));  // Print if the queue is empty (1: Yes, 0: No)
    printf("%d\n", isfullQueue(rear));   // Print if the queue is full (1: Yes, 0: No)
}
