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
   int rule, k;

   // get rule from user
   do
   {
      cout << "Enter Rule (0 - 255): ";
      cin >> rule;
   } while (rule < 0 || rule > 255);

   // create automaton with this rule and single central dot
   Automaton* aut = new Automaton(rule);
   // cout << aut->toStringCurrentGen('o', '*') << endl;
   // aut->propagateNewGen();
   // cout << aut->toStringCurrentGen('o', '*') << endl;
   //cout << "GEN: " << endl;

   // now show it
   // cout << "   start"  << endl;
   for (k = 0; k < 25; k++)
   {
      cout << aut->toStringCurrentGen('.', '*') << endl;
      aut->propagateNewGen();
   }
   // cout << "   end"  << endl;
   // aut->setDisplayWidth(150);
   // for (k = 0; k < 10; k++)
   // {
   //    cout << aut->toStringCurrentGen('o', '*') << endl;
   //    aut->propagateNewGen();
   // }
   // return 0;

   // ooxoo

   // 0-2 -> oox
   // 1-3 -> oxo
   // 2-4 -> xoo
}


// ooooooooooooooooooooooooooooooooooooooo*ooooooooooooooooooooooooooooooooooooooo
// oooooooooooooooooooooooooooooooooooooo***oooooooooooooooooooooooooooooooooooooo
// ooooooooooooooooooooooooooooooooooooo**oo*ooooooooooooooooooooooooooooooooooooo
// oooooooooooooooooooooooooooooooooooo**o****oooooooooooooooooooooooooooooooooooo
// ooooooooooooooooooooooooooooooooooo**oo*ooo*ooooooooooooooooooooooooooooooooooo