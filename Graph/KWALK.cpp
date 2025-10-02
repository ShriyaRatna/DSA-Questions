/*
Description
You are given an N × N chessboard and a knight with starting position (Sx, Sy). You are given a final position (Fx, Fy). You have to find the minimum number of moves required to reach the final position.

Complete the function:

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy);


Input Format
The first line contains a single integer T - the number of test cases.
The first line of each test case contains five integers N Sx Sy Fx Fy - the size of the board, initial position and final position.

Output Format
For every test case print the minimum number of moves required. If it is not possible print -1.

Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 1000
1 ≤ Sx, Sy, Fx, Fy ≤ N
*/

#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    // Complete the function
    Sx--;
    Sy--;
    Fx--;
    Fy--;
    if (Sx == Fx && Sy == Fy)
    {
        return 0;
    }
    vector<vector<int>> visited(N, vector<int>(N, INF));

    queue<vector<int>> que;
    que.push({Sx, Sy, 1});

    while (!que.empty())
    {
        int x = que.front()[0];
        int y = que.front()[1];
        int num = que.front()[2];
        que.pop();
        // cout << x << " " << y << "\n";
        if (x == Fx && y == Fy)
            return visited[Fx][Fy] - 1;
        for (int i = 0; i < 8; i++)
        {
            int new_X = dx[i] + x;
            int new_Y = dy[i] + y;

            if (new_X < 0 || new_Y < 0)
                continue;
            if (new_X >= N || new_Y >= N)
                continue;

            if (visited[new_X][new_Y] == INF)
            {
                visited[new_X][new_Y] = num + 1;
                que.push({new_X, new_Y, num + 1});
            }
        }
    }

    return (-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
}
