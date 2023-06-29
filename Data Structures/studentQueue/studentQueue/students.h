#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>

using namespace std;

class students
{
public:
    void setName(string);
    void setId(int);
    string getName();
    int getId();

private:
    string studentNames;
    int studentIDS;
};

#endif // STUDENTS_H
