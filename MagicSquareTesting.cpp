
//Author: Emily Wolf
//Date: 11/3/14
//To see if a matrix is a "magic square"  (up to size 5x5) (https://en.wikipedia.org/wiki/Magic_square)

#include <iostream>
using namespace std;

	int main(){
	int n, sumR, sumC, sumD;
	int square[5][5];
	int sumRow [5] = {0};
	int sumColumn [5] = {0};
	int sumD1 = 0, sumD2 = 0;
	int a[25];
	bool good = true;
	int e = 0;
	cout << "What is order of your matrix ";
	cout << "(must be less than 5)?" << endl;
	cin >> n;
	
//declares order
	square[n][n];
	a[n*n];
	
//enters values into matrix
	cout << "Please enter in the values for ";
	cout << "your matrix, with respect to rows." << endl;
	for (int i = 0; i <n; i++) {
		for (int j = 0; j<n; j++) { 
			cin >> square[i][j];  } }
			
//turns matrix into array for eastier comparing
	for (int i=0; i <n; i++) {
		for (int j = 0; j < n; j++) {
			a[e] = square[j][i];
			e++;					} }

//sorts the array with bubble sort.
	for (int i = n*n; i > 0; --i) {
		for (int j = 0; j < i - 1; ++j) {
			if (a[j] > a[j+1]) {
				int t  = a[j];
				a[j] = a[j+1];
				a[j+1] = t;   }}}
				
//checks for every value, and assigns false if absent
	for (int i =0; i<n*n; i++) {
		if (a[i] != i+1) {
			cout << "*This matrix doesn\'t contain the number ";
			cout << i+1 << "."  << endl;
			good = false; } }

		if (good == true) {
			cout << "All numbers 1 to " << n*n << " are present."; 
			cout << endl;}
//finds and prints sums of rows
	for (int i=0; i <n; i++){
		for (int j = 0; j<n; j++) {
			sumRow[i] += square[i][j]; }	
			cout << "Row "<< i << " sum: " << sumRow[i] << endl;	}
			
//same as above, but with columns	
	for (int i=0; i <n; i++){
		for (int j = 0; j<n; j++) {
			sumColumn[i] += square[j][i]; }	
			cout << "Column "<< i << " sum: " << sumColumn[i] << endl;	}

//adds diagonals (note: I did my diagonals in a different order)
	for (int i=0; i<n; i++) {
		sumD1 += square[i][n-1-i]; }
		cout << "Diagonal #1 Sum: " << sumD1 << endl;

	for (int i=0; i<n;i++) {
		sumD2 += square[i][i]; }
		cout << "Diagonal #2 Sum: " << sumD2 << endl;
	
//mass compare of sums, columns, and diagonals
	sumR = sumRow[0]; 		
	sumC = sumColumn[0]; 
	for (int i = 0; i <n; i++) {
		if (sumR != sumRow[i]) {
			cout << "*The sum of Row " << i << " doesn't ";	
			cout << "match the sums of the other rows." << endl;
			good = false; }
			
		if (sumC != sumColumn[i]) {
			cout << "*The sum of Column " << i << " doesn't ";
			cout << "match the sums of the other columns." << endl;
			good = false; } }
	
	if (sumD1 != sumD2) {
		cout << "*The sums of the diagonals don't match.";
		cout << endl;
		good = false; }
	
//comparation between rows, columns and diagonals
	if (sumR != sumC || sumR != sumD1) {
		good = false; }
		
//prints out square, along with final diagnosis
	cout << "The square:" << endl;
		for (int i = 0; i <n; i++) {
			for (int j = 0; j<n; j++) { 
				cout << square[i][j] << " "; }
				cout << endl; }
				
	if (good == true) {
		cout << "is a magic square. Bye." << endl; }
	else {
		cout << "is not a magic square, due to the "; 
		cout << "reasons marked by asterisks. Whoops." << endl; }
return 0; }
