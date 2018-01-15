//this program checks if one string is rotation of the other or not
/*
main concept:
let string be s1 : waterbottle
its rotaton be s2: terbottlewa
now the point is, the main string has been in two parts
x = wa
y = terbottle
i.e. s1 = xy
the rotated string s2 = yx, will surely be a substring of xyxy = s1+s1
just check if the it is a substring of self concatenated string s1
*/

#include <iostream>
#include <string>

using namespace std;

bool isRotation(string str, string str2){
    if((str.size() == str2.size()) && str.size()!=0 ){
        string t = str + str;
        size_t f = t.find(str2);
        if(f != string::npos)
            return true;
    }
    return false;
}

int main(){
    string s1, s2;
    cout << "enter first string:\n";
    getline(cin, s1);
    cout << "enter second string\n";
    getline(cin, s2);
    cout << (isRotation(s1,s2)? "true": "false");
    return 0;
}