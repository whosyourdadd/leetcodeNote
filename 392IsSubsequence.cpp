class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        int index = 0;
        
        for(int i=0;i<t_len;i++){
            if(t[i]==s[index])
                index++;
            if(index==s_len)
                return true;
        }
        if(index==s_len)
            return true;
        
        return false;
    
    }
};
