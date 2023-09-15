#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for Huffman tree node
struct Node
{
    char character;
    char frequency;
    struct Node *left;
    struct Node *right;
};

// Priority Queue (min-heap) structure
struct PriorityQueue {
    struct Node **nodes;
    int size;
};

// Function to enqueue a node into the priority queue
void Enqueue(struct PriorityQueue *queue, struct Node *node) {
    //Todo Implement Enqueue functionality
}

// Function to dequeue a node into the priority queue
struct Node *Dequeue(struct PriorityQueue *queue) {
    //Todo Implement Dequeue functionality
}

