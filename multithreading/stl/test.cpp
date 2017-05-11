#include <iostream>
#include <thread>

using namespace std;


int main() {
	// Initialize thread
	thread multi_thread;

	multi_thread = thread(main);

	cout << multi_thread.get_id() << endl;

	multi_thread.join();

	return 0;
}