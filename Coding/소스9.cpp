#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());

	int answer = citations.size();
	for (int i = 0; i < citations.size(); i++) {
		if (i > citations[i]) {
			answer = i;
			break;
		}
	}
	return answer;
}