#include <iostream>
#include <map>
using namespace std;

// Function pointer
bool fncomp (int lhs, int rhs) {return lhs>rhs;}

// Function class
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main() {
	map<int, char> m;

	// Insert
	for(int i = 0; i < 10; i++) {
		m.insert(pair<int,char>(i, i+65));
	}

	for(auto & i : m) {
		cout << i.first << "->" << i.second << "\t"; // More info on pair: http://www.cplusplus.com/reference/utility/pair/
	}
	cout << endl;

	// Count - All keys are unique, so will return a max of 1
	cout << "Count for 5: \t" << m.count(5) << endl;
	cout << "Count for a: \t" << m.count('a') << endl;

	// Emplace
	m.emplace(12,'C');

	cout << "Emplace: \t";
	for(auto & i : m) {
		cout << i.first << "->" << i.second << "\t";
	}
	cout << endl;

	// []
	cout << "m[2]: \t \t" << m[2] << endl;

	// size
	cout << "Size: \t \t" << m.size() << endl;

	// erase
	m.erase(3);
	auto it = m.find(8);
	m.erase(it);
	cout << "Erase: \t \t";
	for(auto & i : m) {
		cout << i.first << "->" << i.second << "\t";
	}
	cout << endl;

	// Created using the classcomp function as the comparison
	map<int, char, classcomp> classCompare;

	// Created using the function pointer as the comparison
	bool(*fn_pt)(int, int) = fncomp;
	map<int, char, bool(*)(int, int)> funcCompare(fn_pt);

	// Clear
	m.clear();

	cout << "m.size(): \t" << m.size() << endl;

	// Insert into funcCompare
	for(int i = 0; i < 10; i++) {
		funcCompare.insert(pair<int,char>(i, i+65));
	}

	// Print funcCompare
	cout << "funcCompare: \t";
	for(auto & i : funcCompare) {
		cout << i.first << "->" << i.second << "\t";
	}
	cout << endl;

	return 0;
}