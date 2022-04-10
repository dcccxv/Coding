#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    int index = 0;
    queue<int> bridge;
    
    while (1) {
        if (index == truck_weights.size()) {  //������ Ʈ���� ��
            answer += bridge_length;  //������ Ʈ���� ������ �ð� �߰�
            break;
        }

        answer++;

        
        if (bridge.size() == bridge_length) { //���� �ٸ��� �� �ǳ��� ���
            bridge_weight -= bridge.front();  //���Կ��� ����
            bridge.pop();
        }

        if (bridge_weight + truck_weights[index] <= weight) { // ������ ���� �����ϸ�
            bridge_weight += truck_weights[index];
            bridge.push(truck_weights[index]);
            index++;
        }
        else {// ������ ���� �Ұ���
            bridge.push(0);
        }
    }

    return answer;
}