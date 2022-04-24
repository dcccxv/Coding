#include <bits/stdc++.h>

using namespace std;
int answer = 50;

void dfs(string begin, string target, vector<string>& words, int count, vector<bool>& visit) {
	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < words[i].length(); j++)
			if (!visit[i] && begin[j] != words[i][j])
				cnt++;
		if (cnt == 1) {
			if (words[i] == target && answer > count + 1) {
				answer = count + 1;
				return;
			}
			visit[i] = true;
			dfs(words[i], target, words, count + 1, visit);
			visit[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	vector<bool> visit(words.size(), false);

	dfs(begin, target, words, 0, visit);

	if (answer == 50)
		return 0;

	return answer;
}
