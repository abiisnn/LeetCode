class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, vector<int>> bucket;
        for(int i = 0; i < nums.size(); i++) {
            bucket[nums[i]].push_back(i); // saving indexes
        }
        
        vector<int> sol(2, -1);
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            int sizeBucket = bucket[need].size();
            if(need == nums[i] && sizeBucket > 1) {
                sol[0] = bucket[need][0];
                sol[1] = bucket[need][1];
                break;
            } else if( need != nums[i] && sizeBucket) {
                sol[0] = i;
                sol[1] = bucket[need][0];
                break;
            }
        }
        return sol;
    }
};