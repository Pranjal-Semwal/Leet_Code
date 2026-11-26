class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int> arr(j+1);
        int k=j;
        while(i<=j){
            if(nums[i]*nums[i]<nums[j]*nums[j]){
                arr[k--]=nums[j]*nums[j];
                j--;
            } else{
                arr[k--]=nums[i]*nums[i];
                i++;
            }
        }
        return arr;
    }
};