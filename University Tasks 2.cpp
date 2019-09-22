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

vector<int> calculateGeneticDiffer(vector<char> elements) {
	vector<int> differ(elements.size());
	for (unsigned int i = 0; i < differ.size(); i++) {
		int countG = count(elements.begin(), elements.begin() + i, "G");
		int countC = count(elements.begin(), elements.begin() + i, "C");
		differ[i] = countG - countC;
	}
	return differ;
}
int calculateFunction(int N) {
	return 0;
}

bool palyndromeCheck(vector<int> elements) {
	vector<int> elementsCopy(elements.size());
	for (int i = 0; i < elements.size(); i++) {
		elementsCopy.push_back(elements[i]);
	}
	reverse(elementsCopy.begin(), elementsCopy.end());
	bool palyndromeFlag = false;
	for (int i = 0; i < elements.size(); i++) {
		if (elements[i] != elementsCopy[i]) {
			palyndromeFlag = true;
			break;
		}
	}
	if (palyndromeFlag == true) {
		return false;
	}
	else {
		return true;

	}
}

int main()
{
	rangeBasedFor(calculateGeneticDiffer({'A', 'G', 'C', 'C', 'A', 'G', 'C', 'G'}));
	// cout << minimalElementIndex({ 2, 6, 8, 1, 5, 1 });
	return 0;
}

