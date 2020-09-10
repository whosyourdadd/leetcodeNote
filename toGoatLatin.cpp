class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        istringstream ss(S);
        string res, t;
        int cnt = 1;
        while (ss >> t) {
            res += ' ' + (vowel.count(t[0]) ? t : t.substr(1) + t[0]) + "ma" + string(cnt, 'a');
            ++cnt;
        }
        return res.substr(1);
        
    }
};
