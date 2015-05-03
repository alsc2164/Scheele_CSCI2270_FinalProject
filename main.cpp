#include <iostream>
#include "tree.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    tree t;
    string STRING;
    ifstream infile(argv[1]);
    //int rankings;
    //string title;
    int v;
    node* n;
    //int year;
    //int quantity;
    while(getline(infile,STRING))
    {
        stringstream ss(STRING);
        string token;
        int counter = 0;
        while(getline(ss, token, ','))
        {
           t.addNode(atoi(token.c_str()));
        }
    }
    infile.close();
    int pick = 0;
    while(pick != 4)
    {
        cout << "====Main Menu====" << endl;
        cout << "1.Print data about tree/data" << endl;
        cout << "2.Modify the data: add/remove" << endl;
        cout << "3.Generate output file" << endl;
        cout << "4.Quit" << endl;
        cin >> pick;
        switch(pick)
        {
        case 1:
            {
                int pick2 = 0;
                while(pick2 != 10)
                {
                    cout << "====Print Data Menu====" << endl;
                    cout << "1.Print Data in Order" << endl;
                    cout << "2.Print Max" << endl;
                    cout << "3.Print Min" << endl;
                    cout << "4.Print Average" << endl;
                    cout << "5.Find Number Frequency" << endl;
                    cout << "6.Find Most Appeared Number" << endl;
                    cout << "7.Print total" << endl;
                    cout << "8.Print tree height" << endl;
                    cout << "9.Print Number of data Points" << endl;
                    cout << "10.Back to main menu" << endl;
                    cin >> pick2;
                    switch(pick2)
                    {
                    case 1:
                        t.printOrder();
                        break;
                    case 2:
                        cout << "Max Value: " << t.maximum()<<endl;
                        break;
                    case 3:
                        cout << "Min Value: " << t.minimum()<< endl;
                        break;
                    case 4:
                        cout  << "The average is: " << t.ave() << endl;
                        break;
                    case 5:{
                        int pick;
                        cout << "Enter the number you want to find the frequency of: " << endl;
                        cin >> pick;
                        cout << pick << endl;
                        cout << "This number appears " << t.frequency(pick) << " times." << endl;
                    }
                        break;
                    case 6:{
							
							t.print_numbers_forward_and_backward();
					}
					break;
                    case 7:
                        cout << "The total is: " << t.total() << endl;
                        break;
                    case 8:
                        cout << "Tree Height: " << t.treeH()<<endl;
                        break;
                    case 9:
                        cout << "The number of data points: " << t.length() << endl;
                        break;
                    }
                }
            }
            break;
        case 2:
            {
                int pick2 = 0;
                while(pick2 != 3)
                {
                    cout << "====Modify Data====" <<endl;
                    cout << "1.Add a Number" << endl;
                    cout << "2.Remove a Number" << endl;
                    cout << "3.Back to Main Menu" << endl;
                    cin >> pick2;
                    switch(pick2)
                    {
                    case 1:{
                        cout << "Add:" << endl;
                        cin.ignore(256, '\n');
                        string tempA;
                        char temp[256];
                        getline(cin, tempA);
                        v = atoi(tempA.c_str());
                        t.addNode(v);}
                        break;
                    case 2:{
                        cout << "Remove:" << endl;
                        cin.ignore(256, '\n');
                        string tempA;
                        char temp[256];
                        getline(cin, tempA);
                        v = atoi(tempA.c_str());
                        t.deleteNode(v);}
                        break;
                    }
                }
            }
            break;
        case 3:{
                cout << "Output File Generated" << endl;
                t.output();
            }
            break;
        case 4:
            cout << "Goodbye" << endl;
            break;
        }
    }
    return 0;
}
