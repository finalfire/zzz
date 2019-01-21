#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> frequencies;
    vector<int> frequencies_calculate;

    string line;
    ifstream myfile ("../input2");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
           frequencies.push_back(stoi(line));
        }

        myfile.close();
    }
    else 
        cout << "Unable to open file";

    int current_frequency = 0;
    while (true) {
        bool found_twice = false;
        for (int j = 0; j < frequencies.size(); j++) {
            current_frequency = current_frequency + frequencies[j];
            
            for (int i = 0; i < frequencies_calculate.size(); i++) {
                if (frequencies_calculate[i] == current_frequency) {
                    cout<<"Result "<<frequencies_calculate[i]<<endl;
                    found_twice = true;
                    break;
                }

            }
            if (found_twice)
                break;
            frequencies_calculate.push_back(current_frequency);
        }
        if (found_twice)
            break;
    }

    return 0;
}
