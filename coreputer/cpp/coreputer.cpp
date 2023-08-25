#include "coreputer.h"

#include <iostream>
#include <numeric>
#include <set>
using namespace std;

vector<int> cast_vector(set<int>& s) {
	vector<int> ret(s.size());
	int i = 0;
	for(int e : s) {
		ret[i] = e;
		i++;
	}
	return ret;
}

vector<int> malfunctioning_cores(int N) {
	set<int> mcs;
	for(int i = 0; i < N; i++)
		mcs.insert(i);

	/* int check_zero = run_diagnostic(cast_vector(mcs)); */

	/* if(check_zero == 0) */
	/* 	return vector<int>(N, 0); */

	int last_diagnostic = 0;
	for(int i = 0; i < N; i++) {
		mcs.erase(i);
		int rd = run_diagnostic(cast_vector(mcs));

		if(rd == -1)
			mcs.insert(i);

		else
			last_diagnostic = rd;
	}

	// last_diagnostic == 0: even malfunctioning cores
	// last_diagnostic == 1: odd malfunctioning cores

	vector<int> secured(N, 0), ret(N, 0);
	for(int e : mcs)
		secured[e] = ret[e] = 1;

	if(last_diagnostic == 1)
		mcs.erase(mcs.begin());

	for(int i = 0; i < N; i++)
		if(!secured[i]) {
			mcs.insert(i);
			int rd = run_diagnostic(cast_vector(mcs));

			if(rd == 1)
				ret[i] = 1;

			mcs.erase(i);
		}

	return ret;
}
