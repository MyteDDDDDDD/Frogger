#include <iostream>
#include <queue>
#include <iomanip> 
#include <stdlib.h>
#include <cmath>

using namespace std;

struct Edge {
	int From, To;
	double Length;
}All_Edges[20000];

int CMP(const void *a, const void *b) {
	Edge *A = (Edge*)a;
	Edge *B = (Edge*)b;
	if (A->Length > B->Length)
		return 1;
	else if (A->Length == B->Length)
		return 0;
	else
		return -1;
}

int Find(int element, int A[]) {
	if (A[element] < 0)
		return element;
	else
		return Find(A[element], A);
}

void UnionSet(int set1, int set2, int A[]) {
	A[set1] += A[set2]; // A[ root of set is negative, and its
	A[set2] = set1;     // magnitude is the num of members
}

void Union(int element1, int element2, int A[]) {
	int root1 = Find(element1, A);
	int root2 = Find(element2, A);
	if (A[root1] < A[root2]) //root1 has more member		
		UnionSet(root1, root2, A);
	else
		UnionSet(root2, root1, A);
}

bool ifContain(int a, int b, int A[]) {
	int fa = Find(a, A);
	int fb = Find(b, A);
	if (fa == a || fb == b)
		return false;
	else if (fa == fb)
		return true;
	else
		return false;
}


double cal(int *stone[], int l) {//prim
	int countE = 0;
	for (int i = 0; i < l - 1; i++) {//from ith stone
		for (int j = i + 1; j < l; j++) {//to jth stone
										 //establish edge
			Edge e;
			e.From = i;
			e.To = j;
			int dx = stone[i][0] - stone[j][0];
			int dy = stone[i][1] - stone[j][1];
			e.Length = sqrt(dx*dx + dy*dy);
			All_Edges[countE] = e;
			countE++;
		}
	}

	qsort(All_Edges, countE, sizeof(Edge), CMP);

	double d = 0;
	int *nStone = new int[l];
	for (int i = 0; i < l; i++) {
		nStone[i] = -1;
	}
	for (int i = 0; i < countE ; i++) {

		if (ifContain(0, 1, nStone) == false) {
			int from = All_Edges[i].From;
			int to = All_Edges[i].To;
			if (ifContain(from, to, nStone) == false) {
				Union(All_Edges[i].From, All_Edges[i].To, nStone);
				d = All_Edges[i].Length;
			}
			else
				continue;
			
			
		}
		else if(ifContain(0, 1, nStone) == true)
			break;

	}

	return d;
}
int main() {
	queue<double> c;
	int sNum;
	cin >> sNum;
	while (!cin.eof() && sNum != 0) {
		int **stone = new int*[sNum + 1];// store location of x y;
		for (int i = 0; i < sNum; i++) {
			stone[i] = new int[2];
		}
		for (int i = 0; i < sNum; i++) {
			cin >> stone[i][0] >> stone[i][1];
		}
		c.push(cal(stone, sNum));
		cin >> sNum;
	}
	int count = 1;
	while (!c.empty()) {
		cout << "Scenario #" << count << endl;
		count++;
		cout.setf(ios::fixed);
		cout << "Frog Dsitance = " << setprecision(3) << c.front() << endl;
		cout << endl;
		c.pop();
	}

	return 0;

}
