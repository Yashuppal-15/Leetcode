class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int,char>> pq;
        for (auto &p : freq) pq.push({p.second, p.first});

        string res = "";
        while (pq.size() > 1) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();

            res.push_back(c1);
            res.push_back(c2);

            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }

        if (!pq.empty()) {
            auto [f, c] = pq.top();
            if (f > 1) return ""; 
            res.push_back(c);
        }

        return res;
    }
};