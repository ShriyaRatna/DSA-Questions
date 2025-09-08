/*
Description
Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only 1.

Find the maximum score possible if you can change at most K elements of the array.

Input Format
The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated integers N, K.
The next line contains N space-separated integers which are either 0 or 1.

Output Format
For each test case, print the maximum score possible if you can change at most K elements of the array.

Constraints
1 ≤ T ≤ 10^4
1 ≤ N ≤ 10^5
0 ≤ K ≤ N
Sum of N across all test cases ≤ 10^6
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int mid, int k)
{
    int numOfZeroes = 0;
    for (int i = 0; i < mid; i++)
    {
        if (arr[i] == 0)
            numOfZeroes++;
    }

    if (numOfZeroes <= k)
        return true;

    for (int i = mid; i < n; i++)
    {
        if (arr[i - mid] == 0)
            numOfZeroes--;
        if (arr[i] == 0)
            numOfZeroes++;
        if (numOfZeroes <= k)
            return true;
    }
    return false;
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
        // cout << "\n\nTest next: \n";
        int n, k;
        cin >> n >> k;
        int arr[n];
        int left = k;
        int right = n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = left;
        while (left <= right)
        {
            // cout << left << " " << right << "\n";
            int mid = (right + left) / 2;
            if (check(arr, n, mid, k))
            {
                ans = mid;
                left = mid + 1;
                // cout << ans << "\n";
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }
}