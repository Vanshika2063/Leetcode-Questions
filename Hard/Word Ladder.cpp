//Word Ladder

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        
        q.push({beginWord, 1});
        vis.insert(beginWord);
        while(!q.empty()){
            string w = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(w == endWord) return lvl;
            for(int i = 0; i < w.size(); i++){
                string temp = w;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(st.find(temp) != st.end() && vis.find(temp) == vis.end()){
                        q.push({temp, lvl+1});
                        vis.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};