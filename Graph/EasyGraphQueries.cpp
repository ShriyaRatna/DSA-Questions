/*
Description
You are given an undirected graph G with N nodes and M edges. You have to answer Q queries. Each query is one of the following two types.

Type 1:
1 X: Print the size of the connected component containing node X.

Type 2:
2 X Y: Print YES if node X and Y belong to the same connected component, otherwise print NO.

Input Format
The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 10^5).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains a query of one of the two types described above.

Output Format
Print Q lines as the answers to the Q queries, each on a new line.

Constraints
1 ≤ N, M, Q ≤ 10^5
The graph is undirected. There can be self-loops and multiple edges. The sum of input sizes fits within standard limits.

*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<int> &visited, int num, vector<vector<int>> &arr)
{
    visited[x] = num;

    for (auto v : arr[x])
    {
        if (!visited[v])
        {
            dfs(v, visited, num, arr);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> arr(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;

        arr[n].push_back(m);
        arr[m].push_back(n);
    }

    vector<int> visited(N + 1, 0);
    int num = 1;
    for (int i = 1; i < N + 1; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, num, arr);
            num++;
        }
    }

    vector<int> freq(num, 0);
    for (int i = 1; i < visited.size(); i++)
    {
        freq[visited[i]]++;
    }

    for (int i = 0; i < Q; i++)
    {
        int que;
        cin >> que;

        if (que == 1)
        {
            int num;
            cin >> num;

            cout << freq[visited[num]] << "\n";
        }
        else
        {
            int num1, num2;
            cin >> num1 >> num2;

            if (visited[num1] == visited[num2])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}