#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Constant for modulus used in hash function
const int N = 141;

// Function prototype of the function that generates a hash index for a given string
int gen_hash_index(const string&);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    // *** TEST ***
    // int grand_sum  = 0;

    string input;
    fstream in_File("lab-37-data-3.txt");
    map<int, list<string>> hash_table;

    if(!in_File){
        cout << "Failed to open then file!" << endl;
        return 1;
    }


    while(getline(in_File, input)){

        int index = gen_hash_index(input);

        hash_table[index].push_back(input);
                                                                                                                                                      
    }

    int count = 0;
    for(map<int, list<string>>::iterator it = hash_table.begin(); (it != hash_table.end()) && ( count <= 100) ; ++it, ++count){

        cout << "\n -> Index #" << it->first << " :" << endl;

        int shown = 0;
        for( auto code = it->second.begin(); (code != it->second.end()) && (shown <= 5); ++code, ++shown){
            cout << *code << " ";
        }

        cout << endl;

    }


    // *** TEST ***
    /*
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

    return sum % N;

}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
