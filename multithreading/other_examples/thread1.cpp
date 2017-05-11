#include <iostream>
#include <pthread.h>
#include <ctime>

using namespace std;

#define NUM_THREADS 10

void *print(void * threadid) {
	auto start_time = clock();
	while(clock() - start_time < 1000){}

	long tid = (long)threadid;
	cout << "Thread ID: " << tid << endl;
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int rc;

	for(int i = 0; i < NUM_THREADS; i++) {
		cout << "Creating thread: " << i << endl;
		rc = pthread_create(&threads[i], NULL, print, (void *)i);

		if(rc) {
			cout << "Error: unable to create thread: " << rc << endl;
			exit(-1);
		}
	}

	pthread_exit(NULL);
}