#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, x, y = 1;

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


	return 0;
}