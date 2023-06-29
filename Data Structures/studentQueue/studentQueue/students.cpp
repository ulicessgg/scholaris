#include <iostream>
#include <iomanip>
#include <string>
#include "students.h"

using namespace std;

void students::setName(string name)
{
    studentNames = name;
}
void students::setId(int iD)
{
    studentIDS = iD;
}
string students::getName()
{
    return studentNames;
}
int students::getId()
{
    return studentIDS;
}
