#include <iostream>
#include <queue>
#include <iomanip> 
#include <stdlib.h>

using namespace std;

struct Edge {
	int From, To, Length;
}All_Edges[1000];

const int CMP(const void *a, const void *b) {
	Edge *A = (Edge*)a;
	Edge *B = (Edge*)b;
	return A->Length - B->Length;
}

double cal(int *stone[]) {
	qsort(All_Edges, nEdges, sizeof(Edge), CMP);

	return 0;
}
int main() {
	queue<double> c;
	int sNum;
	cin >> sNum;
	while (!cin.eof()&&sNum!=0) {
		int **stone = new int*[sNum];// store location of x y;
		for (int i = 0;i < sNum;i++) {
			stone[i] = new int[2];
		}
		for (int i = 0;i < sNum;i++) {
			cin >> stone[i][0] >> stone[i][1];
		}
		c.push(cal(stone));
		cin >> sNum;
	}
	int count = 1;
	while (!c.empty()) {
		cout << "Scenario #" << count << endl;
		count++;
		cout << "Frog Dsitance = " <<setprecision(3)<<c.front() << endl;
		c.pop();
	}

	return 0;

}
