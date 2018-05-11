#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;

struct Point {
	int x;
	int y;

	bool operator ==(const Point& other) const {
		if(x == other.x && y == other.y) {
			return true;
		} else {
			return false;
		}
	}
};

namespace std {
	template<>
	struct hash<Point> {
		size_t operator()(const Point& obj) const {
			return hash<int>()(obj.x);
		}
	};
}


int main() {
	unordered_set<Point> a;

	Point p;
	for(int i = 0; i < 10; i++) {
		p.x = i;
		p.y = i * 3;
		a.insert(p);
	}

	for(auto q : a) {
		cout << q.x << " " << q.y << endl;
	}

	return 0;
}