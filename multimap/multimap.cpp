#include <iostream>
#include <map>
using namespace std;

int main() {
	multimap<int, char> mm; 

	for(int i = 0; i < 10; i++) {
		mm.insert(pair<int, char>(i, i+65));
		mm.insert(pair<int, char>(i/2, i+65));
	}

	for(auto & it : mm) {
		cout << it.first << "->" << it.second << "\t";
	}
	cout << endl;

	return 0;
}