#include <bits/stdc++.h>
using namespace std;
#define ANS 12

int expr(string& s, int& i);    //'+','-'を読む
int term(string& s, int& i);    //'*','/'を読む
int factor(string& s, int& i);  //()を読む
int number(string& s, int& i);  //数を読む

int main() {
    string s;
    cin >> s;
    int i = 0;
    if(expr(s, i) == ANS)
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
}

int expr(string& s, int& i) {  //'+','-'を読む
    int val = term(s, i);
    while(s[i] == '+' || s[i] == '-') {
        char op = s[i];
        i++;
        int val2 = term(s, i);
        if(op == '+') val += val2;
        if(op == '-') val -= val2;
    }
    return val;
}

int term(string& s, int& i) {  //'*','/'を読む
    int val = factor(s, i);
    while(s[i] == '*' || s[i] == '/') {
        char op = s[i];
        i++;
        int val2 = factor(s, i);
        if(op == '*') val *= val2;
        if(op == '/') val /= val2;
    }
    return val;
}

int factor(string& s, int& i) {  //()を読む
    if(isdigit(s[i])) return number(s, i);

    //ここで構文が正しければ s[i] == '('となる
    i++;  //'('を読み飛ばす
    int ret = expr(s, i);
    i++;  //')'を読み飛ば
    return ret;
}

int number(string& s, int& i) {  //数を読む
    int n = s[i++] - '0';
    while(isdigit(s[i])) n = n * 10 + s[i++] - '0';
    return n;
}