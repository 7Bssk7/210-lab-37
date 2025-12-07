#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string&);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    // int grand_sum  = 0;
    string input;
    fstream in_File("lab-37-data-3.txt");
    map<int, list<int>> hash_table;

    if(!in_File){
        cout << "Failed to open then file!" << endl;
        return 1;
    }

    /*
    while(getline(in_File, input)){
        grand_sum += sum_ascii(input);
    }

    cout << "Grand total: " << grand_sum << endl;

    vector<string> test {"536B9DFC93AF", "1DA9D64D02A0", "666D109AA22E", "E1D2665B21EA"};
    for (int i = 0; i < test.size(); ++i){
        cout << "Sum : " << sum_ascii(test.at(i)) << endl;
    }
    */    

    

    return 0;
}


int gen_hash_index(const string & s){
    int sum = 0;

    for(int i = 0; i < s.size(); ++i){
        sum += s.at(i);
    }

    return sum;

}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
