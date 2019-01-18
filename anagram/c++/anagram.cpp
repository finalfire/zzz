#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2);

int main(int argc, char const *argv[])
{
    string s1("pippo");
    string s2("pppio");
    if (argv[1] != NULL)
        s1 = argv[1];
    if (argv[2] != NULL)
        s2 = argv[2];

    if (isAnagram(s1,s2))
        cout<<"The two strings are anagram."<<endl;
    else
        cout<<"The two strings are NOT anagram."<<endl;
        
    return 0;
}

bool isAnagram(string s1, string s2) {
    bool verified[s2.length()] = {0};

    for (int i = 0; i < s1.length(); i++) {
        bool found = false;
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j] && verified[j] == 0) {
                found = true;
                verified[j] = 1;
                break;
            }
        }
        if (!found)
            return false;
    }

    return true;
}
