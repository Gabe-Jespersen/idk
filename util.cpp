/*
 * =====================================================================================
 *
 *       Filename:  util.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2015 12:00:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>

#include "util.h"

using namespace std;

int classSelect()
{
    int charClass, tempInt;
    string temp;

    cout << "Select your class\n" <<
          "\t1. Warrior\n" <<
          "\t2. Rogue\n" << 
          "\t3. Mage\n" <<
          "\t4. Priest\n";
    cin >> temp;

    stringstream convert(temp);
    if(!(convert >> tempInt))
    {
        tempInt = 0;
    }
    switch(tempInt)
    {
        case 1:
            charClass = 1;
            break;
        case 2:
            charClass = 2;
            break;
        case 3:
            charClass = 3;
            break;
        case 4:
            charClass = 4;
            break;
        default:
            cout << "Error\n";
            exit(1);
            break;
    }
}

vector<int> statMaker(int charClass)
{
    srand(time(NULL));

    vector<int> stats;
    switch(charClass)
    {
        case 1:
            stats = {10,8+(rand()%4),8+(rand()%4),5,5,7+(rand()%3)};
            return stats;
            break;
        case 2:
            stats = {6,7+(rand()%3),5,6,6,12+(rand()%5)};
            return stats;
            break;
        case 3:
            stats = {8,5,5,8+(rand()%4),7+(rand()%4),6+(rand()%2)};
            return stats;
            break;
        case 4:
            stats = {8,5,5,7+(rand()%4),8+(rand()%4),6+(rand()%2)};
            return stats;
            break;
        default:
            stats = {6,6,6,6,6,6};
            return stats;
            break;
    }
}

string whatClass(int classNumber)
{
    if(classNumber == 1)
    {
        return "Warrior";
    }
    else if(classNumber == 2)
    {
        return "Rogue";
    }
    else if(classNumber == 3)
    {
        return "Mage";
    }
    else
    {
        return "Priest";
    }
}

vector<int> levelCheck(int level, int experience)
{
    while(experience >= 5*level*(level+1))
    {
        level++;
        experience -= 5*level*(level+1);
    }
    if(experience < 0)
    {
        experience = 0;
    }
    vector<int> toReturn = {level,experience};
    return toReturn;
}
