#include <bits/stdc++.h>
using namespace std;


void printSubseq(string s, int i, string curr) {
    if (i == s.size()) {
        cout << curr << endl;
        return;
    }

    // exclude
    printSubseq(s, i + 1, curr);

    // include
    printSubseq(s, i + 1, curr + s[i]);
}

int main() {
    string s = "abc";
    printSubseq(s, 0, "");


        vector<string> subs = {""};

        for (char c : s) {
            int size = subs.size();
            for (int i = 0; i < size; i++) {
                subs.push_back(subs[i] + c);
            }
        }

        for (auto &x : subs)
            cout << x << endl;

}
