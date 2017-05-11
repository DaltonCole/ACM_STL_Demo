#include <iostream>
#include <thread>
#include <future>
#include <ctime>
#include <chrono>         // std::chrono::seconds

using namespace std;

void thread_call(int i) {
	cout << "Hello, I am thread number: " << i << endl;

	return;
}

void detached_thread(int n) {
	this_thread::sleep_for (chrono::seconds(n));
	cout << "I'm a detached thread that has been paused for " << n << " seconds!" << endl;
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

	// ----- Detach ----- //
	// Detach a thread from this function
	// Makes it so it cannot be rejoined
	// We cannot block the detached thread

	// Why would we set it to a variable if we cannot join it anymore?
	thread(detached_thread, 1).detach();

	// Got to give the above thread time to finish before returning
	this_thread::sleep_for (chrono::seconds(2));	// main is just anohter thread

	// ----- get_id ----- //

	thread get_id_thread = thread(thread_call, 11);
	cout << "get_id_thread's id: " << get_id_thread.get_id() << endl;
	get_id_thread.join();

	// ----- joinable ----- //

	thread joinable_thread = thread(thread_call, 12);

	this_thread::sleep_for (chrono::seconds(1));

	cout << "joinable_thread is joinable: " << joinable_thread.joinable() << endl;
	cout << "get_id_thread   is joinable: " << get_id_thread.joinable() << endl;
	joinable_thread.join();

	

	return 0;
}