#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    int index = 0;
    queue<int> bridge;
    
    while (1) {
        if (index == truck_weights.size()) {  //마지막 트럭일 때
            answer += bridge_length;  //마지막 트럭이 지나는 시간 추가
            break;
        }

        answer++;

        
        if (bridge.size() == bridge_length) { //차가 다리를 다 건넜을 경우
            bridge_weight -= bridge.front();  //무게에서 제외
            bridge.pop();
        }

        if (bridge_weight + truck_weights[index] <= weight) { // 다음차 진입 가능하면
            bridge_weight += truck_weights[index];
            bridge.push(truck_weights[index]);
            index++;
        }
        else {// 다음차 진입 불가능
            bridge.push(0);
        }
    }

    return answer;
}