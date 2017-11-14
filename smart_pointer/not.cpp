#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point* next;
};

int main() {
	Point a;
	a.x = 1;
	a.y = 5;
	Point b;
	b.x = 12;
	b.y = 6;
	a.next = &b;
	Point c;
	c.x = 4;
	c.y = 2;
	b.next = &c;
	c.next = &a;

	Point d = *a.next;
	for(int i = 0; i < 10; i++) {
		cout << d.x << endl;
		d = *d.next;
	}

	return 0;
	cout << a.next << endl;
	cout << b.next << endl;
	cout << c.next << endl << endl;

	a = *a.next;
	cout << a.next << endl;
	cout << b.next << endl;
	cout << c.next << endl << endl; 

	cout << a.x << endl;
	


	return 0;
}