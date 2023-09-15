
#include <iostream>
#include <cmath>
#include <memory>
using namespace std;


void exceptionHandling() {
	int numerator = 10;
	int denominator = 0;

	try {
		if (denominator == 0) {
			throw runtime_error("Division by zero");
		}

		int result = numerator / denominator;
		cout << "Result: " << result << endl;
	} catch (const exception& e) {
		cerr <<"Error: "<<e.what() << endl;
	}
}


// Exercise on Exeptional Handling
void squareRoot() {
	// To calculate the square root of negative number
	double num; // Number to find the square root of

	printf("Enter the number: ");
	cin >> num;

	try
	{
		if (num < 0) {
			throw runtime_error("Square root of a negative number");
		}

		double result = sqrt(num);
		cout << "The square root of " << num << " is " << result << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

}


// Smart Pointers, Examples here
// Memory mangement is vital in C++ and smart pointers help
// manage pointers efficiently and automatically.


// Unique Pointers Examples
void uniquePointer() {
	// Dynamically allocated memory using smart pointers.

	// Create a unique_ptr to manage an integer
	auto numPtr = make_unique<int>(42);

	// Access and modify the integer
	*numPtr += 10;

	cout << "Value: " << *numPtr << endl;
}

// Exercise on Pointer Types

class MyObject{
	public:
	MyObject() {
		cout << "MYObject created" << endl;
	}

	~MyObject() {
		cout << "MyObject destroyed" << endl;
	}
};

// demostrating pointer types
void pointerTypes() {
	// Create a share_ptr to MYObject.
	shared_ptr<MyObject> p1(new MyObject());

	// The reference count of p1 us now 1.
	cout << "Reference count of p1: " << p1.use_count() << endl;

	// Create another shared_ptr to the same MyObject.
	shared_ptr<MyObject> p2(p1);

	// The reference count od p1 is now 2.
	cout << "Reference count of p1: " << p1.use_count() << endl;

	// Create a weak_ptr to the MyObject.
	weak_ptr<MyObject> p3(p1);

	//The weak pointer does not affect the reference count of p1.
	// The reference count of p1 is still 2.
	cout << "Reference count of p1: " << p1.use_count() << endl;

	// Release the second shared_ptr.
	p2.reset();

	// The reference count of p1 is now 1.
	cout << "Reference count of p1: " << p1.use_count() << endl;

	// Release the first shared_ptr.
	p1.reset();

	// The MyObject is now destroyed.
	cout << "MyObject destroyed" << endl;

	// The weak_ptr is now invalid.
	if (p3.expired()) {
		cout << "p3 is expired" << endl;
	} else {
		cout << "P3 is not epired" << endl;
	}
}

/* TODO: Implement a shopping cart, that allows adding,removing products while keeping track of the total cost(read).*/


int main() {
	pointerTypes();

	return 0;
}



