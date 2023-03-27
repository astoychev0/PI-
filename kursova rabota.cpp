#include <iostream>

using namespace std;
int main()
{
	int N;
	cout << "Aleksandar Aleksandrov Stoychev 361222011 grupa 20a\n";
	cout << "Da se systavi programa za obrabotka na masiva A[N,N], kadeto dannite sa celi chisla v intervala [-1000;1000]. Programata da izvyrshi slednite deistviq:\n";
	cout << "-otpechatvane na uslovieto na zadachata;\n";
	cout << "-otpechatvane na imenata na avtora na programata;\n:";
	cout << "-vavejdane na vhodnite danni;\n";
	cout << "-otpechatvane na vhodnite danni;\n";
	cout << "a) da se obrazuva ednomeren masiv C elementite, koito sa elementite ot masiva A popadashti v daden interval [K-L]  ;\n";
	cout << "b) polucheniqt masiv da se sortira po golemina;\n";
	cout << "-otpechatvane na poluchenite rezultati sled obrabotka a) i sled obrabotka b)\n";
	cin >> N;
	// read array
	int** A = new int* [N];
	for (int row = 0; row < N; row++) {
		A[row] = new int[N];
		for (int col = 0; col < N; col++) {
			cout << "A[" << row << "][" << col << "]\n";
			cin >> A[row][col];
		}
	}

	//print array
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << A[row][col] << " ";
			if (col == N - 1) { cout << "\n"; }
		}
	}

	//a)
	int K, L;
	cin >> K;
	cin >> L;
	int count = 0;
	// count the size of the array
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] >= K && A[i][j] <= L) {
				count++;
			}
		}
	}
	// add the numbers to the array
	int* C = new int[count];
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] >= K && A[i][j] <= L) {
				C[index] = A[i][j];
				index++;
			}
		}
	}
	//á)
	// Buble Sort
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (C[j] > C[j + 1]) {
				int temp = C[j];
				C[j] = C[j + 1];
				C[j + 1] = temp;
			}
		}
	}
	// print result
	cout << "C[" << count << "] = { ";
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1) {
			cout << C[i] << " }\n";
		}
		else {
			cout << C[i] << ", ";
		}
	}
	// delete the arrays
	delete[] C;
	for (int i = 0; i < N; i++) {
		delete[] A[i];
	}
	delete[] A;
	return 0;
}