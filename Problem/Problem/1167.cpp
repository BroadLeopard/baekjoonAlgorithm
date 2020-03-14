#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, x, y = 1, bigNode = 1, leng = 0, bigNode2 = 1, leng2 = 0;

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

	queue <int> que;
	bool* chk = new bool[n + 1]();
	int* dis = new int[n + 1]();

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
				}
			}
		}
		chk[node] = true;
		que.pop();
	}

	delete[] chk;
	delete[] dis;

	bool* chk2 = new bool[n + 1]();
	int* dis2 = new int[n + 1]();

	que.push(bigNode);

	while (que.size())
	{
		int node = que.front();

		for (int j = 0; j < arr[node].size(); j += 2)
		{
			if (chk2[arr[node][j]] == false)
			{
				que.push(arr[node][j]);

				dis2[arr[node][j]] = dis2[node] + arr[node][j + 1];

				if (dis2[arr[node][j]] > leng2)
				{
					leng2 = dis2[arr[node][j]];
				}
			}
		}
		chk2[node] = true;
		que.pop();
	}

	cout << leng2;

	delete[] chk2;
	delete[] dis2;
	return 0;
}