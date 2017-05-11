#include <iostream>
#include <thread>
#include <mutex>   

using namespace std;

mutex mtx;

void thread_call(int i);
void mutex_try_lock();


static const int NUM_THREADS = 10;
static const int NUM_THREADS2 = 1000;
static const int FOR_LOOP = 1000;


volatile int counter(0);

int main() {
	// Initialize thread
	thread multi_thread[NUM_THREADS];

	for(int i = 0; i < NUM_THREADS; i++) {
		// Spin up threads
		multi_thread[i] = thread(thread_call, i);
	}

	// Wait for threads to finish
	for(auto & wait : multi_thread) {
		wait.join();
	}


	// ----- try_lock ----- //
	// Initialize thread
	thread multi_thread2[NUM_THREADS2];

	for(auto & thr : multi_thread2) {
		thr = thread(mutex_try_lock);
	}


	// Wait for threads to finish
	for(auto & wait : multi_thread2) {
		wait.join();
	}

	cout << "Counter: " << counter << " out of " << NUM_THREADS2 * FOR_LOOP << endl;

	return 0;
}

void thread_call(int i) {
	mtx.lock();
	cout << "Hello, I am thread number: " << i << endl;
	mtx.unlock();

	return;
}

void mutex_try_lock() {

	for(int i = 0; i < FOR_LOOP; i++) {
		if(mtx.try_lock()) {
			counter++;
			mtx.unlock();
		}
	}

	return;
}
