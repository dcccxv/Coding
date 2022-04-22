#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	for (int i = 3;; i++) {
		if ((brown + yellow) % i == 0) {
			int width = (brown + yellow) / i;
			if ((i - 2) * (width - 2) == yellow) {
				return vector<int> {width, i};
			}
		}
	}

	return answer;
}