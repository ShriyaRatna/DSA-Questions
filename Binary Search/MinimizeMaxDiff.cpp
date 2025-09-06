/*
Description
You are given N distinct points on the number line in a sorted array A. You can place at most K more points on the line (integer coordinates only). You have to make the maximum separation between any two consecutive points in the final configuration as minimum as possible. Output this minimal value.

Note: You can place the points anywhere you like, but you cannot place more than one point at the same position on the line.

*/

#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int mid, int k)
{
    int num = 0;
    for (int i = 1; i < n; i++)
    {
        num += (arr[i] - arr[i - 1] + mid - 1) / mid - 1;
    }
    return num <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int left = 1, right = arr[n - 1] - arr[0];
        int ans = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(arr, n, mid, k))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << ans << endl;
    }
}