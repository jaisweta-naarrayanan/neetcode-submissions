class Solution {
public:
    bool checkK(vector<int>& piles, int k, int h){
        int c = 0;
        for(int i=0; i<piles.size(); i++){
            int bana = piles[i];
            c+=bana/k;
            bana = bana%k;
            if(bana!=0) c++; 
            if(c>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mink = 1, maxk = 0;
        for(int i:piles) maxk = max(maxk,i);
        int ansk=maxk;
        while(mink<=maxk){
            int midk = mink + (maxk-mink)/2;
            bool ck = checkK(piles,midk, h);
            cout<<midk<<":"<<ck<<"; ";
            if( ck == true){
                ansk = midk;
                maxk = midk-1;
            }
            else mink = midk+1;
        }
        return ansk;
    }
};
