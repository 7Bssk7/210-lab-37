// COMSC-210 | Lab 38 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Constant for modulus used in hash function
// CODE_SIZE - all codes are exactly 12 characters long
const int N = 141, CODE_SIZE = 12;

// Function prototypes
int gen_hash_index(const string&);
void search_key(const map<int, list<string>>& , const string&);
void add_key(map<int, list<string>>& , const string&);
void remove_key(map<int, list<string>>& , const string&);
void modify_key(map<int, list<string>>& , const string&);
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

    // Output menu and process user choices until exit
    menu();
    cin >> choice;
    while(choice != 6){
        // Handle invalid menu input
        if((choice < 1) || (choice > 6)){
            cout << "\nInvalid input, please enter your choice again!" << endl;
            menu();
            cin >> choice;
        }
        else{
            // Milestone 1: Print the first 100 entries of the hash table
            if(choice == 1){
                // Outputs the first 100 entries of the hash table
                int count = 0;
                for(map<int, list<string>>::iterator it = hash_table.begin(); (it != hash_table.end()) && ( count < 100) ; ++it, ++count){

                    cout << "\n -> Index #" << it->first << " :" << endl;

                    // Show up to 5 codes from each bucket for readability
                    int shown = 0;
                    for( auto code = it->second.begin(); (code != it->second.end()) && (shown < 5); ++code, ++shown){
                        cout << *code << " ";
                    }

                    cout << endl;
                }
            }
            // Milestone 2: Search for a code
            if(choice == 2){
                string e_key;
                cout << "\n *** SEARCH FOR A KEY *** " << endl;
                cout << "\nEnter your key: ";
                cin >> e_key;
                while( e_key.size() != CODE_SIZE ){
                    cout << "Invalid key size, please enter your key again!" << endl;
                    cout << "Enter your key: ";
                    cin >> e_key;
                }
                search_key(hash_table, e_key);

            }
            // Milestone 3: Add a code
            if(choice == 3){
                string a_key;
                cout << "\n *** ADD A KEY *** " << endl;
                cout << "\nEnter your key: ";
                cin >> a_key;
                while( a_key.size() != CODE_SIZE ){
                    cout << "Invalid key size, please enter your key again!" << endl;
                    cout << "Enter your key: ";
                    cin >> a_key;
                }
                add_key(hash_table, a_key);
                
            }
            // Milestone 4: Remove a code
            if(choice == 4){
                string r_key;
                cout << "\n *** REMOVE A KEY *** " << endl;
                cout << "\nEnter your key: ";
                cin >> r_key;
                while(r_key.size() != CODE_SIZE){
                    cout << "Invalid key size, please enter your key again!" << endl;
                    cout << "Enter your key: ";
                    cin >> r_key;
                }
                remove_key(hash_table, r_key);
                
            }
            // Milestone 5: Modify a code
            if(choice == 5){
                string m_key;
                cout << "\n *** MODIFY A KEY *** " << endl;
                cout << "\nEnter your key: ";
                cin >> m_key;
                while( m_key.size() != CODE_SIZE ){
                    cout << "Invalid key size, please enter your key again!" << endl;
                    cout << "Enter your key: ";
                    cin >> m_key;
                }
                modify_key(hash_table, m_key);
                
            }
        }
        // Output menu again after each operation
        menu();
        cin >> choice;
    }

    // Milestone 6: Exit program
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

// menu(): outputs the interactive menu options for the user
// argument: none
// return: none, outputs menu
void menu(){
    cout << "\n1. Print 100 entries" << endl;
    cout << "2. Search for a key" << endl;
    cout << "3. Add a key" << endl;
    cout << "4. Remove a key" << endl;
    cout << "5. Modify a key" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

// search_key(): searches for a given code in the hash table by computing its hash index and checking the bucket
// argument: const map<int, list<string>>& h_t (hash table), string code (the code to search)
// return: none, outputs whether the code was found and its index
void search_key(const map<int, list<string>>& h_t, const string& code){
    int index = gen_hash_index(code);
    auto it = h_t.find(index);

    if(it != h_t.end()){
        bool found = false;
        for( auto key = it->second.begin(); (key != it->second.end()) && (found == false); ++key){
            if(*key == code){
                found = true;
            }
        }

        if(found){
            cout << "+ Code " << code << " found at index " << index << endl;
        }
        else{
            cout << "x Code " << code << "  NOT found in hash table" << endl;
        }

    }
    else{
        cout <<  "Index " << index << " not found in hash table" << endl;
    }

}

// add_key(): adds a new code to the hash table if it does not already exist in the bucket
// argument: map<int, list<string>>& h_t (hash table), string code (the code to add)
// return: none, outputs confirmation or duplicate warning
void add_key(map<int, list<string>>& h_t, const string& code){
    int index = gen_hash_index(code);
    auto it = h_t.find(index);

    if(it != h_t.end()){
        bool found = false;
        for( auto key = it->second.begin(); (key != it->second.end()) && (found == false); ++key){
            if(*key == code){
                found = true;
            }
        }

        if(found){
            cout << "+ Same code: " << code << " was found at index " << index << endl;
        }
        else{
            h_t[index].push_back(code);
            cout << code << " was added to the bucket under index " << index << endl;
        }
    }
    else{
        h_t[index].push_back(code);
        cout << code << " was added to the bucket under index " << index << endl;
    }
}

// remove_key(): removes a code from the hash table if it exists in the correct bucket
// argument: map<int, list<string>>& h_t (hash table), string code (the code to remove)
// return: none, outputs confirmation or not found message
void remove_key(map<int, list<string>>& h_t, const string& code){
    int index = gen_hash_index(code);
    auto it = h_t.find(index);

    if(it != h_t.end()){
        bool found = false;
        for( auto key = it->second.begin(); (key != it->second.end()) && (found == false); ++key){
            if(*key == code){
                found = true;
                cout << "Code: " << code << " was found at index " << index << endl;
                it->second.erase(key);
                cout << "Code: " << code << " was removed from the hash table" << endl;
            }
        }
        if(!found){
            cout << "x Code " << code << " NOT found in hash table" << endl;
        }

    }
    else{
        cout <<  "Index " << index << " not found in hash table" << endl;
    }

}

// modify_key(): replaces an existing code with a new one by removing the old code and inserting the new code
// argument: map<int, list<string>>& h_t (hash table), string code (the code to modify)
// return: none, inserts for new code, outputs confirmation or not found message
void modify_key(map<int, list<string>>& h_t, const string& code){
    int index = gen_hash_index(code);
    auto it = h_t.find(index);
    string new_code;

    if(it != h_t.end()){
        bool found = false;
        for( auto key = it->second.begin(); (key != it->second.end()) && (found == false); ++key){
            if(*key == code){
                found = true;
                cout << "Code " << code << " was found at index " << index << endl;
                cout << "Enter the code you would like to replace the old code with: ";
                cin >> new_code;
                while((new_code.size() != CODE_SIZE)){
                    cout << "Invalid key size, please enter your key again!" << endl;
                    cout << "Enter your key: ";
                    cin >> new_code;
                }
                cout << "Old code " << code << " removed from bucket under index " << index << endl;
                it->second.erase(key);
                int new_index = gen_hash_index(new_code);
                h_t[new_index].push_back(new_code);
                cout << "New code " << new_code << " was added to the bucket under index " << new_index << endl;
            }
        }
        if(!found){
            cout << "x Code " << code << " NOT found" << endl;
        }

    }
    else{
        cout <<  "Index " << index << " not found in hash table" << endl;
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
