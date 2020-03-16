#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int t, n, m, x, cnt = 0;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		vector <int> vec;
		queue <pair<int, int>> que;

		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			cin >> x;

			vec.push_back(x);
			que.push({ x, j });
		}

		sort(vec.begin(), vec.end());
		
		while (1)
		{
			if (que.front().first == vec.back())
			{
				if (que.front().second == m)
				{
					cout << ++cnt << endl;
					break;
				}
				else
				{
					vec.pop_back();
					que.pop();
					cnt++;
				}
			}
			else
			{
				auto k = que.front();
				que.pop();
				que.push(k);
			}
		}

		cnt = 0;
	}


	return 0;
}