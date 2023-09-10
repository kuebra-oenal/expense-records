#include "expense_records.h"
#include <iostream>
#include <fstream>

using namespace std;

Week::Week(int num, string name) {
	week_num = num;
	week_name = name;
}
int Week::get_week_num() {
	return week_num;
}
string Week::get_week_name() {
	return week_name;
} 

Category::Category(int num, string name) {
	ctg_num = num;
	ctg_name = name;
}
int Category::get_ctg_num() {
	return ctg_num;
}
string Category::get_ctg_name() {
	return ctg_name;
}

Amount::Amount(int num1, int num2, float the_amount) {
	week_num = num1;
	ctg_num = num2;
	amount = the_amount;
}
int Amount::get_week_num() {
	return week_num;
}
int Amount::get_ctg_num() {
	return ctg_num;
}
float Amount::get_amount() {
	return amount;
}

void ExpenseRecords::add_week(int week_num, std::string week_name) {
	weeks.push_back(Week(week_num, week_name));
}
void ExpenseRecords::add_category(int ctg_num, std::string ctg_name) {
	categories.push_back(Category(ctg_num, ctg_name));
}
void ExpenseRecords::add_amount(int week_num, int ctg_num, float the_amount) {
	amounts.push_back(Amount(week_num, ctg_num, the_amount));
}

std::string ExpenseRecords::get_week_name(int num){
	int i = 0;
	while (i < weeks.size() && weeks[i].get_week_num() != num)
		i++;
	return weeks[i].get_week_name();
}

std::string ExpenseRecords::get_ctg_name(int num) {
	int j = 0;
	while (j < categories.size() && categories[j].get_ctg_num() != num)
		j++;
	return categories[j].get_ctg_name();
}

float ExpenseRecords::get_total_amounts() {
	float total_amounts = 0;
	for (int k = 0; k < amounts.size(); k++) {
		total_amounts += amounts[k].get_amount();
	}
	return total_amounts;
		
}

// -----------------------------------
int ExpenseRecords::get_total_weeks() {
	int l = 0;
	while (l < weeks.size())
		l++;
	return l;
}
// -----------------------------------

void ExpenseRecords::report_records(int week_num, std::ostream& stream){
	float total_amount = 0.0f, average = 0.0f;
	int ctg = 0;
	stream << endl << "Expenses for " << get_week_name(week_num) << endl;
	for (Amount& am : amounts)
		if (am.get_week_num() == week_num) {
			stream << get_ctg_name(am.get_ctg_num()) << ": " << am.get_amount() << endl;
			total_amount += am.get_amount();
			ctg = am.get_ctg_num();
		}
	stream << "Total: " << (total_amount) << endl;
	//stream << "ctg_num " << ctg << endl;
}

void ExpenseRecords::report_file(ofstream& outFile) {
	int wname;
	outFile.open("4records.txt");
	if (outFile.fail()) {
		cout << endl << "Couldn't open the file" << endl;
	}
	else {
		outFile << "===========================" << endl;
		for (auto& wk : weeks) {
			wname = wk.get_week_num();
			report_records(wname, outFile);
			outFile << "===========================" << endl;
		}
		outFile << "Total: " << get_total_amounts() << endl;
		outFile << "Weekly average: " << (get_total_amounts() / get_total_weeks());
		cout << "Created 4records.txt successfully!" << endl;
	}
}