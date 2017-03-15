#include <iostream>
#include <queue>
#include <iomanip> 
#include <stdlib.h>

using namespace std;

struct Edge {
	int From, To;
	double Length;
}All_Edges[1000];

int CMP(const void *a, const void *b) {
	Edge *A = (Edge*)a;
	Edge *B = (Edge*)b;
	return A->Length - B->Length;
}

double cal(int *stone[], int l) {//prim
	int countE=0;
	for (int i = 0; i < l-1; i++) {//from ith stone
		for (int j = i+1; j < l; j++) {//to jth stone
			//establish edge
			Edge e ;
			e.From = i;
			e.To = j;
			int dx = stone[i][0] - stone[j][0];
			int dy = stone[i][1] - stone[j][1];
			e.Length = sqrt( dx*dx+dy*dy);
			All_Edges[countE] = e;
			countE++;
		}
	}
	qsort(All_Edges, (countE+1), sizeof(Edge), CMP);
	for (int i = 0; i < countE; i++) {
		cout << All_Edges[i].Length<<endl;
	}
	return max(All_Edges[0].Length, All_Edges[countE].Length);
	/*return 0;*/
}
int main() {
	queue<double> c;
	int sNum;
	cin >> sNum;
	while (!cin.eof() && sNum != 0) {
		int **stone = new int*[sNum];// store location of x y;
		for (int i = 0; i < sNum; i++) {
			stone[i] = new int[2];
		}
		for (int i = 0; i < sNum; i++) {
			cin >> stone[i][0] >> stone[i][1];
		}
		c.push(cal(stone,sNum));
		cin >> sNum;
	}
	int count = 1;
	while (!c.empty()) {
		cout << "Scenario #" << count << endl;
		count++;
		cout << "Frog Dsitance = " << setprecision(3) << c.front() << endl;
		c.pop();
	}

	return 0;

}
