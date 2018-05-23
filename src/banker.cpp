#include <iostream>
#include <ctime>
#include <cstdlib>

const int ProcessesLen = 5;
const int ResourcesLen = 3;

//returns a number between 1 - 100
int randomVal() {	
	return (rand() % 100) + 1;
}

int** calculateNeed(int max[ProcessesLen][ResourcesLen], int alloc[ProcessesLen][ResourcesLen]) {
	int** need = 0;
	need = new int*[ProcessesLen];
	for (int i = 0; i < ProcessesLen; i++) {
		need[i] = new int[ResourcesLen];
		for (int j = 0; j < ResourcesLen; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	return need;
}

bool isSafe(int processes[ProcessesLen], int available[ProcessesLen], int max[ProcessesLen][ResourcesLen], int alloc[ProcessesLen][ResourcesLen]) {
	int** need = calculateNeed(max, alloc);
	bool done[ProcessesLen] = { false }; //! to keep track of finished processes 
	int safeSequence[ProcessesLen];
	int work[ResourcesLen];
	int c = 0; //! to keep track of processes 

	for (int i = 0; i < ResourcesLen; i++) {
		work[i] = available[i];
	}

	while (c < ProcessesLen) {
		bool f = false;
		for (int i = 0; i < ProcessesLen; i++) {
			if (!done[i]) {
				int j = 0;
				while (j < ResourcesLen) {					
					if (need[i][j] > work[j]) {
						f = false;
						break;
					}
					j++;
				}
				if (j == ResourcesLen) {
					for (int k = 0; k < ResourcesLen; k++) {
						work[k] += alloc[i][k];
					}
					safeSequence[c++] = i+1;
					done[i] = true;
					f = true;
				}
			}
		}
		if (f == false) {
			return false;
		}
	}

	std::cout << "--- Safe Sequence ---" << std::endl;
	for (int k = 0; k < ProcessesLen; k++) {
		std::cout << "P" << safeSequence[k] << " ";
	}
	std::cout << std::endl;

	return true;
}