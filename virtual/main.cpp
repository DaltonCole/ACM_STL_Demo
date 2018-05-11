#include "shape.h"

int main() {
	shape* a = new pyramid;

	a -> print();

	a -> t();

	a -> s();

	//delete a;

	pyramid p;
	p.print();
	p.t();
	p.s();

	shape* b = new square;
	b -> s();
	b -> t();

	shape* c = new triangle(b);
	c -> print();
	//delete c;
	//delete b;

	return 0;
}