#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<char> > words;
    vector<char> word;
    int current;
    current = getchar();

    while (current != EOF && current != '\n') {
        if (current != ' ') {
            word.push_back(current);
        } else {
            if (!word.empty())
                words.push_back(word);
            word.clear();
        }
        current = getchar();
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    pair<int, int> *p = new pair<int, int>[words.size()];
    for (int i = 0; i < words.size(); i++) {
        p[i].first = 0;
        p[i].second = i;
        for (int j = 0; j < words[i].size(); j++) {
            p[i].first += (int) (words[i][j]);
        }
    }

    sort(p, p + words.size());

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[p[i].second].size(); j++) {
            cout << words[p[i].second][j];
        }
        cout << " ";
    }

    return 0;
}
