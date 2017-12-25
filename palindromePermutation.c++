#include <iostream>
#include <string>
using namespace std;

bool checkSingleOdd(int b){
	return ((b & (b-1)) == 0);
}

int toggleBit(char c, int bv){
	int mask = 1 << (c-'a');

	if((bv & mask) == 0){
		bv |= mask;
	}
	else{
		bv &= (~mask);
	}
	return bv;
}

int createBitVector(string s){
	int bv = 0;

	for(char c: s){
		bv = toggleBit(c, bv);
	}
	return bv;
}

bool isPalindrome(string phrase){
	int bitvector = createBitVector(phrase);
	return bitvector == 0 || checkSingleOdd(bitvector);
}

int main(){
	string phrase;
	getline(cin, phrase);
	cout << (isPalindrome(phrase)? "true" : "false")<<'\n';
	return 0;
}