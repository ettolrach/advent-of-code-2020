#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> get_numbers_from_file(std::string path) {
	std::vector<int> vectorToReturn;
	std::ifstream filestream(path);
	std::string currentNumberString;
	while (std::getline(filestream, currentNumberString)) {
		vectorToReturn.push_back(std::stoi(currentNumberString));
	}
	return vectorToReturn;
}

int get_summing_number(std::vector<int> numbersToCheck, int posCheckAgainst) {
	int checkAgainst = numbersToCheck[posCheckAgainst];
	for (int i = posCheckAgainst + 1; i < numbersToCheck.size(); i++) {
		if (checkAgainst + numbersToCheck[i] == 2020) {
			return numbersToCheck[i];
		}
	}
	return -1;
}

int main() {
	std::string filename = "input.txt";
	std::vector<int> numbers = get_numbers_from_file(filename);
	int solution[2] = {0, 0};
	int index;

	for (int i = 0; i < numbers.size(); i++) {
		int result = get_summing_number(numbers, i);
		if (result != -1) {
			solution[0] = numbers[i];
			solution[1] = result;
			index = i;
		}
	}

	int answer = solution[0] * solution[1];
	std::cout << std::to_string(answer) << std::endl;
	return 0;
}
