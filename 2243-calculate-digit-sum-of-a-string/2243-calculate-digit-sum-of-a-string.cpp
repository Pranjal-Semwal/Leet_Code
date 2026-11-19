class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string next="";
            int n=s.size();
            for(int i=0;i<n;i=i+k){
                int sum=0;
                for(int j=i;j<n && j<i+k;j++){
                    sum+= s[j] -'0';
                }
                next+=to_string(sum);
            }
            s=next;
        }
        return s;
    }
};