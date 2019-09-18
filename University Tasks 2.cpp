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

void calculateGeneticDiffer(vector<char> elements) {
	vector<int> count(elements.size());
	int countG = 0, countC = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			if (elements[j] == *"G") {
				countG++;
			}
			else if (elements[j] == *"C") {
				countC++;
				}
			count[i] = countG - countC;
			countC = 0;
			countG = 0;
		}
	}
	rangeBasedFor(count);
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
	calculateGeneticDiffer({'A', 'G', 'C', 'C', 'A', 'G', 'C', 'G'});
	// cout << minimalElementIndex({ 2, 6, 8, 1, 5, 1 });
	return 0;
}

