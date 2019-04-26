#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <vector>
#include "Automaton.h"

using namespace std; 


Automaton::Automaton(int rule) {
    // set thisGen to ooxoo
    this->thisGen.push_back(0);
    this->thisGen.push_back(0);
    this->thisGen.push_back(1);
    this->thisGen.push_back(0);
    this->thisGen.push_back(0);

    // binary-ize rule set to rule vector 
    this->setRule(rule);

    // set displaywidth to 79
    this->displayWidth = DEFAULT_DISPLAY_WIDTH;

    // set extremebit 
    this->extremeBit = 0;
}

bool Automaton::setDisplayWidth(int width) {
    
    // if rule is divisible by 2 % then return false 
    if (width > MAX_DISPLAY_WIDTH) {
        return false;
    }
    else if ( width % 2 == 0) {
        return false;
    }
    // if rule is larger than max width false 
    else {
        this->displayWidth = width;
        return true;
    }
}

bool Automaton::setRule(int rule) {

    int backwards = 7;

    string binary = bitset<8>(rule).to_string();
    int n = binary.length(); 
    char char_array[n + 1]; 
    strcpy(char_array, binary.c_str()); 


    for (int i=0; char_array[i] != 0; ++i) {
        if (char_array[i] == '0') {
            cout << "char was 0" << endl;
            rules[backwards] = false;
        }
        else {
            cout << "char was 1" << endl;
            rules[backwards] = true;
        }

        backwards -= 1;

    }

    // // TODO: remove this, just for debugging 
    // for (int j=0; j < 8; ++j) {
    //     cout << "RULE BOOL " << j + 1 << " " << this->rules[j] << endl;
    // }

    return true;
}

void Automaton::propagateNewGen() {

    //char char_array[];

    // fill in thisGen with extreme bits until reached displayWidth

    while (this->thisGen.size() <= 79) {
        this->thisGen.insert(this->thisGen.begin(), this->extremeBit);
        this->thisGen.push_back(this->extremeBit);
    }


}


string Automaton::toStringCurrentGen(char charFor0, char charFor1) const {
    
    string response;

    for (int i=0; i < this->thisGen.size(); ++i) {
        if (this->thisGen.at(i) == 0) {
            response += charFor0;
        }
        else {
            response += charFor1;
        }
    }

    cout << "HERE'S YOUR GEN:" << endl;
    cout << response << endl;

    return response;
}

void Automaton::resetToFirstGen() {

    // clear whatever is inside thisGen
    this->thisGen.clear();

    // propagate thisGen with initial seed
    this->thisGen.push_back(0);
    this->thisGen.push_back(0);
    this->thisGen.push_back(1);
    this->thisGen.push_back(0);
    this->thisGen.push_back(0);

}