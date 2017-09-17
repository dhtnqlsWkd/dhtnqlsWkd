#include <iostream>

using namespace std;

void fa(int **arr, int ** c_arr, int m, int n, int i, int j, int num);

int main()
{
	int m, n, i, j, num;
	int **arr, **c_arr;

	cin >> m >> n;

	arr = new int*[m];
	c_arr = new int*[m];
	for (i = 0; i < m; i++) {
		arr[i] = new int[n];
		c_arr[i] = new int[n];
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
			c_arr[i][j] = 0;
		}
	}

	num = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !c_arr[i][j]) {
				c_arr[i][j] = num;
				fa(arr, c_arr, m, n, i, j, num);
				num++;
			}
		}
	}
	num--;

	cout << num << endl;

	for (i = 0; i < m; i++) {
		delete[] arr[i];
		delete[] c_arr[i];
	}
	delete[] arr;
	delete[] c_arr;

	return 0;
}

void fa(int **arr, int ** c_arr, int m, int n, int i, int j, int num)
{
	if (j < n - 1) {
		if (arr[i][j + 1] == 1 && !c_arr[i][j + 1]) {
			c_arr[i][j + 1] = num;
			fa(arr, c_arr, m, n, i, j + 1, num);
		}
		if (i > 0) {
			if (arr[i - 1][j + 1] == 1 && !c_arr[i - 1][j + 1]) {
				c_arr[i - 1][j + 1] = num;
				fa(arr, c_arr, m, n, i - 1, j + 1, num);
			}
			
		}
		if (i < m - 1) {
			if (arr[i + 1][j + 1] == 1 && !c_arr[i + 1][j + 1]) {
				c_arr[i + 1][j + 1] = num;
				fa(arr, c_arr, m, n, i + 1, j + 1, num);
			}
		}
	}
	if (j > 0) {
		if (i > 0) {
			if (arr[i - 1][j - 1] == 1 && !c_arr[i - 1][j - 1]) {
				c_arr[i - 1][j - 1] = num;
				fa(arr, c_arr, m, n, i - 1, j - 1, num);
			}
		}
		if (arr[i][j - 1] == 1 && !c_arr[i][j - 1]) {
			c_arr[i][j - 1] = num;
			fa(arr, c_arr, m, n, i, j - 1, num);
		}
		if (i < m - 1) {
			if (arr[i + 1][j - 1] == 1 && !c_arr[i + 1][j - 1]) {
				c_arr[i + 1][j - 1] = num;
				fa(arr, c_arr, m, n, i + 1, j - 1, num);
			}
		}
	}
	if (i > 0) {
		if (arr[i - 1][j] == 1 && !c_arr[i - 1][j]) {
			c_arr[i - 1][j] = num;
			fa(arr, c_arr, m, n, i - 1, j, num);
		}
	}
	if (i < n - 1) {
		if (arr[i + 1][j] == 1 && !c_arr[i + 1][j]) {
			c_arr[i + 1][j] = num;
			fa(arr, c_arr, m, n, i + 1, j, num);
		}
	}
}
