#include<iostream>
#include<iomanip>
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
	//testing reformatting of output
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << " The value of temp now changes to : " << sqrt(temp) << endl;

	cout << setiosflags(ios::left);
	cout.width(20);

	int number = 0;

	for (number = 1; number <= 10; number = number + 1) {
		cout.width(20);
		cout << "number with following precision : " << sqrt(number) << endl;
	}
}