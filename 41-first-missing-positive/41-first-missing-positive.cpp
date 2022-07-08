class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int minVal = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                    if(nums[i] == minVal){
                        minVal++;
                        while(i + 1 < nums.size() && nums[i] == nums[i + 1])i++;
                    }else{
                    break;
                }
            }     
        }
        return minVal;
    }
};