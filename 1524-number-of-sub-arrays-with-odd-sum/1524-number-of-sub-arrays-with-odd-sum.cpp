class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        const int MOD = 1e9 + 7;
        long long count_even=0;
        long long count_odd=0;
        long long res=0;
        long long prefix=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            if(prefix%2==0){
                count_even++;
                res+=count_odd;
            } else{
                count_odd++;
                res++;
                res+=count_even;
            }
            res%=MOD;
        }
        return res;
    }
};