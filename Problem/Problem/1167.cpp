#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool chk[100001];
int dis[100001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	queue <int> que;
	int n, x, y = 1, bigNode = 0, leng = 0;

	cin >> n;

	vector <vector<int>> arr(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> x;

		while (1)
		{
			cin >> y;

			if (y == -1)
			{
				y = 1;
				break;
			}
			arr[x].push_back(y);
		}
	}

	que.push(1);

	while (que.size())
	{
		int node = que.front();

		for (int j = 0; j < arr[node].size(); j += 2)
		{
			if (chk[arr[node][j]] == false)
			{
				que.push(arr[node][j]);

				dis[arr[node][j]] = dis[node] + arr[node][j + 1];

				if (dis[arr[node][j]] > leng)
				{
					bigNode = arr[node][j];
					leng = dis[arr[node][j]];
				}
			}
		}
		chk[node] = true;
		que.pop();
	}

	que.push(bigNode);

	bigNode = 0;
	leng = 0;

	for (int i = 1; i <= n; i++)
	{
		chk[i] = false;
		dis[i] = 0;
	}

	while (que.size())
	{
		int node = que.front();

		for (int j = 0; j < arr[node].size(); j += 2)
		{
			if (chk[arr[node][j]] == false)
			{
				que.push(arr[node][j]);

				dis[arr[node][j]] = dis[node] + arr[node][j + 1];

				if (dis[arr[node][j]] > leng)
				{
					leng = dis[arr[node][j]];
				}
			}
		}
		chk[node] = true;
		que.pop();
	}

	cout << leng;

	return 0;
}