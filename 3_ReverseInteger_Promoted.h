class Solution {
public:

    int reverse(int x) {

        long long ans = 0;

        while(x!=0){
            ans = ans * 10 + x%10;
            x/=10;
        }

        if(ans>INT_MAX||ans<INT_MIN)
            return 0;

    return static_cast<int>(ans);
    }
};

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();