#include <stdio.h>
#define N 10  // Maximum size of the queue

// Initialize the front and rear pointers
void initQueue(int* front, int* rear) {
    *front = 0;
    *rear = 0;
}

// Check if the queue is empty (when front equals rear)
int isEmptyQueue(int front, int rear) {
    if (front == rear)
        return 1;  // Queue is empty
    else 
        return 0;  // Queue has elements
}

// Check if the queue is full (when rear reaches the maximum size)
int isFullQueue(int rear) {
    return rear == N;  // Return 1 if full, otherwise 0
}

// Enqueue an element to the queue
void enqueue(int* arr, int* rear, int element) {
    if (isFullQueue(*rear)) {
        printf("Queue is full\n");  // Overflow condition
    } else {
        arr[*rear] = element;  // Insert element at the rear
        *rear = *rear + 1;     // Increment rear pointer
    }
}

// Dequeue an element from the queue
void dequeue(int *arr, int* front, int* element) {
    *element = arr[*front];  // Store the front element to return
    *front = *front + 1;     // Increment front pointer
}

// Print the current state of the queue
void printQueue(int *arr, int front, int rear) {
    if (isEmptyQueue(front, rear)) {
        printf("Queue is empty\n");  // Empty queue
    } else {
        printf("Queue: ");
        for (int i = front; i < rear; i++) {  // Loop through queue elements
            printf("%d ", arr[i]);  // Print each element
        }
        printf("\n");
    }
}

int main() {
    int front, rear, element;
    int arr[N];  // Declare the queue array with size N
    
    initQueue(&front, &rear);  // Initialize queue pointers
    
    // Add elements to the queue
    enqueue(arr, &rear, 10);
    enqueue(arr, &rear, 20);
    enqueue(arr, &rear, 30);
    
    printQueue(arr, front, rear);  // Print current queue

    // Dequeue an element and print the updated queue
    dequeue(arr, &front, &element);
    printf("Dequeued: %d\n", element);  // Print dequeued element
    printQueue(arr, front, rear);

    // Test underflow (trying to dequeue more than available)
    dequeue(arr, &front,  &element);
    dequeue(arr, &front,  &element);
    if (!isEmptyQueue(front, rear)) {  // Ensure queue is not empty before dequeueing
        dequeue(arr, &front,  &element);
    } else {
        printf("Queue is empty, cannot dequeue\n");
    }

    // Test overflow (trying to enqueue more than the queue's capacity)
    for (int i = 0; i < 7; i++) {  // Fill up the queue
        enqueue(arr, &rear, i * 10);
    }
    enqueue(arr, &rear, 999);  // This should print "Queue is full" due to overflow

    return 0;  // Program ends
}
