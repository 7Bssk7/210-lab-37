// COMSC-210 | Lab 37 | Arkhip Finski
// IDE used: Visual Studio
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
void search_key(const map<int, list<string>>& , const string&);
void menu();

int main() {
    // *** TEST ***
    /*
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    */

    // *** TEST ***
    // int grand_sum  = 0;

    // String to hold each line read from the file
    string input;
    // File with dataset containing 12-character codes
    fstream in_File("lab-37-data-3.txt");
    // (Map)Hash table: key is int hash index, value is list of codes mapping to that index
    map<int, list<string>> hash_table;

    // Check if file opened successfully
    if(!in_File){
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    // Read each code from the file, generates hash index, and insert into hash_table list
    while(getline(in_File, input)){

        // Generates index
        int index = gen_hash_index(input);
        // Insert into hash_table list
        hash_table[index].push_back(input);
                                                                                                                                                      
    }

    int choice;

    cout << "\n *** WELCOME *** " << endl;

    menu();
    cin >> choice;
    while(choice != 6){
        if((choice < 1) || (choice > 6)){
            cout << "\nInvalid input, please enter your choice again!" << endl;
            menu();
            cin >> choice;
        }
        else{
            if(choice == 1){
                // Outputs the first 100 entries of the hash table
                int count = 0;
                for(map<int, list<string>>::iterator it = hash_table.begin(); (it != hash_table.end()) && ( count <= 100) ; ++it, ++count){

                    cout << "\n -> Index #" << it->first << " :" << endl;

                    // Show up to 5 codes from each bucket for readability
                    int shown = 0;
                    for( auto code = it->second.begin(); (code != it->second.end()) && (shown <= 5); ++code, ++shown){
                        cout << *code << " ";
                    }

                    cout << endl;
                }
            }
            if(choice == 2){
                string e_key;
                cout << "\n *** SEARCH FOR A KEY *** " << endl;
                cout << "\nEnter your key: ";
                cin >> e_key;
                search_key(hash_table, e_key);
            }
            if(choice == 3){
                
            }
            if(choice == 4){
                
            }
            if(choice == 5){
                
            }
        }
        menu();
        cin >> choice;
    }

    cout << "Bye" << endl;




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

// gen_hash_index(): sums ASCII values of characters in the string, then reduces the sum modulo N(141) to get a hash index
// argument: string(code) read from the input file
// return: hash index for the hash_table
int gen_hash_index(const string & s){
    int sum = 0;

    for(int i = 0; i < s.size(); ++i){
        sum += s.at(i);
    }

    return sum % N;

}

void menu(){
    cout << "\n1. Print 100 entries" << endl;
    cout << "2. Search for a key" << endl;
    cout << "3. Add a key" << endl;
    cout << "4. Remove a key" << endl;
    cout << "5. Modify a key" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void search_key(const map<int, list<string>>& h_t, const string& code){
    int index = gen_hash_index(code);
    auto it = h_t.find(index);

    if(it != h_t.end()){

    }
    else{
        cout <<  "Index " << index << " not found in hash table." << endl;
    }

}

// *** TEST ***
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
