#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zero = 0;
    int correct = 0;

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    for (int n : lottos) {
        if (n == 0) zero++;
        else break;
    }

    int j = 0;
    for (int i = zero; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                correct++;
                win_nums.erase(win_nums.begin() + j);
            }
        }

    }

    if (correct + zero <= 1)
        answer.push_back(6);
    else
        answer.push_back(7 - correct - zero);

    if (correct <= 1)
        answer.push_back(6);
    else
        answer.push_back(7 - correct);

    return answer;
}