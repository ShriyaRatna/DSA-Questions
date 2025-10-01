/*
Description
Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum − target) is minimum). Print the minimum absolute value of (sum − target). You cannot select an index more than once. All three indexes should be distinct.

Input Format
The first line contains T, the number of test cases (1 ≤ T ≤ 100).
For each test case, the first line contains two space-separated integers N, target where 3 ≤ N ≤ 10^3, −10^18 ≤ target ≤ 10^18.
The next line contains N space-separated integers Ai where −10^9 ≤ Ai ≤ 10^9.
The sum of N across all test cases ≤ 10^4.

Output Format
For each test case print the minimum absolute value of (sum − target).

Constraints

3 ≤ N ≤ 10^3

−10^18 ≤ target ≤ 10^18

−10^9 ≤ Ai ≤ 10^9

Sum of N over all test cases ≤ 10^4
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = arr[0] + arr[1] + arr[2];

        for (int i = 1; i < n - 1; i++)
        {
            int left = 0;
            int right = n - 1;
            while (true)
            {
                if (abs(arr[left] + arr[i] + arr[right] - target) < abs(ans - target))
                {
                    ans = arr[left] + arr[i] + arr[right];
                }
                if (arr[left] + arr[i] + arr[right] > target)
                    right--;
                else
                    left++;
                if (left == i || right == i)
                    break;
            }
        }

        cout << abs(ans - target) << "\n";
    }
}