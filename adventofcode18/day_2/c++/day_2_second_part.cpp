#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void get_input(vector<string>&lines) {
    string line;
    ifstream myfile ("../input2");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            // cout << line << '\n';
            lines.push_back(line);

        }
        myfile.close();
    }
    else 
        cout << "Unable to open file"; 
}

int main(int argc, char const *argv[])
{
    string line_result = "";
    vector<string> lines;

    get_input(lines);

    for (int i = 0; i < lines.size(); i++) {
        bool found = false;
        for (int j = 0; j < lines.size(); j++) {
            int count = 0;
            line_result = "";

            for (int z = 0; z < lines[i].length(); z++) {
                if (lines[i][z] == lines[j][z]) {
                    count++;
                    line_result += lines[i][z];
                }
            }
            if (lines[i].length() - count == 1) {
                cout<<"LINE 1 "<<lines[i]<<" LINE 2 "<<lines[j]<<endl;
                cout<<"Result "<<line_result<<endl;
                break;
            }
        }
        if (found)
            break;
    }


    // cout<<"Result "<<line_result<<endl;

    return 0;
}
