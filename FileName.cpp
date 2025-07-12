#include <iostream>
#include <string.h>
using namespace std;
// functions used
string decimalToBi(int x) {
	const int dividor = 2;
	string output;
	while (x > 0) {
		if (x % dividor) {
			output.insert(0, "1");
			x /= dividor;
		}
		else {
			output.insert(0, "0");
			x /= dividor;
		}
	}
	return output;
}
int biToDecimal(string x) {
	int var = 1;
	int output = 0;
	reverse(x.begin(), x.end());
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '1') {
			output = output + 1 * var;
			var *= 2;
		}
		else {
			var *= 2;
		}
	}
	return output;
}
string decimalToHexa(int x) {
	const int dividor = 16;
	string output;
	string hexaChars = "0123456789ABCDEF";
	int r, q; // r to store remainders, q to store qoutients
	q = r = x;
	while (q > 16) {
		r = q % dividor;
		q = q / dividor;
		output += hexaChars[r];
	}
	output += hexaChars[q];
	reverse(output.begin(), output.end());
	return output;
}
string decimalToOcta(int x) {
	const int dividor = 8;
	string output;
	string octaChars = "012345678";
	int r, q; // r to stor remainders, q to store qoutients
	q = r = x;
	while (q > dividor) {
		r = q % dividor;
		q = q / dividor;
		output += octaChars[r];
	}
	output += octaChars[q];
	reverse(output.begin(), output.end());
	return output;
}

long hexaToDecimal(string x) {
	reverse(x.begin(), x.end());
	int mp = 1;
	long output = 0;
	for (int i = 0; i < x.length(); i++) {
		char b = x[i];
		long a;

		if (b <= '9') {
			b = b - '0';
		}
		else {
			b = b - 55;  // 'A' - 10 is 55
		}
		a = b;
		a = a * mp;
		output = output + a;
		mp *= 16;
	}
	return output;
}

int octaToDecimal(string x) {
	reverse(x.begin(), x.end());
	int mp = 1;
	long output = 0;
	for (int i = 0; i < x.length(); i++) {
		char b = x[i];
		long a;
		b -= '0';
		a = b;
		a = a * mp;
		output = output + a;
		mp *= 8;
	}
	return output;
}
void main() {
	cout << "Please input the kind of converstion you want" << endl << endl;
	cout << "1- from decimal to bi" << endl;
	cout << "2- from bi to decimal" << endl;
	cout << "3- from decmimal to hexa" << endl;
	cout << "4- from decimal to octa" << endl;
	cout << "5- from hexa to decimal" << endl;
	cout << "6- from octa to decimal" << endl;
	
	int choise;
	cin >> choise;
	switch (choise) {
	case 1:
	{
		cout << "input decimal number: " << endl;
		int number;
		cin >> number;
		string s = decimalToBi(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	case 2:
	{
		cout << "input binary number: " << endl;
		string number;
		cin >> number;
		int s = biToDecimal(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	case 3: {
		cout << "input decimal number: " << endl;
		int number;
		cin >> number;
		string s = decimalToHexa(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	case 4: {
		cout << "input decimal number: " << endl;
		int number;
		cin >> number;
		string s = decimalToOcta(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	case 5:
	{
		cout << "input hexadecimal number: " << endl;
		string number;
		cin >> number;
		int s = hexaToDecimal(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	case 6:
	{
		cout << "input octa number: " << endl;
		string number;
		cin >> number;
		int s = octaToDecimal(number);
		cout << "Answer is: " << s << endl;
		break;
	}
	}
}
