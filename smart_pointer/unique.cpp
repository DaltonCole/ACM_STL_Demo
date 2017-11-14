#include <memory>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	unique_ptr<Point> next;

	~Point() {
		cout << "Deleting" << endl;
		next.reset();
	}
};

int main() {
	Point a;

	vector<Point> l;

	a.x = 1;
	a.y = 4;

	l.push_back(a);

	for(int i = 1; i < 10; i++) {
		a.x++;
		a.y++;
		l.push_back(a);
		l[i-1].next = *l[i];
	}

	return 0;
}