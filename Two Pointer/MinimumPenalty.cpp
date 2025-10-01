/*
Description

Given an array of N integers and an integer D. Consider all subarrays with length D, the penalty of the subarray is the number of distinct elements present in the subarray. Find a subarray of length D with minimum penalty. Print the minimum penalty.

Input Format

The first line contains an integer T, the number of test cases
(1 ≤ T ≤ 10,000)

For each test case:

The first line contains two integers N and D, where
1 ≤ N ≤ 10⁶ ,
1 ≤ D ≤ N

The second line contains N space-separated integers Aᵢ, where
0 ≤ Aᵢ ≤ 10⁶

The sum of N over all test cases does not exceed 5 × 10⁶

Output Format

For each test case, print the minimum penalty in a new line.

Constraints

1 ≤ T ≤ 10⁴

1 ≤ N ≤ 10⁶

1 ≤ D ≤ N

0 ≤ Aᵢ ≤ 10⁶

The sum of N over all test cases does not exceed 5 × 10⁶
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        unordered_map<int, int> freq;
        int count = 0;
        for (int i = 0; i < d; i++)
        {
            freq[arr[i]]++;
            if (freq[arr[i]] == 1)
                count++;
        }
        int mini = count;

        for (int i = d; i < n; i++)
        {

            if (--freq[arr[i - d]] == 0)
            {
                freq.erase(arr[i - d]);
                count--;
            }

            freq[arr[i]]++;
            if (freq[arr[i]] == 1)
                count++;
            mini = min(count, mini);
        }

        cout << mini << "\n";
    }
}