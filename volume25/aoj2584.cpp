#include <bits/stdc++.h>
using namespace std;

char calc (string s) {
    char c = s[s.size()-1];
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        sum += s[i] == '-' ? -1 : 1;
    }

    if (c == '?') {
        c = 'A';
    } else {
        c = 'A' + (((c - 'A') + 26 + (sum % 26)) % 26);
    }

    return c;
}

string dfs (string str) {
    int i = 0;
    string res = "";

    string tmp = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            tmp += str[i];
        } else if ('A' <= str[i] && str[i] <= 'Z' || str[i] == '?') {
            tmp += str[i];
            res += calc(tmp);
            tmp = "";
        } else if (str[i] == '[') {
            int count = 1;
            i++;
            string str_ = "";
            while (count) {
                if (str[i] == '[') count++;
                if (str[i] == ']') count--;
                if (count) {
                    str_ += str[i];
                }
                i++;
            }
             i--;
            str_ = dfs (str_);
            for (int j = str_.size()-1; j >= 0; j--) {
                res += str_[j];
            }
        }
    }

    return res;
}

int main () {
    string str;
    while (cin >> str, str != ".") {
        cout << dfs(str) << endl;
    }

    return 0;
}
