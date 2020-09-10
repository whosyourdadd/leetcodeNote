class Solution {
public:
/*
我们可以通过计算去A市、B市之间花费的差值cost[i][0]-cost[i][1]，来判断哪一部分人去A市，哪一部分人去B市，差值最小的人去A市，
因为差值越小，去A市是越省钱的。只要把去A市的人确定了，剩下的都去B市就行。
*/
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> refund;
        int N = costs.size()/2;
        int minCost = 0;
        for(vector<int> cost : costs){
            minCost += cost[0];
            refund.push_back(cost[1] - cost[0]); 
        }
        sort(refund.begin(), refund.end());
        for(int i = 0; i < N; i++){
            minCost += refund[i];
        }
        return minCost;
        
    }
};
