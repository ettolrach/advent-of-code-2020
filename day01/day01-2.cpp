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

std::vector<int> get_sums(std::vector<int> numbersToCheck, int posToCheck, int depth, std::vector<int> previousIndicies = {}) {
	std::vector<int> toReturn;
	if (depth == 1) {
		int checkAgainst = 0;
		for (int i = 0; i < previousIndicies.size(); i++) {
			checkAgainst += numbersToCheck[previousIndicies[i]];
			toReturn.push_back(numbersToCheck[previousIndicies[i]]);
		}
		for (int j = posToCheck + 1; j < numbersToCheck.size(); j++) {
			if (checkAgainst + numbersToCheck[j] == 2020) {
				toReturn.push_back(numbersToCheck[j]);
				return toReturn;
			}
		}
		toReturn.clear();
	}
	else {
		for (int i = posToCheck; i < numbersToCheck.size(); i++) {
			previousIndicies.push_back(i);
			std::vector<int> result = get_sums(numbersToCheck, i + 1, depth - 1, previousIndicies);
			if (result.size() != 0) {
				return result;
			}
			previousIndicies.pop_back();
		}
	}
	return toReturn;
}

int main() {
	std::string filename = "input.txt";
	std::vector<int> numbers = get_numbers_from_file(filename);
	std::vector<int> solution = get_sums(numbers, 0, 3);
	int answer = solution[0];
	for (int i = 1; i < solution.size(); i++) {
		answer *= solution[i];
	}

	std::cout << std::to_string(answer) << std::endl;
	return 0;
}
