#include <iostream>
#include <string>
using namespace std;

string compress(string s){
	string c;
	int count = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		count++;

		if (i+1 == s.length() || s[i] != s[i+1])
		{
			c.append(s, i, 1);
			c.append(to_string(count));
			count = 0;
		}
	}
	return ((s.length() < c.length())? s : c);
}

int main(){
	string input;
	cin >> input;
	cout << compress(input) << '\n';
	return 0;
}