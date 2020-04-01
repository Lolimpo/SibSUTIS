#include <bits/stdc++.h>

using namespace std;

struct item{
	int m;
	int c;
};

void check_num(vector< vector <int>> &items_count, item *t, int item_n, int temp_i, int m)
{
	for(auto i = 0; i < item_n; i++)
	{
		items_count[m][i] = items_count[m - t[temp_i].m][i];
	}
	items_count[m][temp_i]++;
}

int main()
{
	int item_n;
	int backpack_c;
	int temp, temp_i;
	cout << "Enter number of items: ";
	cin >> item_n;
	item *t = new item[item_n];
	cout << "Enter item's weight and cost:" << endl;
	for(auto i = 0; i < item_n; i++)
	{
		cin >> t[i].m >> t[i].c;
	}
	cout << "Enter maximal weight:" << endl;
	cin >> backpack_c;
	vector <int> f(backpack_c + 1, 0);
	vector <vector <int>> items_count(backpack_c + 1, vector<int> (item_n, 0)); //3 3 8 5 14 8 23

	for(auto m = 1; m <= backpack_c; m++)
	{
		f[m] = f[m - 1];
		for(auto i = 0; i < item_n; i++)
		{
			temp = f[m];
			if(t[i].m <= m)
			{				
				f[m] = max(f[m], f[m - t[i].m] + t[i].c);
			}
			if(f[m] != temp)
			{
				temp_i = i;
			}		
		}
		if(f[m] != f[m - 1])
		{
			check_num(items_count, t, item_n, temp_i, m);
			for(auto j = 0; j < item_n; j++)
				items_count[backpack_c][j] = items_count[m][j];
		}	
	}
	int weigth =0;
	cout << "Maximal cost for " << backpack_c << " kg backpack: " << f[backpack_c] << endl;	
	for(auto i = 0; i < item_n; i++){
		cout << i + 1 << "- items were " << items_count[backpack_c][i] << " taken." << endl;
		weigth += t[i].m * items_count[backpack_c][i];
	}
	cout << "Gotten weight:" << weigth << endl;
	return 0;
}
