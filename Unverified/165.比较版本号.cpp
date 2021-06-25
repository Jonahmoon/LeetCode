/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size(),end=max(n1,n2);
        for(int p1=0,p2=0;p1<end||p2<end;p1++,p2++){
            int v1=0,v2=0;
            while(p1<n1&&version1[p1]!='.')v1=v1*10+version1[p1++]-'0';            
            while(p2<n2&&version2[p2]!='.')v2=v2*10+version2[p2++]-'0';
            if(v1>v2)return 1;
            else if(v1<v2)return -1;
        }
        return 0;
    }
};
// @lc code=end

