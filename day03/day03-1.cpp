#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> get_map(std::string path) {
	std::vector<std::string> map;
	std::ifstream filestream(path);
	std::string currentLine;
	while (std::getline(filestream, currentLine)) {
		map.push_back(currentLine);
	}
	return map;
}

int count_trees(std::vector<std::string> map) {
	int x = 3, trees = 0;
	for (int i = 1; i < map.size(); i++) {
		if (map[i][x] == '#') {
			trees++;
		}
		x = (x + 3) % 31;
	}
	return trees;
}

int main() {
	std::vector<std::string> map = get_map("input.txt");
	int trees = count_trees(map);
	std::cout << std::to_string(trees) << std::endl;
	return 0;
}