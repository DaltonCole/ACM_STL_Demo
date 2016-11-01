// More info: http://www.cplusplus.com/reference/stack/stack/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> s;

	// Put A-J on the stack
	for(int i = 0; i < 10; i++) {
		s.push(i+65);
	}

	// Size
	cout << "Size: " << s.size() << endl;

	// Swap
	stack<char> p;
	s.swap(p);

	cout << "Printing p: " << endl;
	while(!p.empty()) {
		cout << p.top() << endl;
		p.pop();
	}
}

