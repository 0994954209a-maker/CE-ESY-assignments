# Ring Queue Implementation in C

A simple circular buffer (ring queue) implementation in C that demonstrates basic queue operations with fixed-size storage.

## Description

This program implements a circular buffer data structure that can store characters with a maximum capacity of 20 elements. It demonstrates:
- Circular buffer/queue operations
- First-In-First-Out (FIFO) behavior
- Buffer overflow and underflow protection

## Features

- **Initialize**: Setup a new empty ring queue
- **Insert (Write)**: Add elements to the rear of the queue
- **Remove (Read)**: Remove and return elements from the front of the queue
- **Status checks**: Check if the buffer is full or empty
- **Overflow protection**: Prevents inserting when buffer is full
- **Underflow protection**: Prevents removing from empty buffer

## Functions

| Function | Description |
|----------|-------------|
| `initialize()` | Initializes a new ring queue with empty state |
| `isVacant()` | Returns 1 if queue is empty, 0 otherwise |
| `isComplete()` | Returns 1 if queue is full, 0 otherwise |
| `insert()` | Adds a character to the queue (writes to rear) |
| `removeElement()` | Removes and returns a character from the queue (reads from front) |

## Data Structure

```c
typedef struct {
    char buffer[MAX_SIZE];  // Storage array (MAX_SIZE = 20)
    int head;               // Points to front of queue
    int tail;               // Points to rear of queue
    int size;               // Current number of elements
} RingQueue;
