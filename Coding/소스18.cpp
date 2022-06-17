#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> id_idx_map;
    map<string, set<string>> report_map;

    for (auto i = 0; i < id_list.size(); ++i) {
        id_idx_map[id_list[i]] = i;
    }

    for (auto x : report) {
        stringstream ss(x);
        string from, to;
        ss >> from >> to;

        report_map[to].insert(from);
    }

    for (auto iter : report_map) {
        if (iter.second.size() >= k) {
            for (auto in_iter : iter.second) {
                answer[id_idx_map[in_iter]]++;//
            }
        }
    }

    return answer;
}