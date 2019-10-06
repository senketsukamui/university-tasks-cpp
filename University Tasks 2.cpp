#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.h"
using namespace std;
int minimalElementIndex(vector<double> elements) {
	return distance(elements.begin(), min_element(elements.begin(), elements.end()));

}
void rangeBasedFor(vector<int> const& input) {
	for (auto const& i : input) {
		cout << i << " ";
	}
}

void calculateFunc(int n) {
		vector <int> output;
		for (int i = 1; i <= n; i++)
		{
			int res = 0;
			for (int j = i; j <= i * 2; j++)
			{
				res += j * j;
			}
			output.push_back(res);
		}

		for (int i = 0; i < output.size(); i++)
		{
			cout << output[i] << " ";
		}

}

vector<int> calculateGeneticDiffer(vector<char> elements) {
	vector<int> differ(elements.size());
	for (unsigned int i = 0; i < differ.size(); i++) {
		int countG = count(elements.begin(), elements.begin() + i, 'G');
		int countC = count(elements.begin(), elements.begin() + i, 'C');
		differ[i] = countG - countC;
	}
	return differ;
}

bool palyndromeCheck(vector<int> elements) {
	vector<int> elementsCopy(elements.size());
	for (int i = 0; i < elements.size(); i++) {
		elementsCopy.push_back(elements[i]);
	}
	reverse(elementsCopy.begin(), elementsCopy.end());
	bool palyndromeFlag = false;
	for (unsigned int i = 0; i < elements.size(); i++) {
		if (elements[i] != elementsCopy[i]) {
			palyndromeFlag = true;
			break;
		}
	}
	return !palyndromeFlag;
}
int main() {
	calculateFunc(10);
}