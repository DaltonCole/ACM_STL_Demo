#include <iostream>
#include <vector>
#include <algorithm>	// Sort, for_each
#include <ctime>
#include <random>

using namespace std;

int main() {
	vector<int> temp(10,0);
	vector<vector<int> > random_vector(10, temp);

	srand(time(NULL));

	for(auto & i : random_vector) {
		for(auto & j : i) {
			j = rand() % 10;
		}
	}

	for(auto i : random_vector) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<vector<int> > second_random_vector = random_vector;
	vector<vector<int> > third_random_vector = random_vector;
	vector<vector<int> > fourth_random_vector = random_vector;


	auto s_time = clock();

	// From begining to end
	// Sort each vector using a lambda
	for_each(random_vector.begin(), random_vector.end(), [] (vector<int> & val) { sort(val.begin(), val.end()); } );

	cout << "for_each: \t" << (clock() - s_time) << endl;

	s_time = clock();

	// Clasical way
	for(int i = 0; i < second_random_vector.size(); i++) {
		sort(second_random_vector[i].begin(), second_random_vector[i].end());
	}

	cout << "for: \t \t" << (clock() - s_time) << endl;

	s_time = clock();

	// range_based_for_loop way
	for(auto & it : third_random_vector) {
		sort(it.begin(), it.end());
	}

	cout << "range_for: \t" << (clock() - s_time) << endl;


	s_time = clock();
	// From begining to end
	// Sort each vector using a lambda
	for_each(fourth_random_vector.begin(), fourth_random_vector.end(), [] (vector<int> & val) { sort(val.begin(), val.end()); } );

	cout << "for_each: \t" << (clock() - s_time) << endl << endl;;


	for(auto i : random_vector) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}