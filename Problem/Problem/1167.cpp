#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
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


	cout << bigNode;//가장 먼 점

	bool* chk = new bool[n + 1]();
	int* dis = new int[n + 1]();

	que.push(bigNode);

	while (que.size())
	{
		int node = que.front();

		for (int j = 0; j < arr[node].size(); j += 2)
		{
			if (chk[arr[node][j]] == false)
			{
				que.push(arr[node][j]);

				dis[arr[node][j]] = dis[node] + arr[node][j + 1];

				if (dis[arr[node][j]] > leng2)
				{
					bigNode2 = arr[node][j];
				}
			}
		}
		chk[node] = true;
		que.pop();
	}

	cout << leng2;


	return 0;
}