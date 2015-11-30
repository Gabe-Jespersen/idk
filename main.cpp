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
#include "cycle.h"

using namespace std;

int main(int argc, char** argv)
{
    vector<int> stats;
    int level, charClass, tempInt;
    string temp;

    charClass = classSelect();
    stats = statMaker(charClass);

    /*
    for(int i = 0; i < stats.size(); i++)
    {
        cout << stats.at(i) << endl;
    }
    */

    vector<int> gameInfo = {stats.at(0),stats.at(1),stats.at(2),stats.at(3),stats.at(4),
                            charClass, 1, 0, 1, 0};
    //hp,atk,def,magatk,magdef,class,level,exp,alive,coins


    while(gameInfo.at(8))
    {
        gameInfo = cycle(gameInfo);
    }

    return 0;
}
