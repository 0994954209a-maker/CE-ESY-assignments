#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    char buffer[MAX_SIZE];
    int head;
    int tail;
    int size;
} RingQueue;

void initialize(RingQueue *q) {
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

int isVacant(const RingQueue *q) {
    return q->size == 0;
}

int isComplete(const RingQueue *q) {
    return q->size == MAX_SIZE;
}

void insert(RingQueue *q, char element) {
    if (isComplete(q)) {
        printf("Buffer full\n");
        return;
    }
    q->buffer[q->tail] = element;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->size++;
}

char removeElement(RingQueue *q) {
    if (isVacant(q)) {
        printf("Buffer empty\n");
        return '\0';
    }
    char element = q->buffer[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return element;
}

int main() {
    RingQueue q;
    initialize(&q);

    char userInput[50];
    printf("Enter your name: ");
    scanf("%49s", userInput);
    strcat(userInput, "CE-ESY");

    int length = strlen(userInput);
    for (int i = 0; i < length; i++) {
        insert(&q, userInput[i]);
    }

    while (!isVacant(&q)) {
        char character = removeElement(&q);
        printf("%c", character);
    }
    
    return 0;
}
