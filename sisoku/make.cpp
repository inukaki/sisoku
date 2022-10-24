#include <bits/stdc++.h>
using namespace std;
#define NUM 4
#define CARD_MIN 1
#define CARD_MAX 13
#define ANS_MIN 10
#define ANS_MAX 20

int main() {
    srand(time(NULL));
    int num[NUM];
    double ans = 0;
    int ope;
    for(int i = 0; i < NUM; i++) {
        num[i] = rand() % (CARD_MAX - CARD_MIN + 1) + 1;
    }
    do {
        ans = num[0];
        for(int i = 1; i < NUM; i++) {
            ope = rand() % 4;
            if(ope == 0) ans += num[i];
            if(ope == 1) ans -= num[i];
            if(ope == 2) ans *= num[i];
            if(ope == 3) ans /= num[i];
        }
    } while(ans - (int)ans > 0 || ANS_MAX < ans || ans < ANS_MIN);
    sort(num, num + NUM);
    for(int i = 0; i < NUM; i++) {
        cout << num[i] << " ";
    }
    cout << endl
         << ans << endl;
}
