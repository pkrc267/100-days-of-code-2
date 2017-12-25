#include <iostream>
#include <string>

using namespace std;

bool oneEditAway(string,string);
bool oneReplaceAway(string,string);
bool oneInsertAway(string,string);

int main(){
	string input1, input2;
	getline(cin, input1);
	getline(cin, input2);
	cout << (oneEditAway(input1, input2)? "true\n":"false\n");
	return 0;
}

bool oneEditAway(string s1, string s2){
	if(s1.length() == s2.length()){
		return oneReplaceAway(s1,s2);
	}
	else if (s1.length() < s2.length())
	{
		return oneInsertAway(s1,s2);
	}
	else
		return oneInsertAway(s2, s1);

	return false;
}

bool oneReplaceAway(string s1, string s2){
	bool foundDifference = false;
	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i] != s2[i])
		{
			if(foundDifference)
				return false;	// for checking if the difference is found 2nd time
			foundDifference = true;
		}
	}
	return true;	//for ensuring a true return on zero-edits away strings
}

bool oneInsertAway(string ss, string ls){
	int index1=0, index2=0;

	while(index1 < ss.length() && index2 < ls.length()){
		if (ss[index1] != ls[index2])	// if characters are different
		{
			if (index1 != index2)	//if characters are different check indexes. When index are same, then goes for secone iteration; if chars are diff. again and this time indices are also different => 2 characters are different. hence not one edit away
				return false;
			index2++;
		}
		else{
			index1++;
			index2++;
		}
	}
	return true;
}