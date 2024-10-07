// Circular Queue

#include <stdio.h>
#define N 10

void initQueue(int* front, int* rear)
{
    *front = 0;
    *rear = 0;
}

int isEmptyQueue(int front, int rear)
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullQueue(int front, int rear){
    if(rear+1 % N == front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int* arr, int* rear,int* front, int element){
    if(isFullQueue(*rear, *rear)){
        printf("Queue is full\n");
    }
    else{
        arr[*rear] = element;
        *rear = (*rear + 1) % N;
    }
}

void dequeue(int* arr, int* rear, int* front, int* element){
    if(isEmptyQueue(*front, *rear)){
        printf("Queue is empty\n");
    }
    else{
        *element = arr[*front];
        *front = (*front + 1) % N;
    }
}

void printQueue(int* arr, int front, int rear){
    if(isEmptyQueue(front, rear)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue: ");
        for(int i = front; i < rear; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int front, rear, element;
    int arr[N];

    // Code to drive the queue

    initQueue(&front, &rear);
    enqueue(arr, &rear, &front, 10);
    enqueue(arr, &rear, &front, 20);
    enqueue(arr, &rear, &front, 30);
    printQueue(arr, front, rear);
    dequeue(arr, &rear, &front, &element);
    printf("Dequeued: %d\n", element);
    printQueue(arr, front, rear);

    printf("%d \n", isEmptyQueue(front, rear));
    printf("%d \n", isFullQueue(front, rear));
    
    return 0;
}