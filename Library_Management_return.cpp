/*
nithya-menu card for main,librarian,reader and writing files concept,login
tarun-writing functions for displayBooks, addbooks
gitish-writin functions for deletebooks, searchbooks
sneha-writing functions for addreaders, checking
yashwanth-writing functions for readerSearchbooks, structure
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include "library.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
int main()
{
    //color id
    // A for background color and c for text color
   system("Color 0F");
    int option;
    Library l;
    do
    {
        cout<<"===================================="<<endl;
        cout<<"Hello, Welcome to the Library."<<endl;
        cout<<"================USER================"<<endl;
        cout<<"\t   1. Librarian"<<endl;
        cout<<"\t   2. Reader"<<endl;
        cout<<"\t   3. Exit"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Please select one option from above: ";
        cin>>option;
        cout<<"===================================="<<endl;
        switch(option)
        {
        case 1:
            l.librarian();
            break;
        case 2:
            l.reader();
            break;
        case 3:
            break;
        default:
            cout<<"Enter valid option"<<endl;
        }
    }while(option!=3);
}

