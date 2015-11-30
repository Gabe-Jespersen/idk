/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2015 11:43:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

#include "util.h"

using namespace std;

int main(int argc, char** argv)
{
    vector<int> stats;
    int level, charClass, tempInt;
    string temp;

    charClass = classSelect();
    stats = statMaker(charClass);
    for(int i = 0; i < stats.size(); i++)
    {
        cout << stats.at(i) << endl;
    }

    return 0;
}
