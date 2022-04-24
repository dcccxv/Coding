#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> sortScovile(scoville.begin(),scoville.end());

	while (sortScovile.size() > 1 && sortScovile.top() < K) {
		int temp = sortScovile.top();
		sortScovile.pop();
		temp += sortScovile.top() * 2;
		sortScovile.pop();
		sortScovile.push(temp);
		answer++;
	}

	if (sortScovile.top() < K) return -1;

	return answer;
}