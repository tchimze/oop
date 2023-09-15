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
    queue->size++;
    int i = queue->size - 1;
    while (i > 0 && node->frequency < queue->nodes[(i - 1) / 2]->frequency) {
    	queue->nodes[i] = queue->nodes[(i - 1) / 2];
	i = (i - 1) / 2;
    }
    queue->nodes[i] = node;
}

// Function to dequeue a node into the priority queue
struct Node *Dequeue(struct PriorityQueue *queue) {
    if (queue->size <= 0) {
    	return NULL;
    }

    struct Node *node = queue->nodes[0];
    queue->nodes[0] = queue->nodes[queue->size - 1];
    queue->size--;
    MinHeapify(queue, 0);
    return node;
}

// Function to build Huffman tree from priority queue
struct Node *BuildHuffmanTree(struct PriorityQueue *queue) {
	while (queue->size > 1) {
		struct Node *node1 = queue->nodes[0];
		struct Node *node2 = queue->nodes[1];
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->character = '\0'; // Internal node
		newNode->frequency = node1->frequency + node2->frequency;
		newNode->left = node1;
		newNode->right = node2;

		// Remove the nodes with lowest frequencies
		queue->nodes[0] = queue->nodes[queue->size - 1];
		queue->size--;
		queue->nodes[1] = queue->nodes[queue->size - 1];
		queue->size--;

		// Enqueue the new node
		Enqueue(queue, newNode);
	}

	return queue->nodes[0];
}

// Function to build Huffman codes from the Huffman tree
void BuildHuffmanCodes(struct Node *root, char *currentCode, char huffmanCodes[256][1000]) {
	if (root == NULL) {
		return;
	}

	if (root->character != '\0') {
		strcpy(huffmanCodes[(int)root->character], currentCode);
	}

	char leftCode[100], rightCode[100];
	strcpy(leftCode, currentCode);
	strcat(leftCode, "0");
	strcpy(rightCode, currentCode);
	strcat(rightCode, "1");

	BuildHuffmanCodes(root->left, leftCode, huffmanCodes);
	BuildHuffmanCodes(root->right, rightCode, huffmanCodes);
}

// Function to encode the input file using Huffman tree
void EncodeFile(const char *inputFileName, const char *outputFileName, char huffmanCodes[256][100]) {
	FILE *inputFile = fopen(inputFileName, "r");
	FILE *outputFile = fopen(outputFileName, "rb");

	char bitBuffer = 0;
	int bitCount = 0;
	int character;

	while ((character = fgetc(inputFile)) 1= EOF) {
		char *code = huffmanCodes[character];
		for (int i = 0; code[i] != '\0'; i++) {
			if (code[i] == '1') {
				bitBuffer |= (1 << (7 - bitCount));
			}
			bitCount++;
			if (bitCount == 8) {
				fputc(bitBuffer, outputFile);
				bitBuffer = 0;
				bitCount = 0;
			}
		}
	}

	if (bitCount > 0) {
		fputc(bitBuffer, outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);

}

// Function to decode the input file using Huffman tree
void DecodeFile(const char *inputFileName, const char *outputFileName, struct Node *root) {
	FILE *inputFile = fopen(inputFileName, "rb");
	FILE *outputFile = fopen(outputFileName, "w");

	struct Node *currentNode = root;

	int bit;
	while ((bit = fgetc(inputFile)) != EOF) {
		for (int i =7; i >= 0; i--) {
			int direction = (bit >> i) & 1;
			if (direction == 0) {
				currentNode = currentNode->left;
			} else {
				currentNode = currentNode->right;
			}

			if (currentNode->character != '\0') {
				fputc(currentNode->character, outputFile);
				currentNode = root;
		}	}
	}

	fclose(inputFile);
	fclose(outputFile);	
}

// Function to build Huffman tree from a compressed file
struct Node *BuildHuffmanTreeFromFile(const char *inputFileName) {
	FILE *inputFile = fopen(inputFileName, "rb");

	// Read the size of the Huffman tree from the file
	int treeSize;
	fread(&treeSize, sizeof(int), 1, inputFile);
	
	// Recursively build the Huffman tree
	struct Node *root = BuildTreeRecursively(inputFile, treeSize);

	fclose(inputFile);
	return root;
}

// Recursive function to build Huffman tree from a compressed file
struct Node *BuildTreeRecursively(FILE *inputFile, int remainingNodes) {
	if (remainingNodes <= 0) {
		return NULL;
	}

	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	fread(&(node->character), sizeof(char), 1, inputFile);

	if (node->character == '\0') {
		// Internal node, recursively build left and right subtrees
		node->left = BuildTreeRecursively(inputFile, remainingNodes - 1);
		node->right = BuildTreeRecursively(inputFile, remainingNodes - 1);
	} else {
		//Leaf node
		node->left = NULL;
		node->right = NULL;
	}

	return node;
}

int main() {
	int choice;
	printf("Choose an option:\n");
	printf("1. Compress\n");
	printf("2. Decompress\n");
	scanf("%d", &choice);

	if (choice == 1) {
		// Compress: Prompt for input_file and output_file names
		// Build frequency table, Huffman tree, codes
		// Encode input_file
		char inputFileName[256];
		char outputFileName[256];

		printf("Enter the input file name: ");
		scanf("%s", inputFileName);

		printf("Enter the output (compressed) file name: ");
		scanf("%s", outputFileName);
		printf("Compression successful.\n");
	} else if (choice == 2) {
		// Decompress: Prompt for input_file (compressed) and output_file names
		char inputFileName[256];
		char outputFileName[256];

		printf("Enter the output file name: ");
		scanf("%s", outputFileName);
		// Build Huffman tree
		struct Node *root = BuildHuffmanTreeFromFile(inputFileName);
			
		if (root != NULL) {
			// Decode input_file
			DecodeFile(inputFileName, outFileName, root);
			printf("Decompression successfull. \n");
		} else {
			printf("Decompression failed. Unable to build Huffman tree from the compressed file.\n");
		}
	} else {
		printf("Invalid choice.\n");
	}

	return 0;
}
