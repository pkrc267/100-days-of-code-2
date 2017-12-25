#include <iostream>
#include <cstring>
using namespace std;

char* replaceSpaces(char str[], int truelength) {
  int spaces = 0;
  for(int i = 0; i < truelength; i++)
	if(str[i]==' ')
		spaces++;

  int index = truelength + spaces*2;
  
  if(truelength < strlen(str))
	str[truelength]='\0';
  
  for(int i = truelength -1; i >= 0; i--)
  {
	if(str[i]==' '){
		str[index-1] = '0';
		str[index-2] = '2';
		str[index-3] = '%';
		index-= 3;
	}
	else{
		str[index -1] = str[i];
		index--;
	}
  }
return str;
}

int main()
{
	char input[100]; int length;
	char* s;
	cout<< "enter the string:\n";
	fgets(input, 100, stdin);
	cout << "enter the true length:\n";
	cin >> length;
	s = replaceSpaces(input, length);
	puts(s);
	return 0;
}
