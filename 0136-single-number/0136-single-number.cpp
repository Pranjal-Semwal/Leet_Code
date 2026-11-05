class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        int i=0;
        int res=INT_MAX;
        while(i<nums.size()-1){
            if(nums[i]!=nums[i+1]) {res=nums[i]; break;}
            i+=2;
        }
        if(res==INT_MAX) return nums[n-1];
        return res;
    }
};