#include<iostream>

using namespace std;

void static EuclidAlgoToFindGCD() {
	int m = 0, n = 0;
	int temp = 0;
	cout << "Enter two int values where first value is smaller than second: " << endl;
	cin >> m;
	cin >> n;
	cout << "Values entered : " << m << ", " << n << endl;
	do {
		//while (m <= n) {
			n -= m;
			temp = m;
			m = n;
			n = temp;
		//}
	} while (m > 0 && m <= n);

	cout << "Greatest common denominator for the input values is : " << temp << endl;
}