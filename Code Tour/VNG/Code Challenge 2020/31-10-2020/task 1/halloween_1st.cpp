#include <iostream>
using namespace std;

int a[400][400];
int t[400][400] = { 0 };
int k;
int n;

void deleteCNV(int i, int j)
{
	for (int u = i; u< i + k; u++)
		for (int v = j; v < j + k; v++)
		{
			if (a[u][v] == -1) 
				a[u][v] = -2;
		}
}

void restoreCNV(int i, int j)
{
	for (int u = i; u < i + k; u++)
		for (int v = j; v < j + k; v++)
		{
			if (a[u][v] == -2) a[u][v] = -1;
		}
}

void restoreTick()
{
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
		{
			t[u][v] = 0;
		}
}

int tryCollect(int i, int j)
{
	if (i < 0 || i == n || j < 0 || j == n) return 0;
	if (t[i][j] == 1) return 0;
	if (a[i][j] == -1) return 0;

	t[i][j] = 1;
	int tren = tryCollect(i - 1, j);
	int duoi = tryCollect(i + 1, j);
	int trai = tryCollect(i, j - 1);
	int phai = tryCollect(i, j + 1);
	
	int money = 0;
	if (a[i][j] == 1)
	{
		money = 1 + tren + duoi + trai + phai;
	}
	else money = tren + duoi + trai + phai;

	//t[i][j] = 0;
	return money;
}

void input()
{
	cout << "n = ";	cin >> n;
	cout << "k = ";	cin >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
}

void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
}



int main()
{
	input();
	//output();
	int max = 0;
	for (int i = 0; i<=n-k; i++)
		for (int j = 0; j <= n - k; j++)
		{
			deleteCNV(i, j);
			int money = tryCollect(i, j);
			restoreCNV(i, j);
			restoreTick();
			if (max < money) max = money;
		}

	cout << "Max money: " << max << endl;

	return 0;
}