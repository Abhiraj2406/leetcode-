class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size();
         if(n==0) return 0;
         int i =0;
         int j = 1;
         int unique = 1;
         while(j<n){
            if(nums[i]== nums[j]){
                j++;
                continue;
            }else{
                i++;
                nums[i]=nums[j];
                j++;
                unique++;
            }
         }
         return unique;
    }
};