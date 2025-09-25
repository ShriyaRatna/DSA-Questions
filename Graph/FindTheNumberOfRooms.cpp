/*
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares. Each character in the map is either ′.′ (floor) or ′#′ (wall).

Input Format
The first input line has two integers n and m: the height and width of the map. Then there are n lines of m characters describing the map.

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m;

void dfs(vector<vector<char>> &arr, int i, int j, vector<vector<int>> &visited)
{
    visited[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        if (dx[k] + i < 0 || dx[k] + i >= n)
            continue;
        if (dy[k] + j < 0 || dy[k] + j >= m)
            continue;
        if (arr[dx[k] + i][dy[k] + j] == '#')
            continue;
        if (!visited[dx[k] + i][dy[k] + j])
        {
            dfs(arr, dx[k] + i, dy[k] + j, visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
                continue;
            if (visited[i][j])
                continue;
            dfs(arr, i, j, visited);
            num++;
            // cout << num << "\n";
        }
    }

    cout << num;
}
