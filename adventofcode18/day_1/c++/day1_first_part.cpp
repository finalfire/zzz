#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int sum = 0;
    string line;
    ifstream myfile ("../input2");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            // cout << line << '\n';
            sum += stoi(line);
        }

        myfile.close();
    }

    else 
        cout << "Unable to open file"; 

    cout<<"Result "<<sum<<endl;

    return 0;
}
