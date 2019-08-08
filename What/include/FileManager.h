#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <string.h>
#include <fstream>
#include "Struct.h"

using namespace std;

class Filemanager
{
public:
    Filemanager();

    void AddEntry();
    void searchnameS(char*);
    void searchnameB(char*, int, int);
    archive readfile(int);

private:
    string filename = "items.dat";

};

#endif