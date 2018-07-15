class Solution {
public:
    int lLimit = -pow(2,31)/10-1;
    int rLimit = (pow(2,31)-1)/10+1;

    bool check(int &a){

        if(a<0)
            return a<=lLimit;
        else
            return a>=rLimit;
    }


    int reverse(int x) {
        queue<int> numQueue;

        while(x!=0){
            numQueue.push(x%10);
            x/=10;
        }

        int ans = 0;
        while(!numQueue.empty()){
            if(check(ans))
                return 0;

            ans *= 10;
            ans += numQueue.front();
            numQueue.pop();

        }

    return ans;
    }
};