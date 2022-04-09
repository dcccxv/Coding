#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> countq;

	for (int i = 0; i < progresses.size(); i++) {
		int temp = 0;
		
		temp = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0) temp++;

		countq.push(temp);
	}

	while (!countq.empty()) {
		int front = countq.front();
		int count = 0;

		while ((!countq.empty()) && (countq.front() <= front)) {
			countq.pop();
			count++;
		}
		answer.push_back(count);
	}

	return answer;
}
