/*
nithya-menu card,clean up, update books,return books, logs, books borrowed list
tarun-writing functions for displayBooks, addbooks
gitish-writing functions for deletebooks, searchbooks
sneha-writing functions for addreaders, checking
yashwanth-writing functions for readerSearchbooks, librarian


===Reader===
1. Search Book
2. Display Books
3. Return Books
4. Exit
===Librarian===
1.  Add Books
2.  Delete Books
3.  Update Books
4.  Search Book
5.  Add Readers
6.  Add Librarians
7.  Display Books
8.  Display Borrowed List
9.  logs
10. cleanup
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::to_string;
using std::map;
using std::vector;
using std::stringstream;
//using std::push_back;
void displayBooks();
void addBooks();
void deleteBooks(string bookToDelete,int fault);
int checkingLibrarian(string UserId,string Password);
void searchBooks();
void addReaders();
void ViewList();
void cleanUp();
struct Books
{
    int BookId;
    string BookName;
    string PublisherName;
    string AuthorName;
    string purchasedDate;
    int noOfCopies;
    double Price;
    double Edition;
    string BookStatus;
    string BorrowedBy;

};
struct Reader
{
    string ReaderPassWord;
    string ReaderName;
    int ReaderAge;
    string ReaderMobileNumber;
    string ReaderEmailId;
    string ReaderAddress;
};
struct Librarian
{
    string LibrarianPassWord;
    string LibrarianName;
    int LibrarianAge;
    string LibrarianMobileNumber;
    string LibrarianEmailId;
    string LibrarianAddress;

};
int i=0;
int k=0;
int m=0;
struct Books b[100];
struct Reader r[100];
struct Librarian l[100];
map<string,vector<string>> BorrowedList;
void addLibrarians()
{
    int choise;
    ofstream write;
    write.open("LibrariansInfo1.txt",ios::out|ios::app);
    do{
    cin.ignore();
    cout<<"Enter Librarian Name: ";
    getline(cin,l[m].LibrarianName);
     cout<<"Enter Librarian Password: ";
    getline(cin,l[m].LibrarianPassWord);
    cout<<"Enter Librarian Age: ";
    cin>>l[m].LibrarianAge;
    cin.ignore();
    cout<<"Enter Librarian Mobile Number: ";
    getline(cin,l[m].LibrarianMobileNumber);
    cout<<"Enter Librarian Email Id: ";
    getline(cin,l[m].LibrarianEmailId);
    cout<<"Enter Librarian Address: ";
    getline(cin,l[m].LibrarianAddress);
    cout<<"Enter 1 to continue adding Librarians:";
    cin>>choise;
    write<<l[m].LibrarianEmailId<<"\n"<<l[m].LibrarianName<<"\n"<<l[m].LibrarianPassWord<<"\n"
    <<l[m].LibrarianAge<<"\n"<<l[m].LibrarianMobileNumber<<"\n"
    <<l[m].LibrarianAddress<<endl;
        ofstream logs;
        logs.open("booksLogs1.txt",ios::out|ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        logs << dt;
        logs<<"Librarian name: "<<l[m].LibrarianName<<" was added."<<endl;
        logs.close();
    m++;
    }while(choise==1);
    write.close();
}
void addReaders()
{
    int choise;
    ofstream write;
    write.open("ReadersInfo1.txt",ios::out|ios::app);
    do{
    cin.ignore();
    cout<<"Enter Reader Name: ";
    getline(cin,r[k].ReaderName);
     cout<<"Enter Reader Password: ";
    getline(cin,r[k].ReaderPassWord);
    cout<<"Enter Reader Age: ";
    cin>>r[k].ReaderAge;
    cin.ignore();
    cout<<"Enter Reader Mobile Number: ";
    getline(cin,r[k].ReaderMobileNumber);
    cout<<"Enter Reader Email Id: ";
    getline(cin,r[k].ReaderEmailId);
    cout<<"Enter Reader Address: ";
    getline(cin,r[k].ReaderAddress);
    cout<<"Enter 1 to continue adding Readers:";
    cin>>choise;
    write<<r[k].ReaderEmailId<<"\n"<<r[k].ReaderName<<"\n"<<r[k].ReaderPassWord<<"\n"
    <<r[k].ReaderAge<<"\n"<<r[k].ReaderMobileNumber<<"\n"
    <<r[k].ReaderAddress<<endl;
        ofstream logs;
        logs.open("booksLogs1.txt",ios::out|ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        logs << dt;
        logs<<"Reader Name: "<<r[k].ReaderName<<" was added."<<endl;

    k++;

    }while(choise==1);
    write.close();
}
void returnBooks()
{
    cin.ignore();
    string bookToReturn;
    cout<<"Enter Book Name to return: ";
    getline(cin,bookToReturn);
    int flag=0;
    string BookName1;
    string PublisherName1;
    string AuthorName1;
    string PurchasedDate1;
    string NoOfCopies1;
    string Price1;
    string Edition1;
    string BookStatus1;
    string BorrowedBy1;
    ifstream read;
    read.open("bookself1.txt",ios::in);
    string line;
    int count=0;
    while(getline(read,line))
    {
        if(line==bookToReturn || count>0)
        {
            flag=1;
            count++;
            switch(count)
            {
            case 1:
                cout<<"Book Name: ";
                BookName1=line;
                cout<<line<<endl;
                break;
            case 2:
                cout<<"Author Name: ";
                AuthorName1=line;
                cout<<line<<endl;
                break;
            case 3:
                cout<<"Purchased date: ";
                PurchasedDate1=line;
                cout<<line<<endl;
                break;
            case 4:
                cout<<"no of copies: ";
                NoOfCopies1=line;
                cout<<line<<endl;
                break;
            case 5:
                cout<<"Price: ";
                Price1=line;
                cout<<line<<endl;
                break;
            case 6:
                cout<<"Publisher Name: ";
                PublisherName1=line;
                cout<<line<<endl;
                break;
            case 7:
                cout<<"edition: ";
                Edition1=line;
                cout<<line<<endl;
                break;
            case 8:
                cout<<"Book status: ";
                BookStatus1=line;
                cout<<line<<endl;
                break;
            case 9:
                cout<<"Book Borrowed by: ";
                BorrowedBy1=line;
                cout<<line<<endl;
                string choise;
                cout<<"Do you want to return this Book ? (enter yes or no): "<<endl;
                cin>>choise;
                if(choise=="yes")
                {
                    ofstream logs;
                    logs.open("booksLogs1.txt",ios::out|ios::app);
                    time_t now = time(0);
                    char* dt = ctime(&now);
                    logs << dt;
                    logs<<"Book: "<<BookName1<<" returned by "<<BorrowedBy1<<endl;
                    logs.close();
                    stringstream ss;
                    ss<<NoOfCopies1;
                    int n;
                    ss>>n;
                    stringstream ss1;
                    n=n+1;
                    ss1<<n;
                    string m;
                    ss1>>m;
                   NoOfCopies1=m;
                   if(n>0)
                   {
                    BookStatus1="Available";
                   }
                    BorrowedBy1="Null";
                    cout<<"Congradulations !!! Book is Returned successfully, Thank you"<<endl;

                    ifstream read;
                    read.open("BorrowedList.txt",ios::in);
                    ofstream write1;
                    write1.open("tempBorrowedList.txt",ios::out);
                    string line,line1="Book : "+BookName1+" Name "+" : "+BorrowedBy1;
                    while(getline(read,line))
                    {
                        if(line==line1)
                        {
                            continue;
                        }
                        else
                        {
                            write1<<line<<endl;
                        }
                    }
                    read.close();
                    write1.close();
                    ifstream read1;
                    read1.open("tempBorrowedList.txt",ios::in);
                    ofstream write;
                    write.open("BorrowedList.txt",ios::out);
                    string line2;
                    while(getline(read,line2))
                    {
                        write<<line<<endl;
                    }
                }
                else
                {
                    cout<<"Thank you for visiting us!!!"<<endl;
                }
                break;
            }
        }

        if(count==9)
        {
            break;
        }
    }
    deleteBooks(bookToReturn,1);
    ofstream write;
    write.open("bookself1.txt",ios::out|ios::app);
    write<<BookName1<<"\n"<<AuthorName1<<"\n"<<PublisherName1<<"\n"<<NoOfCopies1<<"\n"<<Price1<<"\n"<<PublisherName1<<"\n"
    <<Edition1<<"\n"<<BookStatus1<<"\n"<<BorrowedBy1<<endl;
    read.close();
    if(flag==0)
    {
        cout<<"Book: "<<bookToReturn<<" could not be found"<<endl;
        displayBooks();
    }
}
void displayLogs()
{
    ifstream logs;
    logs.open("booksLogs1.txt",ios::in);
    string line;
    while(getline(logs,line))
    {
        cout<<line<<endl;
    }
    logs.close();
}
void addBooks()
{
    cin.ignore();
    ofstream write;
    write.open("bookself1.txt",ios::out|ios::app);
    int choise=0;
    do{

    b[i].BookId=i+1;
    b[i].BorrowedBy="Null";
    b[i].BookStatus="Available";
    int e=0;
    do{
    if(e>0)cout<<"This Book Field is Mandatory, you can't leave it as blank!!!"<<endl;
    cout<<"Enter Book Name: ";
    getline(cin,b[i].BookName);
    e++;
    //cout<<e<<endl;
    }while(b[i].BookName=="");
    e=0;
    do{
    if(e>0)cout<<"This Author Field is Mandatory, you can't leave it as blank!!!"<<endl;
    cout<<"Enter Author Name: ";
    getline(cin,b[i].AuthorName);
    e++;
    }while(b[i].AuthorName=="");
    e=0;
    do{
    if(e>0)cout<<"This Field is Mandatory, you can't leave it as blank!!!"<<endl;
    cout<<"Enter Purchase Date: ";
    getline(cin,b[i].purchasedDate);
    e++;
    }while(b[i].purchasedDate=="");

    //cin.ignore();
    cout<<"Enter no of copies: ";
    cin>>b[i].noOfCopies;

    cout<<"Enter Price: ";
    cin>>b[i].Price;

    cin.ignore();
    cout<<"Enter Publisher Name: ";
    getline(cin,b[i].PublisherName);

    if(b[i].PublisherName=="")
    {
        b[i].PublisherName="Null";
    }
    cout<<"Enter edition: ";
    cin>>b[i].Edition;
    write<<b[i].BookName<<"\n"<<b[i].AuthorName<<"\n"<<b[i].purchasedDate<<"\n"<<b[i].noOfCopies<<"\n"<<b[i].Price<<"\n"<<b[i].PublisherName<<"\n"<<b[i].Edition<<"\n"<<b[i].BookStatus<<"\n"<<b[i].BorrowedBy<<endl;
        ofstream logs;
        logs.open("booksLogs1.txt",ios::out|ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        logs << dt;
        logs<<"Book: "<<b[i].BookName<<" was added."<<endl;
        logs.close();
    i++;
    cout<<"Enter 1 to continue adding books:";
    cin>>choise;
    cin.ignore();
    }while(choise==1);
}
void deleteBooks(string bookToDelete,int fault)
{

    int flag=0;
    for(int j=0;j<i;j++)
    {
        if(b[j].BookName==bookToDelete)
        {
            flag=1;
        }
        if(flag==1)
        {
            b[j].BookName=b[j+1].BookName;
            b[j].PublisherName=b[j+1].PublisherName;
            b[j].AuthorName=b[j+1].AuthorName;
            b[j].purchasedDate=b[j+1].purchasedDate;
            b[j].noOfCopies=b[j].noOfCopies;
            b[j].Price=b[j+1].Price;
            b[j].Edition=b[j+1].Edition;
            b[j].BookStatus=b[j+1].BookStatus;
            b[j].BorrowedBy=b[j+1].BorrowedBy;
        }
    }

    ifstream read;
    read.open("bookself1.txt",ios::in);
    ofstream temp;
    temp.open("tempBookself1.txt",ios::out);
    string line;
    int count=0;
    while(getline(read,line))
    {
        if(line==bookToDelete ||(count>=1 && count<9))
        {
            flag=1;
            count++;
        }
        if(count>=1 && count<=9)
        {
            if(count==9)
            {
                count=0;
            }
            continue;
        }

        temp<<line<<endl;

    }
    read.close();
    temp.close();
    ofstream write;
    write.open("bookself1.txt",ios::out|ios::trunc);
    ifstream temp1;
    temp1.open("tempBookself1.txt",ios::in);
    while(getline(temp1,line))
    {
        write<<line<<endl;
    }
    write.close();
    temp1.close();
    if(flag==1 && fault==0)
    {
        ofstream logs;
        logs.open("booksLogs1.txt",ios::out|ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        logs << dt;
        logs<<"Book: "<<bookToDelete<<" was deleted."<<endl;
        logs.close();
        cout<<"Book: "<<bookToDelete<<" deleted successfully"<<endl;
        i--;
    }
    else if(flag==0)
    {
        cout<<"Book: "<<bookToDelete<<" could not be found"<<endl;
    }

}
void updateBooks()
{
    cin.ignore();
    string BookName1;
    string PublisherName1;
    string AuthorName1;
    char PurchaseDate[20];
    int NoOfCopies;
    int Price1;
    int Edition1;
    string BookStatus1;
    string BorrowedBy1;
    cout<<"Enter Book Name to update: ";
    getline(cin,BookName1);
    cout<<"Enter Author Name to update: ";
    getline(cin,AuthorName1);
    cout<<"Enter Purchase Date: ";
    cin.get(PurchaseDate,20);
    cout<<"Enter no of copies: ";
    cin>>NoOfCopies;
    cout<<"Enter Price to update: ";
    cin>>Price1;
    cin.ignore();
    cout<<"Enter Publisher Name to update: ";
    getline(cin,PublisherName1);
    if(PublisherName1=="")
    {
        PublisherName1="Null";
    }
    cout<<"Enter edition to update: ";
    cin>>Edition1;

    int flag=0;
    ifstream read;
    read.open("bookself1.txt",ios::in);
    string line;
    int count=0;
    while(getline(read,line))
    {
        if(line==BookName1 || count>0)
        {
            flag=1;
            count++;
            switch(count)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                BookStatus1=line;
                break;
            case 9:
                BorrowedBy1=line;
                count=0;
                break;
            }
        }

    }
    read.close();
    if(flag==1)
    {
        deleteBooks(BookName1,1);
        ofstream write;
        write.open("bookself1.txt",ios::out|ios::app);
        write<<BookName1<<"\n"<<AuthorName1<<"\n"<<PurchaseDate<<"\n"<<NoOfCopies<<"\n"<<Price1<<"\n"<<PublisherName1<<"\n"
        <<Edition1<<"\n"<<BookStatus1<<"\n"<<BorrowedBy1<<endl;
        cout<<"Book: "<<BookName1<<" Updated Successfully."<<endl;
        ofstream logs;
        logs.open("booksLogs1.txt",ios::out|ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        logs << dt;
        logs<<"Book: "<<BookName1<<" was updated."<<endl;
        logs.close();
    }

    if(flag==0)
    {
        cout<<"Book: "<<BookName1<<" could not be found"<<endl;
        displayBooks();
    }
}
void searchBooks()
{
    cin.ignore();
    string bookToSearch;
    cout<<"Enter Book Name to Search: ";
    getline(cin,bookToSearch);
    int flag=0;
    ifstream read;
    read.open("bookself1.txt",ios::in);
    string line;
    int count=0;
    while(getline(read,line))
    {
        if(line==bookToSearch || count>0)
        {
            flag=1;
            count++;
            switch(count)
            {
            case 1:
                cout<<"Book Name: ";
                cout<<line<<endl;
                break;
            case 2:
                cout<<"Author Name: ";
                cout<<line<<endl;
                break;
            case 3:
                cout<<"Purchased date: ";
                cout<<line<<endl;
                break;
            case 4:
                cout<<"No of copies: ";
                cout<<line<<endl;
                break;
            case 5:
                cout<<"Price: ";
                cout<<line<<endl;
                break;
            case 6:
                cout<<"Publisher Name: ";
                cout<<line<<endl;
                break;
            case 7:
                cout<<"edition: ";
                cout<<line<<endl;
                break;
            case 8:
                cout<<"Book status: ";
                cout<<line<<endl;
                break;
            case 9:
                cout<<"Book Borrowed by: ";
                cout<<line<<endl;
                count=0;
                break;
            }
        }

    }
    read.close();

    if(flag==0)
    {
        cout<<"Book: "<<bookToSearch<<" could not be found"<<endl;
        displayBooks();
    }
}

void displayBooks()
{
    ifstream read;
    read.open("bookself1.txt",ios::in);
    string line;
    int count=0;
    if(!read.eof())
    while(getline(read,line))
    {
        count++;
        switch(count)
        {
        case 1:
            cout<<"Book Name: ";
            cout<<line<<endl;
            break;
        case 2:
            cout<<"Author Name: ";
            cout<<line<<endl;
            break;
        case 3:
            cout<<"Purchased date: ";
            cout<<line<<endl;
            break;
        case 4:
            cout<<"No of copies: ";
            cout<<line<<endl;
            break;
        case 5:
            cout<<"Price: ";
            cout<<line<<endl;
            break;
        case 6:
            cout<<"Publisher Name: ";
            cout<<line<<endl;
            break;
        case 7:
            cout<<"edition: ";
            cout<<line<<endl;
            break;
        case 8:
            cout<<"Book status: ";
            cout<<line<<endl;
            break;
        case 9:
            //cout<<"Book Borrowed by: ";
            //cout<<line<<endl;
            count=0;
            break;
            }
    }
    read.close();

}
void librarian()
{
    int option,check;
    string UserId,Password;
    string bookToDelete;
    do{
        cout<<"Enter your User Email: ";
        cin>>UserId;
        cout<<"Enter your Password: ";
        cin>>Password;
        check=checkingLibrarian(UserId,Password);
        if(check == 1)
        {
            do
            {
                cout<<"===================================="<<endl;
                cout<<"Hello, Welcome to the Library."<<endl;
                cout<<"===============LIBRARIAN============"<<endl;
                cout<<"\t   1.  Add Books"<<endl;
                cout<<"\t   2.  Delete Books"<<endl;
                cout<<"\t   3.  Update Books"<<endl;
                cout<<"\t   4.  Search Book"<<endl;
                cout<<"\t   5.  Add Readers"<<endl;
                cout<<"\t   6.  Add Librarians"<<endl;
                cout<<"\t   7.  Display Books"<<endl;
                cout<<"\t   8.  Display Borrowed List"<<endl;
                cout<<"\t   9.  logs"<<endl;
                cout<<"\t   10. cleanup"<<endl;
                cout<<"\t   11. Exit"<<endl;
                cout<<"===================================="<<endl;
                cout<<"Please select one option from above: ";
                cin>>option;
                cout<<"===================================="<<endl;
                switch(option)
                {
                case 1:
                    addBooks();
                    break;
                case 2:
                    cin.ignore();
                    cout<<"Enter Book Name to Delete: ";
                    getline(cin,bookToDelete);
                    deleteBooks(bookToDelete,0);
                    break;
                case 3:
                    updateBooks();
                    break;
                case 4:
                    searchBooks();
                    break;
                case 5:
                    addReaders();
                    break;
                case 6:
                    addLibrarians();
                    break;
                case 7:
                    displayBooks();
                    break;
                case 8:
                    ViewList();
                    break;
                case 9:
                    displayLogs();
                    break;
                case 10:
                    cleanUp();
                    break;
                case 11:
                    break;
                default:
                    cout<<"Enter valid option"<<endl;
                }
            }while(option!=11);
        }
        else
        {
            cout<<"Invalid User Id or Password!!!"<<endl;
            check=1;
        }
    }while(check==0);

}
int checkingLibrarian(string UserId,string Password)
{
    string line;
    ifstream read;
    read.open("LibrariansInfo1.txt",ios::in);
    int count=0;
    while(getline(read,line))
    {
        if(line==UserId ||count>0)
        {
            count++;
            if(count==3)
            {
                if(line==Password)
                {
                    return 1;
                }
               break;
            }
        }
    }
    return 0;
}
int checking(string UserId,string Password)
{
    string line;
    ifstream read;
    read.open("ReadersInfo1.txt",ios::in);
    int count=0;
    while(getline(read,line))
    {
        if(line==UserId ||count>0)
        {
            count++;
            if(count==3)
            {
                if(line==Password)
                {
                    return 1;
                }
               break;
            }
        }
    }
    return 0;
}
string namechecking(string UserId)
{
    string line;
    ifstream read;
    read.open("ReadersInfo1.txt",ios::in);
    int count=0;
    while(getline(read,line))
    {
        if(line==UserId ||count>0)
        {
            count++;
            if(count==2)
            {
               break;
            }
        }
    }
    return line;

}
void ViewList()
{

    /*for(map< string,vector<string>> ::iterator mit=BorrowedList.begin();mit!=BorrowedList.end();mit++)
    {
        for(vector<string>:: iterator vit=((*mit).second).begin();vit!=((*mit).second).end();vit++)
        {
            //cout<<"HI"<<endl;
            cout<<"Book : "<<(*mit).first <<" Name "<<" : "<<(*vit)<<endl;

        }
    }*/

    ifstream read;
    read.open("BorrowedList.txt",ios::in);
    string line;
    while(getline(read,line))
    {
      cout<<line<<endl;
    }
}

void cleanUp()
{
    int option;
    ofstream write3;
    ofstream write1;
    ofstream write2;
    do
    {
        cout<<"===================================="<<endl;
        cout<<"Hello, Welcome to the Library."<<endl;
        cout<<"==============CLEANUP==============="<<endl;
        cout<<"\t   1. Clear Logs"<<endl;
        cout<<"\t   2. Clear Book self"<<endl;
        cout<<"\t   3. Clear Borrowed logs"<<endl;
        cout<<"\t   4. Exit"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Please select one option from above: ";
        cin>>option;
        cout<<"===================================="<<endl;
        if(option==1)
        {
            write3.open("booksLogs1.txt",ios::out|ios::trunc);
            write3.close();
            cout<<"Logs cleared Successfully"<<endl;
        }
        if(option==2)
        {
            write1.open("bookself1.txt",ios::out|ios::trunc);
            write1.close();
            cout<<"Books cleared Successfully"<<endl;
        }
        if(option==3)
        {
            write2.open("BorrowedList.txt",ios::out|ios::trunc);
            write2.close();
            cout<<"Borrowed Logs cleared Successfully"<<endl;
        }
        if(option!=1 && option!=2 && option!=3)
            cout<<"Enter valid option"<<endl;

    }while(option!=4);
}
void ReadersearchBooks(string UserId)
{
    cin.ignore();
    string bookToSearch;
    cout<<"Enter Book Name to Search: ";
    getline(cin,bookToSearch);
    int flag=0;
    string BookName1;
    string PublisherName1;
    string AuthorName1;
    string Price1;
    string PurchaseDate1;
    string NoOfCopies;
    string Edition1;
    string BookStatus1;
    string BorrowedBy1;
    ifstream read;
    read.open("bookself1.txt",ios::in);
    string line;
    int count=0;
    while(getline(read,line))
    {
        if(line==bookToSearch || count>0)
        {
            flag=1;
            count++;
            switch(count)
            {
            case 1:
                cout<<"Book Name: ";
                BookName1=line;
                cout<<line<<endl;
                break;
            case 2:
                cout<<"Author Name: ";
                AuthorName1=line;
                cout<<line<<endl;
                break;
            case 3:
                cout<<"Purchased date: ";
                PurchaseDate1=line;
                cout<<line<<endl;
                break;
            case 4:
                cout<<"no of copies: ";
                NoOfCopies=line;
                cout<<line<<endl;
                break;
            case 5:
                cout<<"Price: ";
                Price1=line;
                cout<<line<<endl;
                break;
            case 6:
                cout<<"Publisher Name: ";
                PublisherName1=line;
                cout<<line<<endl;
                break;
            case 7:
                cout<<"edition: ";
                Edition1=line;
                cout<<line<<endl;
                break;
            case 8:
                cout<<"Book status: ";
                BookStatus1=line;
                cout<<line<<endl;
                break;
            case 9:
                cout<<"Book Borrowed by: ";
                BorrowedBy1=line;
                cout<<line<<endl;
                string choise;
                cout<<"Do you want to borrow this Book ? (enter yes or no): "<<endl;
                cin>>choise;
                int nn=NoOfCopies[0]-'0';
                if(choise=="yes")
                {
                if( nn!=0)
                {
                    stringstream ss;
                    ss<<NoOfCopies;
                    int n;
                    ss>>n;
                    stringstream ss1;
                    n=n-1;
                    ss1<<n;
                    string m;
                    ss1>>m;
                   NoOfCopies=m;
                   if(n!=0)
                   {
                    BookStatus1="Available";
                   }
                   else
                    {
                    BookStatus1="Not Available";
                   }
                    BorrowedBy1=namechecking(UserId);
                    ofstream logs;
                    logs.open("booksLogs1.txt",ios::out|ios::app);
                    time_t now = time(0);
                    char* dt = ctime(&now);
                    logs << dt;
                    logs<<"Book: "<<BookName1<<" borrowed by "<<BorrowedBy1<<endl;
                    logs.close();
                    BorrowedList[BookName1].push_back(BorrowedBy1);
                    ofstream write;
                    write.open("BorrowedList.txt",ios::out|ios::app);
                    write<<"Book : "<<BookName1<<" Name "<<" : "<<BorrowedBy1<<endl;
                    write.close();
                    cout<<"Congradulations !!! Book is available, collect your Book at Front Desk, Thank you"<<endl;
                }
                else
                {
                    cout<<"Sorry, Book is not available to borrow at this moment, come back later"<<endl;
                }
                }
                else
                {
                    cout<<"Thank you for visiting us!!!"<<endl;
                }
                break;
            }
        }

        if(count==9)
        {
            break;
        }
    }
    deleteBooks(bookToSearch,1);
    ofstream write;
    write.open("bookself1.txt",ios::out|ios::app);
    write<<BookName1<<"\n"<<AuthorName1<<"\n"<<PurchaseDate1<<"\n"<<NoOfCopies<<"\n"<<Price1<<"\n"<<PublisherName1<<"\n"
    <<Edition1<<"\n"<<BookStatus1<<"\n"<<BorrowedBy1<<endl;
    read.close();
    if(flag==0)
    {
        cout<<"Book: "<<bookToSearch<<" could not be found"<<endl;
        displayBooks();
    }
}
void reader()
{
    int option,check;
    string UserId,Password;
    do{
        cout<<"Enter your User Email: ";
        cin>>UserId;
        cout<<"Enter your Password: ";
        cin>>Password;
        check=checking(UserId,Password);
        if(check == 1)
        {
            do
            {
                cout<<"===================================="<<endl;
                cout<<"Hello, Welcome to the Library."<<endl;
                cout<<"================READER=============="<<endl;
                cout<<"\t   1. Search Book"<<endl;
                cout<<"\t   2. Display Books"<<endl;
                cout<<"\t   3. Return Books"<<endl;
                cout<<"\t   4. Exit"<<endl;
                cout<<"===================================="<<endl;
                cout<<"Please select one option from above: ";
                cin>>option;
                cout<<"===================================="<<endl;
                switch(option)
                {
                case 1:
                    ReadersearchBooks(UserId);
                    break;
                case 2:
                    displayBooks();
                    break;
                case 3:
                    returnBooks();
                    break;
                case 4:
                    break;
                default:
                    cout<<"Enter valid option"<<endl;
                }
            }while(option!=4);
        }
        else
        {
            cout<<"Invalid User Id or Password!!!"<<endl;
            check=1;
        }
    }while(check==0);
}
int main()
{
    //addLibrarians();
    int option;
    do
    {
        //system("cls");
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
            system("color 3");
            librarian();
            break;
        case 2:
            system("color 2");
            reader();
            break;
        case 3:
            break;
        default:
            cout<<"Enter valid option"<<endl;
        }
    }while(option!=3);
}



