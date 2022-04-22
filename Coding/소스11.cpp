#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return false;
    }

    return true; 
}

int solution(string numbers) {
    int answer = 0;
    vector<char> papers;
    vector<int> numbersInt;

    for (char n : numbers) {
        papers.push_back(n);
    }

    sort(papers.begin(), papers.end());

    do {
        string temp = "";
        for (int n : papers) {
            temp.push_back(n);
            numbersInt.push_back(stoi(temp));
        }
    } while (next_permutation(papers.begin(), papers.end()));

    sort(numbersInt.begin(), numbersInt.end());
    numbersInt.erase(unique(numbersInt.begin(), numbersInt.end()), numbersInt.end());

    for (int n : numbersInt) {
        if (isPrime(n))
            answer++;
    }

    return answer;
}