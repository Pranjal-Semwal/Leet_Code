class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix(n);
        const int MOD = 1e9 + 7;
        prefix[0]=arr[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+arr[i];
        long long count_even=0;
        long long count_odd=0;
        long long res=0;
        for(int i=0;i<n;i++){
            if(prefix[i]%2==0){
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