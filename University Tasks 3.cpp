// University Tasks 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
void rangeBasedFor(std::vector<std::string> const& input) {
	for (auto const& i : input) {
		std::cout << i << " ";
	}
}

void calcBase(int n, int num) {
	if (num == 0) {
		return;
	}
	int finalNum = 0;
	int i;
	for (i = 0; num >= n - 1; i++) {
		finalNum += (num % n) * pow(10, i);
		num /= n;
	}
	finalNum += num * pow(10, i++);
	std::cout << finalNum;
}


void split(std::string line, char delimeter) {
	std::vector<std::string> output;
	std::string element = "";
	for (unsigned int i = 0; i < line.size(); i++) {
		bool flag = false;
		if (line[i] == delimeter) {
			output.push_back(element);
			element = "";
			flag = true;
		}

		if (!flag) {
			element += line[i];
		}
	}
	output.push_back(element);
	rangeBasedFor(output);
}
void swap(int& a, int& b) {
	int t = 0;
	t = a;
	a = b;
	b = t;
}
void doNothing() {
	std::string  a = "This function is more useless then me";
}
void newBubbleSort(std::vector<int> numbersToSort) {
	for (unsigned int i = 0; i < numbersToSort.size(); ++i) {
		for (unsigned int j = numbersToSort.size() - 1; j > i; --j) {
			numbersToSort[i] > numbersToSort[j] ? swap(numbersToSort[i], numbersToSort[j]) : doNothing();
		}
	}
	for (unsigned int i = 0; i < numbersToSort.size() ; i++) {
		std::cout << numbersToSort[i] << " ";
	}
	
}
int main()
{
	newBubbleSort({ 1, 2, 5, 8, 11, 43, 4, 9 });
}

