/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result;
    result = malloc(sizeof(char)*2);
    //int count = 0;
    for(int i = 0 ; i < numsSize-1 ; i++)
    {
        for(int j = i+1 ; j<numsSize; j++ )
        {
            if(nums[i] + nums[j] == target)
            {
                //count++;
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return -1;
}
