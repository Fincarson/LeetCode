class Solution {
public:
    map<string, vector<string>> allComboDict;
    int L = 0;
    int visitWordNode(queue<pair<string, int>>& Q, map<string, int>& Visited,
                      map<string, int>& othersVisited) {
        for (size_t j = Q.size(); j > 0; j--) {
            pair<string, int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < this->L; i++) {
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                for (string adjacentWord : this->allComboDict[newWord]) {
                    if (othersVisited.find(adjacentWord) !=
                        othersVisited.end()) {
                        return level + othersVisited[adjacentWord];
                    }
                    if (Visited.find(adjacentWord) == Visited.end()) {
                        Visited[adjacentWord] = level + 1;
                        Q.push(make_pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        L = beginWord.size();
        for (string& word : wordList) {
            for (int i = 0; i < L; i++) {
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                vector<string>& transformations = this->allComboDict[newWord];
                transformations.push_back(word);
            }
        }
        queue<pair<string, int>> q_beg;
        q_beg.push(make_pair(beginWord, 1));
        queue<pair<string, int>> q_end;
        q_end.push(make_pair(endWord, 1));
        map<string, int> visited_beg;
        visited_beg[beginWord] = 1;
        map<string, int> visited_end;
        visited_end[endWord] = 1;
        int ans = -1;
        while (!q_beg.empty() && !q_end.empty()) {
            if (q_beg.size() <= q_end.size()) {
                ans = visitWordNode(q_beg, visited_beg, visited_end);
            } else {
                ans = visitWordNode(q_end, visited_end, visited_beg);
            }
            if (ans > -1) {
                return ans;
            }
        }
        return 0;
    }
};
