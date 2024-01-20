#include<bits/stdc++.h>
#define boom -1
#define maxn 101
int a[maxn][maxn],b[maxn][maxn];
int n, m, num;
using namespace std;
void createBoom() {
	srand((unsigned int)time(NULL));
	int x, y;
	for (int i = 1; i <= num; i++) {
		x = rand() % n + 1;
		y = rand() % m + 1;
		if (a[x][y] != boom)a[x][y] = boom;
		else i--;
	}
}
void createNum() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == boom) {
				if (a[i - 1][j - 1] != boom && i - 1 > 0 && j - 1 > 0)a[i - 1][j - 1]++;
				if (a[i - 1][j] != boom && i - 1 > 0)a[i - 1][j]++;
				if (a[i - 1][j + 1] != boom && i - 1 > 0 && j + 1 <= m)a[i - 1][j + 1]++;
				if (a[i][j - 1] != boom && j - 1 > 0)a[i][j - 1]++;
				if (a[i][j + 1] != boom && j + 1 <= m)a[i][j + 1]++;
				if (a[i + 1][j - 1] != boom && i + 1 <= n && j - 1 > 0)a[i + 1][j - 1]++;
				if (a[i + 1][j] != boom && i + 1 <=n)a[i + 1][j]++;
				if (a[i + 1][j + 1] != boom && i + 1 <=n && j + 1 <= m)a[i + 1][j + 1]++;
			}
		}
	}
}
void print() {
	system("cls");
	for (int i = 0; i <= n; i++) {
		printf("%2d ", i);
		for (int j = 1; j <= m; j++) {
			if (i == 0)printf("%2d ", j);
			else if (b[i][j] == 2)printf(" ^ ");
			else if (b[i][j] == 0)printf(" - ");
			else printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}
void init() {
	cout << "提示:往下的坐标一律先纵后横" << endl;
	cout << "输入棋盘的长和宽:";
	cin >> n >> m;
	cout << "输入炸弹数量:";
	cin >> num;
	system("cls");
}
bool win() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != boom && b[i][j] == 1)sum++;
		}
	}
	return sum == (n * m - num);
}
void printdev() {
	system("cls");
	for (int i = 0; i <= n; i++) {
		printf("%2d ", i);
		for (int j = 1; j <= m; j++) {
			if (i == 0)printf("%2d ", j);
			else if (a[i][j] == boom)printf(" * ");
			else printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}
void change(int i, int j) {
	if (b[i - 1][j - 1] == 0 && i - 1 > 0 && j - 1 > 0 &&a[i-1][j-1]!=boom) {
		b[i - 1][j - 1] = 1;
		if (a[i - 1][j - 1] == 0)change(i - 1, j - 1);
	}
	if (b[i - 1][j] == 0 && i - 1 > 0&&a[i-1][j]!=boom) {
		b[i - 1][j] = 1;
		if (a[i - 1][j] == 0)change(i - 1, j);
	}
	if (b[i - 1][j + 1] == 0 && i - 1 > 0 && j + 1 <= m && a[i-1][j+1]!=boom) {
		b[i - 1][j + 1] = 1;
		if (a[i - 1][j + 1] == 0)change(i - 1, j + 1);
	}
	if (b[i][j - 1] == 0 && j - 1 > 0 && a[i][j-1]!=boom) {
		b[i][j - 1] = 1;
		if (a[i][j - 1] == 0)change(i, j - 1);
	}
	if (b[i][j + 1] == 0 && j + 1 <= m && a[i][j+1]!=boom) {
		b[i][j + 1] = 1;
		if (a[i][j + 1] == 0)change(i, j + 1);
	}
	if (b[i + 1][j - 1] == 0 && i + 1 <= n && j - 1 > 0 && a[i+1][j-1]!=boom) {
		b[i + 1][j - 1] = 1;
		if (a[i + 1][j - 1] == 0)change(i + 1, j - 1);
	}
	if (b[i + 1][j] == 0 && i + 1 <= n && a[i+1][j]!=boom) {
		b[i + 1][j] = 1;
		if (a[i + 1][j] == 0)change(i + 1, j);
	}
	if (b[i + 1][j + 1] == 0 && i + 1 <= n && j + 1 <= m && a[i+1][j+1]!=boom) {
		b[i + 1][j + 1] = 1;
		if (a[i + 1][j + 1])change(i + 1, j + 1);
	}
}
int main() {
	init();
	createBoom();
	createNum();
	int x, y, operation;
	while (true) {
		print();
		cout << "输入要检查的坐标:";
		cin >> x >> y;
		cout << "输入操作(1为打开,2为挂旗):";
		cin >> operation;
		if (operation == 1) {
			if (a[x][y] == boom) {
				printdev();
				cout << "你被炸死了!";
				return 0;
			}
			else if (a[x][y] == 0&&b[x][y]!=2) {
				b[x][y] = 1;
				change(x, y);
			}
			else {
				if (b[x][y] != 2)b[x][y] = 1;
			}
		}
		else if (operation == 2) {
			if (b[x][y] == 0)b[x][y] = 2;
		}
		else cout << "无效操作!";
		if (win())break;
	}
	printdev();
	printf("恭喜!你赢了!");
	return 0;
}
