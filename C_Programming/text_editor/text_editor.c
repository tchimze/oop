#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000

void saveToFile(const char* text, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) { 
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fputs(text, file);
    fclose(file);
}

int main() {
    char text[MAX_TEXT_SIZE] = "";
    char choice;
    char filename[100];
    const char *extension = ".txt";

    printf("Simple Text Editor\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. New Text\n");
        printf("2. Edit Text\n");
        printf("3. Save Text\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Enter new text:\n");
                scanf(" %[^\n]", text);
                break;
            case '2':
                printf("Current Text:\n%s\n", text);
                printf("Enter new text:\n");
                scanf(" %[^\n]", text);
                break;
            case '3':
                printf("Enter the filename: ");
                scanf("%s", filename);
                if(strstr(filename, extension) == NULL){
                    strcat(filename, extension);
                }
                saveToFile(text, filename);
                printf("Text saved to %s.\n",filename);    
                break;
            case '0':
                printf("Exiting the text editor. \n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
