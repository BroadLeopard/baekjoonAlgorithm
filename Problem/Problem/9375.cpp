#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	string a, b;
	
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		vector <pair<string, int>> x;

		int mul = 1;

		if (n == 0)
		{
			cout << 0 << endl;
			continue;
		}

		cin >> a >> b;

		x.push_back({ b,1 });

		for (int j = 0; j < n - 1; j++)
		{
			cin >> a >> b;

			for (int k = 0; k <= x.size(); k++)
			{
				if (k == x.size())
				{
					x.push_back({ b,1 });
					break;
				}

				if (x.at(k).first == b)
				{
					x.at(k).second++;
					break;
				}	
			}
		}

		for (int i = 0; i < x.size(); i++)
		{
			mul *= (x.at(i).second + 1);
		}

		cout << mul - 1 << endl;
	}

	return 0;
}