class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        /*
        1. 迴圈文字列表。
        2. 將每個文字轉成字符陣列並迴圈
        3. 將每個字符依照ASCII表的規則扣除97（直接減'a'也可），即為摩斯密碼陣列中該字母所對映的符號索引。
        4. 從摩斯密碼陣列表中取出該字母對映的密碼，並串接成字串。
        5. 將字串放入Set中確保唯一。
        6. 計算Set中元素的數量並回傳。
        */
        vector<string> vec{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> set;
        for(int i = 0; i < words.size(); i++){
            string s;
            for(char c : words[i]){
                s.append(vec[c - 'a']);
            }
            set.insert(s);
        }
        return set.size();
    }
};
