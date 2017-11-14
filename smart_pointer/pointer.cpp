#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	shared_ptr<Point> next;
};

int main() {
	Point a;
	a.x = 1;
	a.y = 5;
	Point b;
	b.x = 12;
	b.y = 6;
	a.next = make_shared<Point>(b);
	Point c;
	c.x = 4;
	c.y = 2;
	b.next = make_shared<Point>(c);
	c.next = make_shared<Point>(a);

	cout << a.next.use_count() << endl;
	Point d = a;
	cout << d.next.use_count() << endl << endl;
	for(int i = 0; i < 10; i++) {
		cout << d.x << endl;
		d = *d.next;
	}
	return 0;

	/*
	Point a;
	a.x = 1;
	a.y = 5;
	Point b;
	b.x = 12;
	b.y = 6;
	a.next = make_shared<Point>(b);
	Point c;
	c.x = 4;
	c.y = 2;
	b.next = make_shared<Point>(c);


	cout << a.next.use_count() << endl;
	cout << b.next.use_count() << endl;
	c.next = b.next;
	cout << c.next.use_count() << endl << endl;

	cout << a.next << endl;
	cout << b.next << endl;
	cout << c.next << endl << endl;

	//a = *a.next;
	cout << a.next << endl;
	cout << b.next << endl;
	cout << c.next << endl << endl;
	

	cout << b.next.use_count() << endl;

	Point d = *b.next;
	cout << d.next << endl;

	return 0;
	*/
}