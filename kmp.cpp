#include <bits/stdc++.h>

using namespace std;

vector<int> hihi;

vector<int> compute_lps_array(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            j++;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmp_search(const string& pattern, const string& text) {
    int m = pattern.size();
    int n = text.size();

    vector<int> lps = compute_lps_array(pattern);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout<< i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text,pattern;
    cin>>pattern>>text;
    kmp_search(pattern, text);
    return 0;
}
