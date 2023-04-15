class Solution
{
private:
    void merge(int &count, int start, int mid, int end, vector<int> &nums)
    {

        int subArrayOneSize = mid - start + 1;
        int subArrayTwoSize = end - mid;

        int subArrayOne[subArrayOneSize];
        int subArrayTwo[subArrayTwoSize];

        for (int i = 0; i < subArrayOneSize; i++)
        {
            subArrayOne[i] = nums[start + i];
        }

        for (int i = 0; i < subArrayTwoSize; i++)
        {
            subArrayTwo[i] = nums[mid + i + 1];
        }

        int j = 0;
        for (int i = 0; i < subArrayOneSize; i++)
        {
            while (j < subArrayTwoSize && subArrayOne[i] > 2 * ((long)subArrayTwo[j]))
            {
                j++;
            }
            count += j;
        }

        int subArrayOneIndex = 0;
        int subArrayTwoIndex = 0;
        int mainIndex = start;
        while (subArrayOneIndex < subArrayOneSize && subArrayTwoIndex < subArrayTwoSize)
        {
            if (subArrayOne[subArrayOneIndex] <= subArrayTwo[subArrayTwoIndex])
            {
                nums[mainIndex] = subArrayOne[subArrayOneIndex];
                subArrayOneIndex++;
            }
            else
            {
                nums[mainIndex] = subArrayTwo[subArrayTwoIndex];
                subArrayTwoIndex++;
            }
            mainIndex++;
        }

        while (subArrayOneIndex < subArrayOneSize)
        {
            nums[mainIndex] = subArrayOne[subArrayOneIndex];

            subArrayOneIndex++;
            mainIndex++;
        }

        while (subArrayTwoIndex < subArrayTwoSize)
        {
            nums[mainIndex] = subArrayTwo[subArrayTwoIndex];

            subArrayTwoIndex++;
            mainIndex++;
        }
    }
    void mergeSort(int &count, int start, int end, vector<int> &nums)
    {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;

        mergeSort(count, start, mid, nums);
        mergeSort(count, mid + 1, end, nums);
        merge(count, start, mid, end, nums);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int count = 0;
        mergeSort(count, 0, nums.size() - 1, nums);

        return count;
    }
};