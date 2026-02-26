#include <iostream>
#include <vector>
using namespace std;

vector<int> nextArr(const string &t) {
    if (t.size() == 1) {
        return vector<int>{-1};
    }
    vector<int> next(t.size());
    next[0] = -1;
    next[1] = 0;
    int i = 2, jump = 0;
    while (i < t.size()) {
        if (t[i - 1] == t[jump]) {
            next[i++] = ++jump;
        } else if (jump > 0) {
            jump = next[jump];
        } else {
            next[i++] = 0;
        }
    }
    return next;
}
vector<int> kmp(string s, string t) {
    int i = 0, j = 0;
    vector<int> next = nextArr(t);
    vector<int> indexs;
    while (i < s.size()) {
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j];
            } else {
                i++;
            }
        }
        if (j == t.size()) {
            indexs.push_back(i - j);
            j = 0;
        } else {
            return indexs;
        }
    }
    return indexs;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "ababaaababaa";
    vector<int> next = nextArr(s);
    for (int i = 0; i < next.size(); i++) {
        cout << next[i] << " ";
    }
    return 0;
}