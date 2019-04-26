#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
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

    int backwards = 7

    string binary = bitset<8>(rule).to_string();
    int n = binary.length(); 
    char char_array[n + 1]; 
    strcpy(char_array, binary.c_str()); 


    for (int i=0; char_array[i] != 0; ++i) {
        
        if (char_array[i] == 0) {
            rules[backwards] = false;
        }
        else {
            rules[backwards] = true;
        }

        backwards -= 1;

    }

    // TODO: remove this, just for debugging 
    for (int j=0; j < this->rules.size(); ++j) {
        cout << "RULE POSITION: " << j + 1 << " " << this->rules.at(j) << endl;
    }

    return true;
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