class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || n==0) return 1;
        if(x==0) return 0;
        if(x==-1 && n%2==0) return 1;
        if(x==-1 && n%2!=0) return -1;
        long double ans=1;
        long double base=x;
        long num=n;
        if(n<0){
            base=1/base;
            num=-num;
        }
        while(num>0){
            if(num%2==1) ans*=base;
            base*=base;
            num/=2;
        }
        return (double)ans;
    }
};