
#include <iostream>
#include <fstream>
#include <vector>
#include "expense_records.h"

using namespace std;


void initialize(ifstream&);


ifstream inFile;
ofstream outFile;
ExpenseRecords ER;


int main()
{
    initialize(inFile);

    ER.report_file(outFile);


    return 0;
}

void initialize(ifstream& inFile) {

    string str, name;
    int week_num, ctg_num;
    int count = 0;
    float amount;

    // open files, check errors, iterate through file eof, getline
    inFile.open("1dates.txt");
    if (inFile.fail()) {
        cout << "File dates.txt not found!";
    }
    else {
        while (!inFile.eof()) {
            getline(inFile, str);
            week_num = stoi(str);
            getline(inFile, name);
            cout << week_num << " " << name << endl;
            ER.add_week(week_num, name);
            count++;
        }
        inFile.close();
        cout << "Found " << count << " weeks" << endl;
    }

    count = 0;

    inFile.open("2categories.txt");
    if (inFile.fail()) {
        cout << "File dates.txt not found!";
    }
    else {
        while (!inFile.eof()) {
            getline(inFile, str);
            ctg_num = stoi(str);
            getline(inFile, name);
            cout << ctg_num << " " << name << endl;
            ER.add_category(ctg_num, name);
            count++;
        }
        inFile.close();
        cout << "Found " << count << " categories" << endl;
    }

    count = 0;

    inFile.open("3expenses.txt");
    if (inFile.fail()) {
        cout << "File dates.txt not found!";
    }
    else {
        while (!inFile.eof()) {
            getline(inFile, str);
            week_num = stoi(str);
            getline(inFile, str);
            ctg_num = stoi(str);
            getline(inFile, str);
            amount = stof(str);
            cout << week_num << " " << ctg_num << " " << amount << endl;
            ER.add_amount(week_num, ctg_num, amount);
            count++;
        }
        inFile.close();
        cout << "Found " << count << " amounts" << endl;
    }


}
