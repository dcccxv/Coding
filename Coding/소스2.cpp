#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

	map<string, int> music; //�帣�� ���Ƚ�� ����
	map<string, map<int, int>> musiclist; //���Ƚ���� �ּ� ����

	for (int i = 0; i < genres.size(); i++) {
		music[genres[i]] += plays[i]; 
		musiclist[ genres[i] ] [i] = plays[i]; 
	}

	while (music.size() > 0) {
		string hightGenre;
		int max = 0;
		for (auto n : music) { // ���� ���� �帣 ã��
			if (max < n.second) {
				max = n.second;
				hightGenre = n.first;
			}
		}

		for (int i = 0; i < 2; i++) {
			int val = 0, ind = -1;
			for (auto ml : musiclist[hightGenre]) { //���� ������ ã��
				if (val < ml.second) {
					val = ml.second;
					ind = ml.first;
				}
			}
			if (ind == -1)    break;// �뷡 2�� �̸� Ż��
			answer.push_back(ind);
			musiclist[hightGenre].erase(ind);
		}
		music.erase(hightGenre);
	}



    return answer;
}