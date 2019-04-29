#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>
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
    // this->thisGen.insert(this->thisGen.begin(), 0);
    // this->thisGen.insert(this->thisGen.begin(), 0);
    // this->thisGen.push_back(0);  
    // this->thisGen.push_back(0);  
    // set extremeBit to rule 000
    //this->extremeBit = this->rules[0];
    //cout << "Extreme: " << this->extremeBit << endl;

}

bool Automaton::setDisplayWidth(int width) {
    
    // if rule is divisible by 2 % then return false 
    if (width < 1) {
        return false;
    }
    else if (width > MAX_DISPLAY_WIDTH) {
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

    if (rule < 0) {
        return false;
    }
    else if (rule > 255) {
        return false;
    }
    else {
        int backwards = 7;

        string binary = bitset<8>(rule).to_string();
        // cout << "BIN " << binary << endl;
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

}

void Automaton::propagateNewGen() {

    // pad four zeros on thisgen 
    this->thisGen.insert(this->thisGen.begin(), this->extremeBit);
    this->thisGen.insert(this->thisGen.begin(), this->extremeBit);
    this->thisGen.push_back(this->extremeBit);  
    this->thisGen.push_back(this->extremeBit);  

    // cout << "EVALUATING THIS GEN: " << endl;
    // for (int i=0; i< this->thisGen.size(); ++i) {
    //     cout << this->thisGen.at(i);
    // }

    // cout << endl;

    vector<int> newGen;
    
    int start = 0;
    int end = 2;

    while (end <= this->thisGen.size() - 1) {
        string subGen;

        // get the triplet
        for (int i=start; i <= end; ++i) {
            //cout << this->thisGen.at(i) << endl;
            subGen += to_string(this->thisGen.at(i));
        }

        //cout << "Start " << start << " , " << "End " << end << " " << "sub: " <<  subGen << endl;

        // evaluate new generation with subGen 
            if (subGen == "111") {
                // cout << "Matched: 111" << endl;
                // cout << "Added: rule[7]: " << this->rules[7] << endl;
                newGen.push_back(this->rules[7]);
            }
            else if (subGen == "110") {
                // cout << "Matched: 110" << endl;
                // cout << "Added: rule[6]: " << this->rules[6] << endl;
                newGen.push_back(this->rules[6]);
            }
            else if (subGen == "101") {
                // cout << "Matched: 101" << endl;
                // cout << "Added: rule[5]: " << this->rules[5] << endl;
                newGen.push_back(this->rules[5]);
            }
            else if (subGen == "100") {
                // cout << "Matched: 100" << endl;
                // cout << "Added: rule[4]: " << this->rules[4] << endl;
                newGen.push_back(this->rules[4]);
            }
            else if (subGen == "011") {
                // cout << "Matched: 011" << endl;
                // cout << "Added: rule[3]: " << this->rules[3] << endl;
                newGen.push_back(this->rules[3]);
            }
            else if (subGen == "010") {
                // cout << "Matched: 010" << endl;
                // cout << "Added: rule[2]: " << this->rules[2] << endl;
                newGen.push_back(this->rules[2]);
            }
            else if (subGen == "001") {
                // cout << "Matched: 001" << endl;
                // cout << "Added: rule[1]: " << this->rules[1] << endl;
                newGen.push_back(this->rules[1]);
            }
            else if (subGen == "000") {
                // cout << "Matched: 000" << endl;
                // cout << "Added: rule[0]: " << this->rules[0] << endl;
                newGen.push_back(this->rules[0]);
            }

        start += 1;
        end += 1;

    }

    // // DEBUG STATEMENT: see binary for new gen
    // cout << "NEW GEN: " << endl;
    // for (int k=0; k< newGen.size(); ++k) {
    //     cout << newGen.at(k);
    // }

    // cout << endl;

    // set thisGen as newGen
    this->thisGen = newGen;

    // set extremeBit to rule 000
    this->extremeBit = this->rules[0];

}


string Automaton::toStringCurrentGen(char charFor0, char charFor1) const {
    
    string response;
    string totalResponse;
    string leftTotalPad; 
    string rightTotalPad;
    int leftPad;
    int rightPad;    
    int totalPad;


    for (int i=0; i < this->thisGen.size(); ++i) {
        if (this->thisGen.at(i) == 0) {
            response += charFor0;
        }
        else {
            response += charFor1;
        }
    }

    // compute padding total
    if (this->thisGen.size() <= this->displayWidth) {
        totalPad = displayWidth - this->thisGen.size();
        //cout << "totalPad: " << totalPad << endl;
        leftPad = totalPad / 2;
        //cout << "LEFT: " << leftPad << endl;
        rightPad = totalPad / 2;
        //cout <<"RIGHT: " << rightPad << endl;

        // create leftPad
        for (int left=0; left < leftPad; ++left) {
            if (this->extremeBit == 0) {
                leftTotalPad += charFor0;
            }
            else {
                leftTotalPad += charFor1;
            }
        }

        // create rightPad
        for (int right=0; right< rightPad; ++right) {
            if (this->extremeBit == 0) {
                rightTotalPad += charFor0;
            }
            else {
                rightTotalPad += charFor1;
            }
        }

        totalResponse = leftTotalPad + response + rightTotalPad;
        return totalResponse;
    }
    else {
        //cout << "LARGE: " << response.length() << endl;
        while (response.length() > this->displayWidth) {
            response.erase(0,1);
            response.erase(response.length() - 1);
            //cout << "reduced: " << response.length() << endl;
        }


        return response;
    }
    // totalPad = displayWidth - this->thisGen.size();
    // //cout << "totalPad: " << totalPad << endl;
    // leftPad = totalPad / 2;
    // //cout << "LEFT: " << leftPad << endl;
    // rightPad = totalPad / 2;
    // //cout <<"RIGHT: " << rightPad << endl;

    // // create leftPad
    // for (int left=0; left < leftPad; ++left) {
    //     if (this->extremeBit == 0) {
    //         leftTotalPad += charFor0;
    //     }
    //     else {
    //         leftTotalPad += charFor1;
    //     }
    // }

    // // create rightPad
    // for (int right=0; right< rightPad; ++right) {
    //     if (this->extremeBit == 0) {
    //         rightTotalPad += charFor0;
    //     }
    //     else {
    //         rightTotalPad += charFor1;
    //     }
    // }

    // totalResponse = leftTotalPad + response + rightTotalPad;
    // return totalResponse;
}

void Automaton::resetToFirstGen() {

    // clear whatever is inside thisGen
    this->thisGen.clear();

    // propagate thisGen with initial seed
    // this->thisGen.push_back(0);
    // this->thisGen.push_back(0);
    this->thisGen.push_back(1);
    // this->thisGen.push_back(0);
    // this->thisGen.push_back(0);

    this->extremeBit = 0;

}