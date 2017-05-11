#include <iostream>
#include <thread>

using namespace std;

void thread_call() {
	string input;
	cin >> input;
	cout << input << endl;

	return;
}

static const int NUM_THREADS = 10;

int main() {
	thread multi_thread[NUM_THREADS];

	for(auto & thr : multi_thread) {
		thr = thread(thread_call);
	}

	for(auto & thr : multi_thread) {
		thr.join();
	}

	return 0;
}