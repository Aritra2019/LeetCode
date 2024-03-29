class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low=0;
       int mid=0;
       int high=nums.size()-1;
       int temp=0;
       while(mid<=high){
           if(nums[mid]==0){
               temp=nums[mid];
               nums[mid]=nums[low];
               nums[low]=temp;
               mid++;
               low++;
           }
           else if(nums[mid]==1){
               mid++;
           }
           else {
               temp=nums[mid];
               nums[mid]=nums[high];
               nums[high]=temp;
               high--;
           }

       }
    }
};