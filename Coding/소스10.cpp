#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    int student1[5] = { 1,2,3,4,5 };
    int student2[8] = { 2,1,2,3,2,4,2,5 };
    int student3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int result[3] = { 0,0,0 };
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == student1[i % 5]) 
            result[0]++;
        if (answers[i] == student2[i % 8]) 
            result[1]++;
        if (answers[i] == student3[i % 10]) 
            result[2]++;
    }

    int max = *max_element(result, result + 3);

    for (int i = 0; i < 3; i++) {
        if (result[i] == max) answer.push_back(i + 1);
    }

    return answer;
}