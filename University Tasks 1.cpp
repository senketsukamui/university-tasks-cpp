

#include <iostream>
using namespace std;
bool isPrime(int n) {
	bool isPrime;
	int d = 2;
	while (n % d != 0) {
		d++;
	}
	return isPrime = (d == n);
}
void printPrimes(int m) {
	for (int i = 1; i < m; i++) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
}
int printBinary(int m) {
	int output = 0, k = 1;

	while (m)
	{
		output += (m % 2) * k;
		k *= 10;
		m /= 2;
	}

	return output;
	
}
void printPrimesRev(int m) {
	for (int i = m; i > 1; i--) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
}
void functionsManager(int m) {
	cout << "Welcome to functions manager. Please enter number from 1 to 4 to choose function" << "\n";
	cout << "1. Prime check" << "\n";
	cout << "2. Print all prime numbers from 1 to number you chose in function" << "\n";
	cout << "3. Same as in the 2, only in reverse order" << "\n";
	cout << "4. Transform number in function to binary form" << "\n";
	int functionNumber;
	cin >> functionNumber;
	switch (functionNumber)
	{
	case 1:
	{
		cout << isPrime(m);
		break;
	}
	case 2:
	{
		printPrimes(m);
		break;
	}
	case 3:
		printPrimesRev(m);
		break;
	case 4:
		cout << printBinary(m);
		break;
	default:
		cout << "You typed wrong number. Try again.";
		break;
		
	}
}
int main()
{
	functionsManager(6);
}
