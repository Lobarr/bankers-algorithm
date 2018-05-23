#include <iostream>
#include "src/banker.cpp"

int main() {
	
	// Given
	// int processes[ProcessesLen] = { 1, 2, 3, 4, 5 };
	// int available[ResourcesLen] = { 3,3,2 };
	// int max[ProcessesLen][ResourcesLen] = { { 7,5,3 },{ 3,2,2 },{ 9,0,2 },{ 2,2,2 },{ 4,3,3 } };
	// int alloc[ProcessesLen][ResourcesLen] = { { 0,1,0 },{ 2,0,0 },{ 3,0,2 },{ 2,1,1 },{ 0,0,0 } };

	// std::string status = isSafe(processes, available, max, alloc) ? "safe" : "unsafe";
	// std::cout << "Status: " << status << std::endl;
	
	
	//Random
	srand(time(0));
	int safe = 0;
	for (int i = 0; i < 100; i++) {
		int processes[ProcessesLen] = { 0, 1, 2, 3, 4 };
		int available[ResourcesLen];
		for (int j = 0; j < ResourcesLen; j++) {
			available[j] = randomVal();
		}

		int max[ProcessesLen][ResourcesLen];
		for (int j = 0; j < ProcessesLen; j++) {
			for (int k = 0; k < ResourcesLen; k++) {
			max[j][k] = randomVal();
			}
		}

		int alloc[ProcessesLen][ResourcesLen];
		for (int j = 0; j < ProcessesLen; j++) {
			for (int k = 0; k < ResourcesLen; k++) {
			alloc[j][k] = randomVal();
			}
		}


		if (isSafe(processes, available, max, alloc)) {
			safe++;
		}

		isSafe(processes, available, max, alloc);
	}

	std::cout << safe << " are safe" << std::endl;
	
	system("pause");
	return 0;
}