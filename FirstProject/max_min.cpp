#include<iostream>
#include<algorithm>
#include "max_min.h";

using namespace std;

int Maximum(matrix A) {
	int maximum = A[0];
	for (int i = 1; i <= dimen; i++) {
		maximum = maximum < A[i - 1] ? A[i - 1] : maximum;
	}

	return maximum;
}

int Minimum(matrix A) {
	int minimum = A[0];
	for (int i = 1; i <= dimen; i++) {
		minimum = minimum > A[i - 1] ? A[i - 1] : minimum;
	}

	return minimum;
}