#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(){
	
	int gamesize = 15;
	char simon[gamesize];
	char color[4] = {'R','Y','B','G'};
	char user[gamesize];
	string s;
	int turn = 1;
	bool lost = false;
	int w, r;
	//seeding
	srand(time(0));
	//assigning random values
	for (int q = 0; q < gamesize; q++) {	
		simon[q] = color[rand()%4];	}
	
	cout << "Welcome. Press enter to play Simon Says!" << endl;
	//waits for enter
	getline (cin, s, '\n');
	//outputs variables then replaces with . while incrementing turns
	while (!lost && turn <= gamesize) {
		cout << "\014" << "Simon Says:" << endl;
		
		for (int w = 0; w < turn; w++) {
			cout << simon[w] << flush;
			sleep(1);
			cout << "\010" << flush;
			cout << ".";
			r = w +1; }
		cout << endl;
		cout << "Please enter " << r << " characters to match: ";
		
	//for loop to get input and compare	
			for ( int w =0; w < turn; w++) {	 
				cin >> user[w];
				if (user[w] != simon[w]) {
				lost = true;	} } 
		turn++; }
		
	//outputs user's results
	if (lost == false) {
		cout << "Congratulations! You win!" << endl;
	}
	else
		cout << "You personify losing. The ";
		cout <<"correct sequence was: " << simon << endl;
	
	return 0;	}
