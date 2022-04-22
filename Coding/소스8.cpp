#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	string astring = to_string(a);
	string bstring = to_string(b);

	return astring + bstring > bstring + astring;	
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), cmp);

	for (int n : numbers) {
		answer += to_string(n);
	}

	if (answer[0] == '0')
		answer = "0";

	return answer;
}