#include <iostream>
#include <functional>
#include <unordered_set>
#include <string>

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

	friend std::string to_string(const Point& p) {
		return std::to_string(p.x) + " " + std::to_string(p.y);
	}


};

namespace std {
	template<>
	struct hash<Point> {
		size_t operator()(const Point& obj) const {
			return hash<string>()(to_string(obj));
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