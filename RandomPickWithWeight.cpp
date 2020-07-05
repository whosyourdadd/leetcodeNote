/*
题目大意
这个题目不太好理解，是要求按照权重挑选索引。比如[1,99]中，有1%的概率挑选到索引0，有99%的概率挑选到索引1.

解题方法
这个题很巧妙，我是想不出来的。做法是把概率分布函数转化为累计概率分布函数。然后通过随机数，进行二分查找。

比如，输入是[1,2,3,4]，那么概率分布是[1/10, 2/10, 3/10, 4/10, 5/10]，累积概率分布是[1/10, 3/10, 6/10, 10/10].总和是10。如果我们产生一个随机数，在1~10之中，然后判断这个数字在哪个区间中就能得到对应的索引。

对于输入[1,2,3,4]，计算出来的preSum是[1,3,6,10]，然后随机选一个s，然后查找s属于哪个区间，各区间的含义是：
————————————————
版权声明：本文为CSDN博主「负雪明烛」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/fuxuemingzhu/java/article/details/81807215

*/
class Solution {
private:
    vector<int> sum;
public:
     Solution(vector<int> w) {
        sum = w;
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back(), left = 0, right = sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= x) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
