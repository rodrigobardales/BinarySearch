#include "FileManager.h"

Filemanager::Filemanager() {}

void Filemanager::AddEntry()
{
    ofstream file(filename, ios::out | ios::app | ios::binary);

    if (!file)
    {
        cout << "Error with file \n";
        return;
    }

    archive new_archive;

    cout << "Insert code: \n";
    cin >> new_archive.code;
    cout << "Insert name: \n";
    cin >> new_archive.name;
    cout << "Insert last name: \n";
    cin >> new_archive.lastname;
    cout << "Insert city: \n";
    cin >> new_archive.city;

    file.seekp(0, ios::end);
    file.write(reinterpret_cast<const char *>(&new_archive), sizeof(archive));

    file.close();
}

void Filemanager::searchnameB(char *name, int l, int r)
{
    int mid = (l - r) / 2;

    if (strcmp(readfile(l).name, name) == 0)
    {
        cout << readfile(l).name << " " << readfile(l).lastname << " " << readfile(l).city << " " << endl;
    }else
    {
        searchnameB(name, l + 1, r -1);
    }
    
}

archive Filemanager::readfile(int at)
{
    int read_at = at * sizeof(archive);

    ifstream reading(filename, ios::in | ios::binary);

    if (!reading)
    {
        cout << "Error with file \n";
    }

    archive readingarchive;
    reading.seekg(read_at, ios::beg);
    reading.read(reinterpret_cast<char *>(&readingarchive), sizeof(archive));
    reading.close();
    return readingarchive;
}

void Filemanager::searchnameS(char *name)
{
    ifstream archivedat(filename, ios::in | ios::binary);

    if (!archivedat)
    {
        cout << "Error with file \n";
        return;
    }

    archive reading;

    archivedat.seekg(0, ios::beg);
    archivedat.read(reinterpret_cast<char *>(&reading), sizeof(archive));

    while (!archivedat.eof())
    {
        if (strcmp(reading.name, name) == 0)
        {
            archivedat.close();
            cout << "Name: " << reading.name << " " << reading.lastname << " from: " << reading.city << endl;
            return;
        }
        archivedat.read(reinterpret_cast<char *>(&reading), sizeof(archive));
    }
    cout << "Entry not found \n";
    archivedat.close();
}