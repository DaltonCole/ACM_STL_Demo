#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void zzz(int i) {
	this_thread::sleep_for(chrono::milliseconds(564));
	cout << i << " is done sleeping!" << endl;
}

int main() {
	vector<thread> threads;

	for(int i = 0; i < 10; i++) {
		threads.push_back(thread(zzz, i));
	}

	for(auto& t : threads) {
		t.join();
	}

	cout << "DONE!" << endl;

	return 0;
}