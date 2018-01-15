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