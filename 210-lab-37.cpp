#include <iostream>
#include <string>
using namespace std;

int sum_ascii(const string&);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string test = "ABC"; 
    int test_r;

    test_r = sum_ascii(test);

    cout << "Sum : " << test_r << endl;
    

    return 0;
}


int sum_ascii(const string & s){
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
