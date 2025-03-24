#include<iostream>
#include<cmath>

using namespace std;

void static findQuadRoots() {
	double a = 0.0, b = 0.0, c =0.0;
	double root = 0.0;
	double x1 = 0.0, x2 = 0.0, x = 0.0;

	cout << "Enter the value of a,b & c : " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "Value of a,b,c == " << a << " " << b << " " << c << endl;
	
	root = ((b*b) - (4*a*c));
	cout << "Root = " << root << endl;
	if (a == 0) {
		x = -c / b;
		cout << "Only one root exists = " << x << endl;
	}
	else {
		if (root > 0) {
			x1 = (-b - sqrt(root)) / (2 * a);
			x2 = (-b + sqrt(root)) / (2 * a);

			cout << "The roots are " << x1 << " and " << x2 << endl;
		}
		else {
			if (root == 0) {
				x = -b / (2 * a);

				cout << "Only one root exists = " << x << endl;
			}
			else {
				if (root < 0) {
					cout << "This equation has complex roots \n";

					double real = -b / (2.0 * a);
					double im = sqrt(fabs(root)) / (2 * a);

					cout << "x1 = " << real << " + i" << im << endl;
					cout << "x2 = " << real << " - i" << im << endl;
				}
			}
		}

	}

	

}