class Solution {
public:
    int fmax(vector<int>& piles){
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++){
         maxi = max(maxi,piles[i]);
    }
    return maxi;
}
    long long freq(vector<int>& piles ,int mid){
    int n= piles.size();
    long long total=0;
    for(int i=0;i<n;i++){
        int d=ceil((double)piles[i]/(double)mid);
        total+=d;
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
    int high=fmax(piles);
        int ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long total=freq(piles,mid);
        if(total<=h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    }
};