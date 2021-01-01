#include <iostream> 
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T>& array) {
	for (T ele : array) {
		cout << ele << " ";
	}
	cout << endl;
}
