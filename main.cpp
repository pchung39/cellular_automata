#include <string>
#include <iostream>
#include "Automaton.h"

using namespace std;

// int main()
// {
//    int rule, k;

//    // get rule from user
//    do
//    {
//       cout << "Enter Rule (0 - 255): ";
//       cin >> rule;
//    } while (rule < 0 || rule > 255);

//    // create automaton with this rule and single central dot
//    Automaton 
//       aut(rule);

//    // now show it
//    cout << "   start"  << endl;
//    for (k = 0; k < 100; k++)
//    {

//       cout << aut.toStringCurrentGen() << endl;
//       aut.propagateNewGeneration();
//    }
//    cout << "   end"  << endl;
   
//    return 0;
// }


int main()
{
   int rule;

   // get rule from user
   do
   {
      cout << "Enter Rule (0 - 255): ";
      cin >> rule;
   } while (rule < 0 || rule > 255);

   // create automaton with this rule and single central dot
   Automaton* aut = new Automaton(rule);
   aut->propagateNewGen();
   cout << "GEN: " << endl;
   cout << aut->toStringCurrentGen('o', '*') << endl;
   // now show it
   // cout << "   start"  << endl;
   // for (k = 0; k < 100; k++)
   // {

   //    cout << aut.toStringCurrentGen() << endl;
   //    aut.propagateNewGeneration();
   // }
   // cout << "   end"  << endl;
   
   return 0;
}

