#include <stdio.h>
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <vector>
#include "Automaton.h"

using namespace std; 


Automaton::Automaton(int rule) {

    // binary-ize rule set to rule vector 
    this->setRule(rule);

    // set displaywidth to 79
    this->displayWidth = DEFAULT_DISPLAY_WIDTH;

    // set extremebit 
    this->extremeBit = 0;

    // set thisGen to ooxoo
    this->thisGen.push_back(1);

    // set extremeBit to rule 000
    //this->extremeBit = this->rules[0];
    cout << "Extreme: " << this->extremeBit << endl;

    // at the end, pad with extreme bits 
    while (this->thisGen.size() <= this->displayWidth) {
        this->thisGen.insert(this->thisGen.begin(), this->extremeBit);
        this->thisGen.push_back(this->extremeBit);
    }

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
            rules[backwards] = false;
        }
        else {
            rules[backwards] = true;
        }

        backwards -= 1;

    }

    return true;
}

void Automaton::propagateNewGen() {


    vector<int> newGen;

    int end = 2;
    int start = 0;
    while (end <= this->thisGen.size() - 1) {
        string subGen;

        // get the triplet
        for (int i=start; i <= end; ++i) {
            //cout << this->thisGen.at(i) << endl;
            cout << "at i: " << this->thisGen.at(i) << endl;
            subGen += to_string(this->thisGen.at(i));
        }

        cout << "Start " << start << " , " << "End " << end << " " << "sub: " <<  subGen << endl;

        // evaluate new generation with subGen 
            if (subGen == "111") {
                newGen.push_back(this->rules[7]);
                break;
            }
            else if (subGen == "110") {
                newGen.push_back(this->rules[6]);
                break;
            }
            else if (subGen == "101") {
                newGen.push_back(this->rules[5]);
                break;
            }
            else if (subGen == "100") {
                newGen.push_back(this->rules[4]);
                break; 
            }
            else if (subGen == "011") {
                newGen.push_back(this->rules[3]);
                break;
            }
            else if (subGen == "010") {
                newGen.push_back(this->rules[2]);
                break;
            }
            else if (subGen == "001") {
                newGen.push_back(this->rules[1]);
                break;
            }
            else if (subGen == "000") {
                newGen.push_back(this->rules[0]);
                break;
            }


        start += 1;
        end += 1;

    }

    // set thisGen as newGen
    this->thisGen = newGen;

    // set extremeBit to rule 000
    this->extremeBit = this->rules[0];

    // at the end, pad with extreme bits 
    while (this->thisGen.size() <= this->displayWidth) {
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