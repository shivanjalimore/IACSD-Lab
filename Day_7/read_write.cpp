#include <iostream>
#include <fstream>
using namespace std;
class Base
{
public:
    int id;
    string name;

    Base()
    {
        id = 0;
        name = "No Name";
    }
    Base(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    void display()
    {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
    }
    void write()
    {
        ofstream fout("file.txt", ios::app);
        if (fout.is_open())
        {
            cout << "Enter id : " << endl;
            cin >> id;
            cout << "Enter name : " << endl;
            cin >> name;
            fout << "Your Entered data : " << endl;
            fout << "ID: " << id << " Name : " << name << endl;
            fout.close();
        }
        else
        {
            cout<<" File is not opening "<<endl;
        }
    }

    // void read()
    // {
    //     ifstream fin("file.txt",ios::in | ios::binary);
    //     string s;
    //     if (fin.is_open())
    //     {
    //         // while (getline(fin, s))  //read each line from the file
    //         // {
    //         //     cout <<" "<<s<< endl;
    //         // }
    //         fin >> id >> name >> department;
    //         cout<<" id : "<<id<<" Name : "<<name<<" department : "<<department<<endl;
    //     //     // Add 5 to the id
    //     //     id += 5;
    //     //     // Display modified data
    //     //    cout << "Modified Data:" << endl;
    //     // display();
    //         fin.close();
    //     }
    //     else
    //     {
    //         cout << "--- Error in reading ---" << endl;
    //     }
    // }

};
class Derived : public Base
{
public:
    string department;
    Derived()
    {
        department = " No Department";
    }
    Derived(int id, string name, string department) : Base(id, name)
    {
        this->department = department;
    }
    void display()
    {
        cout << "Department : " << department << endl;
    }
    void write()
    {
        Base::write();
        ofstream fout("file.txt", ios::app);
        if (fout.is_open())
        {
            cout << "Enter department : " << endl;
            cin >> department;

            fout << "Your Entered data : " << endl;
            fout << "Department : " << department << endl;
            fout.close();
        }
          else
        {
            cout<<" File is not opening "<<endl;
        }
    }
    void read()
    {
        ifstream fin("file.txt",ios::in | ios::binary);
        string s;
        if (fin.is_open())
        {
            // while (getline(fin, s))  //read each line from the file
            // {
            //     cout <<" "<<s<< endl;
            // }
            fin >> id >> name >> department;
            cout<<" id : "<<id<<" Name : "<<name<<" department : "<<department<<endl;
        //     // Add 5 to the id
        //     id += 5;
        //     // Display modified data
        //    cout << "Modified Data:" << endl;
        // display();
            fin.close();
        }
        else
        {
            cout << "--- Error in reading ---" << endl;
        }
    }
};
int main()
{
    Base bobj;
    Derived dobj;
    //  input obj;
    int choice;
    do
    {
        cout << "\n\nChoose an option:" << endl;
        cout << "1. Fill data" << endl;
        cout << "2. Read data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            dobj.write();
            break;
        case 2:
            dobj.read();
            break;
        case 3:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}