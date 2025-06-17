class Solution {
public: 
    int timeToEat(vector<int> &piles,int &k){
        int time = 0;
        for(int &x : piles){
            time += (x/k);
            if(x % k) time++;
        } return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;

        for(int &x : piles){
            if(x > high) high = x;
        }

        while(low < high){
            int mid = low + (high-low)/2;

            if(timeToEat(piles,mid) <= h){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};