#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void DFS(vector<int>& numbers, int target, int sum, int i) {
    if (i == numbers.size()) {
        if (sum == target) answer++;
    }
    else {
        DFS(numbers, target, sum + numbers[i], i + 1);
        DFS(numbers, target, sum - numbers[i], i + 1);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    return answer;
}