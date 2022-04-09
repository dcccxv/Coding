#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer=0;
	queue<pair<int, int>> pri;
	priority_queue<int> sorted;

	for (int i = 0; i < priorities.size(); i++) {
		pri.push(make_pair(priorities[i], i));
		sorted.push(priorities[i]);
	}

	while (!pri.empty()) {
		if (pri.front().first == sorted.top()) {
			sorted.pop();
			answer++;

			if (pri.front().second == location)
				break;
		}
		else {
			pri.push(pri.front());
		}
		pri.pop();
	}
	return answer;
}