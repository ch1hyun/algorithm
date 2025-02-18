class Solution {
public:
    map<string, int> mapper;
    map<int, string> revMapper;
    int mapperIdx = 0;
    vector<vector<int>> edges;
    vector<set<int>> prev;
    vector<int> dist;
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        edges.resize(502);
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            revMapper[mapperIdx] = beginWord;
            mapper[beginWord] = mapperIdx++;
        }
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return {};
        }

        for (string word : wordList) {
            revMapper[mapperIdx] = word;
            mapper[word] = mapperIdx++;
        }
        

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isSequence(wordList[i], wordList[j])) {
                    edges[mapper[wordList[i]]].push_back(mapper[wordList[j]]);
                    edges[mapper[wordList[j]]].push_back(mapper[wordList[i]]);
                }
            }

            if (isSequence(wordList[i], endWord)) {
                edges[mapper[wordList[i]]].push_back(mapper[endWord]);
            }
        }
        
        for (string word : wordList) {
            if (isSequence(beginWord, word)) {
                edges[mapper[beginWord]].push_back(mapper[word]);
            }
        }

        prev.resize(mapperIdx);
        dist.resize(mapperIdx, 1000);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, mapper[beginWord]});
        dist[mapper[beginWord]] = 0;

        while (!pq.empty()) {
            int curD = pq.top().first, curN = pq.top().second; pq.pop();

            if (curD > dist[curN]) continue;

            for (int nxt : edges[curN]) {
                if (dist[nxt] > curD + 1) {
                    dist[nxt] = curD + 1;
                    prev[nxt].clear();
                    prev[nxt].insert(curN);
                    pq.push({dist[nxt], nxt});
                } else if (dist[nxt] == curD + 1) {
                    prev[nxt].insert(curN);
                }
            }
        }

        getAns(beginWord, endWord);

        return ans;
    }

    void getAns(string beginWord, string currentWord, vector<string> path = vector<string>()) {
        path.insert(path.begin(), currentWord);

        if (beginWord == currentWord) {
            ans.push_back(vector<string>(path));
            return;
        }

        for (int nxt : prev[mapper[currentWord]]) {
            getAns(beginWord, revMapper[nxt], path);
        }

        path.erase(path.begin());
    }

    bool isSequence(string word, string other) {
        int diffCount = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] != other[i]) ++diffCount;
            if (diffCount > 1) return false;
        }

        return true;
    }
};