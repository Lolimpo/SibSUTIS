#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    srand(time(NULL));
    ll i, j, k, n, razm, left1, right1, left2, right2, pr = 0, sr = 0;
	cin >> n;
	ll arr[n], temp[n];
	for(i = 0; i < n;i++)
		arr[i] = rand() % 101;

	/*cout << "Origin massive:" << endl;
	for(i = 0; i < n; i++)
		cout << arr[i] << " ";*/
    puts("");
	for(razm = 1; razm < n; razm *= 2 )
	{
		left1 = 0;
		k = 0;
		while(left1 + razm < n)
		{
			right1 = left1 + razm - 1;
			left2 = right1 + 1;
			right2 = left2 + razm - 1;
			if(right2 >= n)
				right2 = n - 1;
			i = left1;
			j = left2;

			while(i <= right1 && j <= right2)
			{
			    sr++;
			    pr++;
				if(arr[i] <= arr[j])
					temp[k++] = arr[i++];
				else
					temp[k++] = arr[j++];
			}
			while(i <= right1)
            {
                pr++;
				temp[k++] = arr[i++];
            }
			while(j <= right2)
            {
                pr++;
                temp[k++] = arr[j++];
            }
			left1 = right2 + 1;
		}
		for(i = left1; k < n; i++)
        {
            pr++;
            temp[k++] = arr[i];
        }
		for(i = 0; i < n;i++)
		{
		    pr++;
		    arr[i] = temp[i];
		}
/*
		cout << "Blocks: " << razm << endl;
		for(i = 0; i < n; i++)
            cout << arr[i] << " ";
        puts("");*/
	}
	/*cout << "Sorted: " << endl;
	for(i = 0; i < n; i++)
		cout << arr[i] << " ";*/
    puts(" ");
    cout << "\nCompares: " << sr << "\nChanges: " << pr << endl;
	return 0;
}
