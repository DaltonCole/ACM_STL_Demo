// CORRECT SOLUTION

#include <iostream>
#include <memory>

using namespace std;

struct Point {
	unique_ptr<int> x;
	unique_ptr<int> y;
	unique_ptr<Point> next;

	const Point & operator =(const Point & rhs) {
		cout << "begin" << endl;
		x = unique_ptr<int> (new int(*rhs.x));
		y = unique_ptr<int> (new int(*rhs.x));
		next = unique_ptr<Point> (new Point(*rhs.next));
		cout << "end" << endl;

		return *this;
	}

	Point() {}

	Point(const Point & rhs) {
		x = unique_ptr<int> (new int(*rhs.x));
		y = unique_ptr<int> (new int(*rhs.x));
		cout << "t" << endl;
		if(rhs.next == nullptr) {
			next = nullptr;
		} else {
			next = unique_ptr<Point> (new Point(*rhs.next));
		}
	}
};

int main() {
	Point a;
	a.x = unique_ptr<int> (new int(5));
	a.y = unique_ptr<int> (new int(6));
	a.next = unique_ptr<Point> (new Point);
	a.next -> x = unique_ptr<int> (new int(1));
	a.next -> y = unique_ptr<int> (new int(2));

	Point b;
	b = a;

	cout << *a.x << " " << *a.y << " " << *b.x << " " << *b.y << endl;
	cout << *a.next -> x << " " << *a.next -> y << endl;
	*b.next -> y = 9;
	cout << *b.next -> x << " " << *b.next -> y << endl;

	return 0;
}