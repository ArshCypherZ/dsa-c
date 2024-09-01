#include <stdio.h>
#include <stdlib.h>

int isFull(int SIZE, int front, int rear) {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty(int front) {
    return (front == -1);
}

void insertFront(int value, int deque[], int SIZE, int *front, int *rear) {
    if (isFull(SIZE, *front, *rear)) {
        printf("Deque is full\n");
        return;
    }

    if (*front == -1) {  // If deque is initially empty
        *front = 0;
        *rear = 0;
    } else if (*front == 0) {  // Circular condition
        *front = SIZE - 1;
    } else {
        (*front)--;
    }

    deque[*front] = value;
    printf("Inserted %d at front\n", value);
}

void insertRear(int value, int deque[], int SIZE, int *front, int *rear) {
    if (isFull(SIZE, *front, *rear)) {
        printf("Deque is full\n");
        return;
    }

    if (*front == -1) {  // If deque is initially empty
        *front = 0;
        *rear = 0;
    } else if (*rear == SIZE - 1) {  // Circular condition
        *rear = 0;
    } else {
        (*rear)++;
    }

    deque[*rear] = value;
    printf("Inserted %d at rear\n", value);
}

void deleteFront(int deque[], int SIZE, int *front, int *rear) {
    if (isEmpty(*front)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted %d from front\n", deque[*front]);

    if (*front == *rear) {  // Deque has only one element
        *front = -1;
        *rear = -1;
    } else if (*front == SIZE - 1) {
        *front = 0;  // Circular condition
    } else {
        (*front)++;
    }
}

void deleteRear(int deque[], int SIZE, int *front, int *rear) {
    if (isEmpty(*front)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted %d from rear\n", deque[*rear]);

    if (*front == *rear) {  // Deque has only one element
        *front = -1;
        *rear = -1;
    } else if (*rear == 0) {
        *rear = SIZE - 1;  // Circular condition
    } else {
        (*rear)--;
    }
}

void display(int deque[], int SIZE, int front, int rear) {
    int i;
    if (isEmpty(front)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are:\n");

    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } else {
        for (i = front; i < SIZE; i++) {
            printf("%d ", deque[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of the deque: ");
    scanf("%d", &size);

    int deque[size];
    int front = -1, rear = -1;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(value, deque, size, &front, &rear);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value, deque, size, &front, &rear);
                break;
            case 3:
                deleteFront(deque, size, &front, &rear);
                break;
            case 4:
                deleteRear(deque, size, &front, &rear);
                break;
            case 5:
                display(deque, size, front, rear);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
