#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int count_two = 0;
    int count_three = 0;

    string line;
    ifstream myfile ("../input2");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            // cout << line << '\n';
            bool counted_two = false;
            bool counted_three = false;
            for (int i = 0; i < line.length(); i++) {
                int count = 0;
                for (int j = 0; j < line.length(); j++) {
                    if (line[i] == line[j])
                        count++;
                }
                if (count == 2 && !counted_two) {
                    count_two++;
                    counted_two = true;
                }
                else if (count == 3 && !counted_three) {
                    count_three++;
                    counted_three = true;
                }
            }
        }

        myfile.close();
    }

    else 
        cout << "Unable to open file"; 

    cout<<"Result "<<(count_two*count_three)<<endl;

    return 0;
}
