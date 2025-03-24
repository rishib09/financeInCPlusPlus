#include<iostream>;
#include<cstdlib>;
using namespace std;

void static FindPrime() {
	unsigned int input, j;
	cout << "Enter Number : " << endl;
	cin >> input;

	for (j = 2; j <= input / 2; j++) {
		cout << "For loop iterating at j = " << j << endl;

		if (input % j == 0) {
			cout << "Input number is not prime as it is divisible by " << j << endl;
			exit(0);
		}
	}
	cout << input << " is a prime number!!" << endl;
}