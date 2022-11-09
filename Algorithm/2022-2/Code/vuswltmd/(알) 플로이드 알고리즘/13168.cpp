#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

const int INF = 100 * 1000000 * 10;
int N, R;
unordered_map<string, int> city;
vector<string> Tour;
int M;
int K;
double naeilo[105][105];
double vehicle[105][105];
double naeilo_cost = 0;
double vehicle_cost = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R;

	for (int i = 1; i <= N; i++)
	{
		string c;
		cin >> c;
		city[c] = i;
	}

	cin >> M;

	for (int i = 1; i <= M; i++)
	{
		string c;
		cin >> c;

		Tour.push_back(c);
	}

	cin >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			naeilo[i][j] = INF;
			vehicle[i][j] = INF;
		}
	}

	for (int i = 1; i <= K; i++)
	{
		string typei, a, b;

		double cost;
		cin >> typei >> a >> b >> cost;

		int start = city[a];
		int end = city[b];

		vehicle[start][end] = min(vehicle[start][end], cost);
		vehicle[end][start] = min(vehicle[end][start], cost);

		if (typei == "ITX-Saemaeul" || typei == "Mugunghwa" || typei == "ITX-Saemaeul")
		{
			naeilo[start][end] = 0;
			naeilo[end][start] = 0;
		}
		else if (typei == "S-Train" || typei == "V-Train")
		{
			naeilo[start][end] = min(naeilo[start][end], cost / 2);
			naeilo[end][start] = min(naeilo[end][start], cost / 2);
		}
		else
		{
			naeilo[start][end] = min(naeilo[start][end], cost);
			naeilo[end][start] = min(naeilo[end][start], cost);
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (vehicle[i][k] + vehicle[k][j] < vehicle[i][j])
					vehicle[i][j] = vehicle[i][k] + vehicle[k][j];
				if (naeilo[i][k] + naeilo[k][j] < naeilo[i][j])
					naeilo[i][j] = naeilo[i][k] + naeilo[k][j];
			}
		}
	}

	for (int i = 1; i < M; i++)
	{
		int start = city[Tour[i - 1]];
		int end = city[Tour[i]];

		naeilo_cost += naeilo[start][end];
		vehicle_cost += vehicle[start][end];
	}
	naeilo_cost += R;

	if (vehicle_cost > naeilo_cost) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

}
