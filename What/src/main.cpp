#include <iostream>
#include "FileManager.h"
#include "Timer.h"

using namespace std;

int main()
{
    char search[25];
    Filemanager manager;
    Timer counter;

    cout << "Welcome\n";
    int op = 0;

    do
    {

        cout << "~ ~ ~ M E N U ~ ~ ~ \n";
        cout << "1. Add entry \n";
        cout << "2. Search Binary \n";
        cout << "3. Search secuential\n";
        cout << "4. Exit\n";
        cin >> op;
        switch (op)
        {
        case 1:
            manager.AddEntry();
            break;
        case 2:
            cout << "Searching name: \n";
            cin >> search;
            counter.start();
            manager.searchnameB(search, 0, 20999);
            counter.stop();
            cout << "Seconds: " << counter.elapsedSeconds() << std::endl;
            break;
        case 3:
            cout << "Searching name: \n";
            cin >> search;
            counter.start();
            manager.searchnameS(search);
            counter.stop();
            cout << "Seconds: " << counter.elapsedSeconds() << endl;
            break;
        case 4:
            op = 4;
            break;

        default:
            cout << "Invalid option \n";
            break;
        }
    } while (op != 4);
}