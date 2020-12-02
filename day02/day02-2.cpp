#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Password
{
	std::vector<int> positions;
	std::string character;
	std::string password;
};

std::vector<Password> get_passwords(std::string path) {
	std::vector<Password> passwordDatabase;
	std::ifstream filestream(path);
	std::string currentLine;
	int posOfDash;
	int posOfSpace;
	int posOfColon;
	while (std::getline(filestream, currentLine)) {
		Password newPassword;
		posOfDash = currentLine.find("-");
		posOfSpace = currentLine.find(" ");
		posOfColon = currentLine.find(":");
		newPassword.positions.push_back(std::stoi(currentLine.substr(0, posOfDash)));
		newPassword.positions.push_back(std::stoi(currentLine.substr(posOfDash + 1, posOfSpace - (posOfDash + 1))));
		newPassword.character = currentLine.substr(posOfColon - 1, 1);
		newPassword.password = currentLine.substr(posOfColon + 2, currentLine.size() - (posOfColon + 2));
		passwordDatabase.push_back(newPassword);
	}
	return passwordDatabase;
}

int is_valid(Password toCheck) {
	char character = toCheck.character.c_str()[0];
	bool valid = false;
	for (int i = 0; i < toCheck.positions.size(); i++) {
		if (toCheck.password[toCheck.positions[i] - 1] == character) {
			valid = !valid;
		}
	}
	return (int)valid;
}

int main() {
	std::vector<Password> database = get_passwords("input.txt");
	int correctTotal = 0;
	for (int i = 0; i < database.size(); i++) {
		correctTotal += is_valid(database[i]);
	}
	std::cout << std::to_string(correctTotal) << std::endl;
	return 0;
}