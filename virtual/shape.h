#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class shape {
	public:
		virtual void print() = 0;
		virtual void s() {cout << "a" << endl;}
		virtual void t() {cout << "b" << endl;}
		virtual int get_corners() const {return this -> corners;}

	protected:
		shape(int n): corners(n) {}
		shape(const shape* a): shape(a -> corners) {}
		int corners;
};

class square: virtual public shape {
	public:
		square(): shape(4) {}

		virtual void print() {
			cout << this -> corners << endl;
		}

		virtual void s() {
			cout << "s" << endl;
		}
};

class triangle: virtual public shape {
	public:
		triangle(): shape(3) {};
		triangle(const shape* t): shape(t -> get_corners()) {}

		virtual void print() {
			cout << this -> corners << endl;
		}

		virtual void t() {
			cout << "t" << endl;
		}
};

class pyramid: public square, public triangle {
	public:
		pyramid(): shape(5) {};

		virtual void print() {
			cout << this -> corners << endl;
		}
};

#endif