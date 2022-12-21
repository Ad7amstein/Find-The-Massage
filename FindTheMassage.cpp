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

int main() {
	// Load the dictionary
	LoadDic(DICTIONARY);
}