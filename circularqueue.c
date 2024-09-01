#include <stdio.h>
#include <stdlib.h>

int isFull(int SIZE, int front, int rear) {
    return ((front == 0 && rear == SIZE - 1) || ((rear + 1) % SIZE == front));
}

int isEmpty(int front) {
    return (front == -1);
}

void enqueue(int value, int queue[], int SIZE, int front, int rear) {
    if (isFull(SIZE, front, rear)) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) { // Inserting the first element
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0; // Wrap around to the start of the array
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(int queue[], int front, int rear, int SIZE) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1;

    if (front == rear) { // Queue has only one element
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0; // Wrap around to the start of the array
    } else {
        front++;
    }

    return data;
}

void display(int front, int rear, int queue[], int SIZE) {
    int i;
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("\nEnter size of the array: ");
    scanf("%d", &size);

    int queue[size];
    int front = -1, rear = -1;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value, queue, size, front, rear);
                break;
            case 2:
                value = dequeue(queue, front, rear, size);
                if (value != -1) {
                    printf("Dequeued %d\n", value);
                }
                break;
            case 3:
                display(front, rear, queue, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
