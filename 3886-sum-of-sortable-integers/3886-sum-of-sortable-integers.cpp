class Solution {
public:
    bool isSubarraySortable(vector<int>& nums, int k)
    {
        int n = nums.size();
        if(k == 1)
        {
            for(int i = 0; i < n - 1; i++) 
            {
                if(nums[i] > nums[i+1])
                    return false;
            }
            return true;
        }

        int prev_max = INT_MIN;

        for(int i = 0; i < n; i += k)
        {
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);
            
            int drops = 0;
            for(int j = 0; j < k; j++) {
                if(temp[j] > temp[(j + 1) % k]) {
                    drops++;
                }
            }
            if(drops > 1) {
                return false; 
            }
            vector<int> v1 = temp;
            sort(v1.begin(), v1.end());

            if(v1[0] < prev_max) {
                return false;
            }
            prev_max = v1[k-1];
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return 1;
        if(n == 2)
        {
            if(nums[0] > nums[1])
                return 2;
            else
                return 3;
        }
        int res = 0;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                if(isSubarraySortable(nums, i))
                {
                    res += i;
                }
                if(n / i != i && isSubarraySortable(nums, n / i))
                {
                    res += n / i;
                }
            }
        }
        return res;
    }
};