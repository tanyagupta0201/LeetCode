class Solution
{
public:
    int merge(vector<int> &a, int *tmp, int left, int mid, int right)
    {
        int i, j;
        i = left;
        j = mid + 1;

        int count = 0;
        
        while ((i <= mid))
        {
            while (j <= right and a[i] > 2LL * a[j])
            {
                j++;
            }
            
            count += (j - mid - 1);
            i++;
        }
        
        int p, q, k;
        p = left;
        q = mid + 1;
        k = left;
        
        while ((p <= mid) and (q <= right))
        {
            if (a[p] <= a[q])
            {
                tmp[k++] = a[p++];
            }
            else
            {
                tmp[k++] = a[q++];
            }
        }
        
        while (p <= mid)
        {
            tmp[k++] = a[p++];
        }
        
        while (q <= right)
        {
            tmp[k++] = a[q++];
        }
        
        for (int i = left; i <= right; i++)
        {
            a[i] = tmp[i];
        }
        
        return count;
    }
    
    int mergesort(vector<int> &a, int *tmp, int left, int right)
    {
        int cnt = 0;
        int mid;
        
        if (left < right)
        {
            mid = left + (right - left) / 2;
            
            cnt += mergesort(a, tmp, left, mid);
            cnt += mergesort(a, tmp, mid + 1, right);
            cnt += merge(a, tmp, left, mid, right);
        }
        
        return cnt;
    }
    
    int reversePairs(vector<int> &a)
    {
        int n = a.size();
        int tmp[n];
        
        return mergesort(a, tmp, 0, n - 1);
    }
};