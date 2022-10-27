// problem statement 
// find the kth smallest element in an unsorted array 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 4;

	set<int> s(arr, arr + N);

	// s.begin() returns a pointer to first
	// element in the set
	set<int>::iterator itr = s.begin();

	advance(itr, K - 1); // itr points to kth element in set

	cout << *itr << "\n";

	return 0;
}
