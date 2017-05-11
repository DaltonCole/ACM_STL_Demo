#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

void thread_call(int i) {
	cout << "Hello, I am thread number: " << i << endl;

	return;
}

static const int NUM_THREADS = 10;

int main() {
	// Initialize thread
	thread multi_thread[NUM_THREADS];

	// Initialize clock to delay thread execution
	auto start_time = clock();

	for(int i = 0; i < NUM_THREADS; i++) {
		// Spin up threads
		multi_thread[i] = thread(thread_call, i);

		// Wait to spin up another one
		while(clock() - start_time < 1000*(i+1)) {}
	}

	// Wait for threads to finish
	for(int i = 0; i < NUM_THREADS; i++) {
		multi_thread[i].join();
	}

	return 0;
}