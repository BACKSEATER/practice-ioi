#include "aplusb.h"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;

std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {
	minheap <pair<int, pair<int, int>>> pq;
	for(int i = 0; i < N; i++)
		pq.push({A[i] + B[0], {i, 0}});

	vector<int> ret;
	for(int i = 0; i < N; i++) {
		auto [x, is] = pq.top(); pq.pop();

		ret.push_back(x);
		if(is.second < N - 1)
			pq.push({A[is.first] + B[is.second + 1], {is.first, is.second + 1}});
	}

	return ret;
}
