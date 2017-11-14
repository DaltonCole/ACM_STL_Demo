#include <iostream>
#include <memory>

using namespace std;

struct Point {
	int x;
	int y;
	unique_ptr<Point> next;

	Point() {
		x = 0;
		y = 0;
	}

	Point(const Point & rhs) {
		x = rhs.x;
		y = rhs.y;
		//next(new Point(*rhs.next));
		//next(rhs.next);
		//next = unique_ptr<Point> (new Point);
		//next = rhs.next;
		unique_ptr<Point> temp (new Point);

		while(rhs.next != nullptr) {
			temp
		}
	}

	/*
	Point& operator =(Point & rhs) {
		rhs.x = x;
		rhs.y = y;
		rhs.next = next;

		return *this;
	}
	*/

};

int main() {
	Point a;
	a.x = 1;
	a.y = 2;
	a.next = unique_ptr<Point> (new Point);
	a.next -> x = 3;
	a.next -> y = 4;

	//Point b = a;
	Point b(a);

	cout << a.x << " " << a.y << " " << a.next -> x << " " << a.next -> y << " " << endl;
}

/*
class A
{
   std::unique_ptr< int > up_;

public:
   A( int i ) : up_( new int( i ) ) {}
   A( const A& a ) : up_( new int( *a.up_ ) ) {}
};

int main()
{
   A a( 42 );
   A b = a;
}
*/