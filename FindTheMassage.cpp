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

void FindTheMassage(string s, vector<string>& ans, int i, string w) {
	if (isWord(w) && i >= s.length()) {
		//cout << "DONE!\n";
		ans.push_back(w);
		for (string i : ans) cout << i << " ";
		cout << endl;
	}
	if (!isWord(w) && i < s.length()) {
		//cout << "NOT WORD YET: " << w << endl;
		FindTheMassage(s, ans, i + 1, w + s[i]);
	}
	else if (!isWord(w) && i >= s.length()) {
		//out << "Cant't be Word: " << w << endl;
		if (ans.empty()) return;
		i -= w.length();
		w = ans.back();
		ans.pop_back();
		FindTheMassage(s, ans, i + 1, w + s[i]);
	}
	else if (isWord(w) && i < s.length()) {
		//cout << "YES word: " << w << endl;
		ans.push_back(w);
		w = "";
		FindTheMassage(s, ans, i, w);
	}
}

int main() {
	// Load the dictionary
	LoadDic(DICTIONARY);
	// Prompt the user for the massage
	string originalMassage;
	cin >> originalMassage;
	// Turn the massage to the lower case
	for (int i = 0; i < originalMassage.length(); ++i) {
		originalMassage[i] = tolower(originalMassage[i]);
	}
	// Find understandable massage
	vector<string>modifiedMassage;
	FindTheMassage(originalMassage, modifiedMassage, 0, "");
}