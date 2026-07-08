class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      int sum = 0;

        int rem1_first = INT_MAX, rem1_second = INT_MAX;
        int rem2_first = INT_MAX, rem2_second = INT_MAX;
     for (int num : nums) {
            sum += num;

            if (num % 3 == 1) {
                if (num < rem1_first) {
                    rem1_second = rem1_first;
                    rem1_first = num;
                }
                else if (num < rem1_second) {
                    rem1_second = num;
                }
            }

            else if (num % 3 == 2) {
                if (num < rem2_first) {
                    rem2_second = rem2_first;
                    rem2_first = num;
                }
                else if (num < rem2_second) {
                    rem2_second = num;
                }
            }
        }

        if (sum % 3 == 0)
            return sum;

        if (sum % 3 == 1) {
            int option1 = (rem1_first == INT_MAX) ? 0 : sum - rem1_first;
            int option2 = (rem2_second == INT_MAX) ? 0 : sum - rem2_first - rem2_second;
            return max(option1, option2);
        }

        int option1 = (rem2_first == INT_MAX) ? 0 : sum - rem2_first;
        int option2 = (rem1_second == INT_MAX) ? 0 : sum - rem1_first - rem1_second;

        return max(option1, option2);
    }
}; 
 