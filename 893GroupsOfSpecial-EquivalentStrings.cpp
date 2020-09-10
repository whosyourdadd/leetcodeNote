/*
这道题定义了一种特殊相等的关系，就是说对于一个字符串，假如其偶数位字符之间可以互相交换，且其奇数位字符之间可以互相交换，交换后若能跟另一个字符串相等，则这两个字符串是特殊相等的关系。
现在给了我们一个字符串数组，将所有特殊相等的字符串放到一个群组中，问最终能有几个不同的群组。最开始的时候博主没仔细审题，以为是随意交换字母，就直接对每个单词进行排序，然后扔到一个 HashSet 
中就行了。后来发现只能是奇偶位上互相交换，于是只能现先将奇偶位上的字母分别抽离出来，然后再进行分别排序，之后再合并起来组成一个新的字符串，再丢到 HashSet 中即可，利用 HashSet 的自动去重复功能
，这样最终留下来的就是不同的群组了
*/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for (string word : A) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};
