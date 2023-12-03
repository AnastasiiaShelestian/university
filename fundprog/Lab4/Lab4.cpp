#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> inputVector, int** matrix, int n) {
	vector<int> resultVector;

	for (int i = 0; i < inputVector.size(); i++) {
		resultVector.push_back(0);

		for (int j = 0; j < n; j++) {
			resultVector[i] += inputVector[i] * matrix[i][j];
		}
	}

	return resultVector;
};

vector<int> inputVector(int m) {
	vector<int> temp;

	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		temp.push_back(num);
	}

	return temp;
};

void printIntVector(vector<int> inputVector) {
	for (int i : inputVector) {
		cout << i << " ";
	}
};

int** initializeMatrix(int m, int n) {
	int** matrix = new int* [m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	return matrix;
};

int** inputMatrix(int m, int n) {
	int** matrix = initializeMatrix(m, n);

	cout << endl << "Enter the elements for myMatrix: " << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}

	return matrix;
}

void printMatrix(int** matrix, int m, int n) {
	cout << "Matrix: " << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int m, n;
	vector <int> myVector;
	vector <int> resVector;
	int** myMatrix;

	cout << "Enter the number of elements m and n: " << endl;
	cin >> m >> n;

	cout << "Enter the elements for myVector: " << endl;
	myVector = inputVector(m);

	cout << "Entered numbers: " << endl;
	printIntVector(myVector);

	myMatrix = inputMatrix(m, n);
	printMatrix(myMatrix, m, n);

	resVector = multiply(myVector, myMatrix, n);

	cout << "Result myVector * myMatrix: " << endl;
	printIntVector(resVector);

	return 0;
}

