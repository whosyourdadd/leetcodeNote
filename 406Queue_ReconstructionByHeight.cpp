class Solution {
public:
 
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
        给出了一个数组，数组的每个元素表示一个人的身高以及在一个队伍前面不比他矮的人的个数。现在要重新排列，使得数组是满足条件的。
        */
        
        /*for(int i = 0 ; i < people.size() ; i++){
            for(int j = 0 ; j < people[0].size() ; j++)
                cout<<i<<" "<<j<<" "<<people[i][j]<<endl;
        }*/
        sort(people.begin(), people.end(),[](const vector<int> a, const vector<int> b){
            return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>>  res;
        for (auto p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;

    }
};
