class Solution {
public:
    /*
    我们知道，两点之间的直线距离最短，在本题中，我们只能沿着每个格子的边或者对角线移动，因为对角线移动的效率最高，因此我们应该优先对角线移动（对角线移动一步相当于x和y个移动一次），剩下的部分再做边移动即可。

比如我们想从(1,1)移动到(4,5)，我们可以先对角线移动3步到(4,4)，这时，相当于x移动了3，y移动了3。然后再y方向移动1步到(4,5)，y移动了1。总共花费4步，即x总共移动3，y总共移动4。我们发现，最后的结果应是，x和y所需要移动的最大值即是两点间的最短距离。

根据上面的思路，循环遍历所有两点之间的最短距离，求和即是结果。
    */
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        for(int i = 0; i < points.size()-1;i++){
            int x_dist =  abs(points[i][0] - points[i+1][0]);
            int y_dist =  abs(points[i][1] - points[i+1][1]);
            sum += max(x_dist,y_dist);
        }   

        return sum;
    }
};
