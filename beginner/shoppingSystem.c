/*
Attributes: customerInfo, productDetail, cartContent, orderHistory
Objects: Customer, Product, ShoppingCart, Order
Methods: addign, removing from to/from cart, placing orders, tracking order history.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

// Define objects
struct Customer {
	char accountName[50];
	char email[30];
	char addresse[30];
};

struct Product {
	char productId[30];
	char productName[20];
	double quantity;
};

struct ShoppingCart {
	char shoppingCart[100];
};

struct Order {
	int orderCount;
	char date[30];
}


//Function add product to Cart
void addToCart() {

}

// Fuction remove from cart based on either id or name
void removeFromCart() {

}

//Function update the Cart quantity
void updateCart() {

}

// Function Orderhistory (number of times your have bought)
void Orderhistory() {

}

int main() {

}
