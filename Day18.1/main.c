/* Leet_Code_Array_Problem:
Given a binary array nums,return the maximum number of consecutive 1's in the array.
Example:Input: nums[] = {1,1,0,1,1,1}
Output: 3
*/
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max_consecutive_ones = 0;
    int current_consecutive_ones = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            ++current_consecutive_ones;

            if (current_consecutive_ones > max_consecutive_ones)
            {
                max_consecutive_ones = current_consecutive_ones;
            }
        }
        else if (nums[i] == 0)
        {
            current_consecutive_ones = 0;
        }

    }
    printf("%d", max_consecutive_ones);

}

int main()
{
    int nums[] = { 1,1,1,1,0,1,1,1,0,0,1,1 };
    findMaxConsecutiveOnes(nums, sizeof(nums) / nums[0]);
    return 0;
}