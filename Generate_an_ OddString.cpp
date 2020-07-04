class Solution {
public:
/*
Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.
*/
    string generateTheString(int n) {
        return n % 2 ? string(n, 'a') : string(n - 1, 'a') + 'b';
    }
};
