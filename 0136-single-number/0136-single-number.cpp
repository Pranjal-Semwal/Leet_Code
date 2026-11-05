class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int res=INT_MAX;
        while(j<nums.size()-1){
            if(nums[i]!=nums[j]) {res=nums[i]; break;}
            i+=2;
            j+=2;
        }
        if(res==INT_MAX) return nums[n-1];
        return res;
    }
};