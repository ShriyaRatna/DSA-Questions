/*
Description
Given a rotated sorted array, find the index of the minimum element in the array. All the elements are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

int checker(int arr[], int index)
{
    if (arr[index] < arr[0])
        return 1;
    return 0;
}

int findMin(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int check = arr[0];
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (checker(arr, mid) == 1)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << findMin(arr, n) << endl;
    }
}