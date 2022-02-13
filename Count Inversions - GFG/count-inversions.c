// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long i, j, k, inv_count = 0;
    
    i = left;
    j = mid;
    k = left;
    
    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            
            inv_count += (mid - i);
        }
    }
    
    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long int merge_Sort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, inv_count = 0;
    
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr, temp, left, mid);
        inv_count += merge_Sort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    
    long long ans = merge_Sort(arr, temp, 0, N - 1);
    return ans;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends