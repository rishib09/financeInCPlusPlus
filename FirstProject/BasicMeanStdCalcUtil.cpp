#include<iostream>
#include<cmath>

using namespace std;

void fill_up(double a[], int& size) {
	cout << "Enter size " << endl;
	cin >> size;
	cout << "Now Enter numbers: " << endl;

	for (int i = 1; i <= size; i++) {
		cin >> a[i - 1];
	}
}

void display(double a[], int& size) {
	cout << "You have entered the following values in the array : " << endl;

	for (int i = 1; i <= size; i++) {
		cout << a[i - 1] << endl;
	}
}

double average(double a[], int size) {
	double av = 0.0;
	for (int i = 1; i <= size; i++) {
		av += a[i - 1];
	}
	double mean = av / size;

	cout << "The average is " << mean << endl;

	return av;
}

double stan_dev(double a[], int size, double mean) {
	double sum = 0.0;
	for (int i = 1; i <= size; i++) {
		sum += ((a[i - 1] * mean) * (a[i - 1] * mean));
	}

	double variance = sum / size;
	cout << "Standard Deviation : " << sqrt(variance) << endl;

	return 0;
}