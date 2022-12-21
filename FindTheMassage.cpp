// Headers
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <string>
using namespace std;
// To store the dictionary in
set<string>DICTIONARY;

// Load the dictionary
void LoadDic(set<string>& dic) {
	// open the dictionary
	ifstream file;
	file.open("dictionary.txt", ios::in);
	// Load word by word
	string w;
	while (getline(file, w)) {
		dic.insert(w);
	}
	// Close the dictionary
	file.close();
}

// Check if the word in the dictionary or not
bool isWord(string w) {
	// finding position of w
	auto pos = DICTIONARY.find(w);
	// return true if it is present in set
	if (pos != DICTIONARY.end())
		return true;
	return false;
}

int main() {
	// Load the dictionary
	LoadDic(DICTIONARY);
}