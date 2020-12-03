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

int count_trees(std::vector<std::string> map, int dx, int dy) {
	int x = dx, y = dy, trees = 0, width = map[0].size();
	for (int i = y; i < map.size(); i += dy) {
		if (map[i][x] == '#') {
			trees++;
		}
		x = (x + dx) % width;
	}
	return trees;
}

int main() {
	std::vector<std::string> map = get_map("input.txt");
	std::vector<std::vector<int>> slopes { {1,1}, {3,1}, {5,1}, {7,1}, {1,2} };


	long int treeProduct = count_trees(map, slopes[0][0], slopes[0][1]);
	for (int i = 1; i < slopes.size(); i++) {
		treeProduct *= count_trees(map, slopes[i][0], slopes[i][1]);
	}

	std::cout << std::to_string(treeProduct) << std::endl;
	return 0;
}