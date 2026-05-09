class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        int rcnt = n/groupSize;
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i:hand){
            mp[i]++;
            minh.push(i);
        }
        int hands = 0;
        
        while(hands<rcnt){
            while(mp[minh.top()] == 0)
                minh.pop();
            int num = minh.top();
            int cnt = 1;
            mp[num]--;
            while(cnt<groupSize){
                if(mp.find(num+1) == mp.end() || mp[num+1] == 0)
                    return false;
                cnt++;
                mp[num+1]--; 
                num++;       
            }
            hands++;
        }
        return hands == rcnt;
    }
};
