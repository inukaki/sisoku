#include <bits/stdc++.h>
using namespace std;
#define ANS 19

int main() {
    int num[] = {
        6,6,7,12};
    int NUM = sizeof(num) / sizeof(num[0]);
    sort(num, num + NUM);
    queue<pair<double, int>> sum;

    do {
        sum.push(make_pair(num[0], 0));
        while(!sum.empty()) {
            pair<double, int> sum_receive;
            sum_receive = make_pair(sum.front().first, sum.front().second);
            sum.pop();
            if(sum_receive.second == NUM && sum_receive.first == ANS) {
                for(int i = 0; i < NUM; i++) cout << num[i] << " ";
                cout << endl
                     << "can" << endl;
                return 0;
            }
            if(sum_receive.second < NUM) {
                sum.push(make_pair(sum_receive.first + num[sum_receive.second + 1], sum_receive.second + 1));
                sum.push(make_pair(sum_receive.first - num[sum_receive.second + 1], sum_receive.second + 1));
                sum.push(make_pair(sum_receive.first * num[sum_receive.second + 1], sum_receive.second + 1));
                sum.push(make_pair(num[sum_receive.second + 1] / sum_receive.first, sum_receive.second + 1));
                if(num[sum_receive.second + 1] != 0) sum.push(make_pair(sum_receive.first / num[sum_receive.second + 1], sum_receive.second + 1));
            }
        }
    } while(next_permutation(num, num + NUM));
    cout << "cannot" << endl;
}