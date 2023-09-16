#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Define structures for objects
struct Car {
	char* name;
	char* model;
};

struct Book {
	char* title;
	char* author;
};

struct Smartphone {
	char* brand;
	char* model;
};

struct Chair {
	char* material;
	char* color;
};

struct Dog {
	char* breed;
	char* name;
};

// Function to create an object of type Car
struct Car* createCar(const char* name, const char* model) {
	struct Car* car = (struct Car*)malloc(sizeof(struct Car));
	car->name = strdup(name);
	car->model = strdup(model);

	return car;
}

// Function to create an object of type Book
struct Book* createBook(const char* title, const char* author) {
	struct Book* book = (struct Book*)malloc(sizeof(struct Book));
	book->title = strdup(title);
	book->author = strdup(author);

	return book;
}

// Function to create an object od type Smartphone
struct Smartphone* createSmartphone(const char* brand, const char* model) {
	struct Smartphone* phone = (struct Smartphone*)malloc(sizeof(struct Smartphone));
	phone->brand = strdup(brand);
	phone->model = strdup(model);

	return phone;
}

// Function to create an object of type Chair
struct Chair* createChair(const char* material, const char* color) {
	struct Chair* chair = (struct Chair*)malloc(sizeof(struct Chair));
	chair->material = strdup(material);
	chair->color = strdup(color);

	return chair;
}

//Function to create an object of type Dog
struct Dog* createDog(const char* breed, const char* name) {
	struct Dog* dog = (struct Dog*)malloc(sizeof(struct Dog));
	dog->breed = strdup(breed);
	dog->name = strdup(name);

	return dog;

}

int main() {
	// Create object
	struct Car* myCar = createCar("NyCar", "Sedan");
	struct Book* greatBook = createBook("Great Book", "Willian Shakespeare");
	struct Smartphone* myPhone = createSmartphone("NyPhone", "Iphone");
	struct Chair* comfyChair = createChair("Leather", "Black");
	struct Dog* rover = createDog("Golden Retriever", "Rover");

	// Display objects
	printf("Car: %s, Model: %s\n", myCar->name, myCar->model);
	printf("Book: %s, Author: %s\n", greatBook->title, greatBook->author);
	printf("Smartphone: %s, Model: %s\n", myPhone->brand, myPhone->model);
	printf("Chair: %s, Color: %s\n", comfyChair->material, comfyChair->color);
	printf("Dog: %s, Breed: %s\n", rover->name, rover->breed);

	// Free allocated memory
	free(myCar->name);
	free(myCar->model);
	free(myCar);

	free(greatBook->title);
	free(greatBook->author);
	free(greatBook);

	free(myPhone->brand);
	free(myPhone->model);
	free(myPhone);

	free(comfyChair->material);
	free(comfyChair->color);
	free(comfyChair);

	free(rover->name);
	free(rover->breed);
	free(rover);

	return 0;
}


