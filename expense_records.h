#pragma once

#include <vector>
#include <string>

class Week {
private:
	int week_num;
	std::string week_name;
public:
	Week(int num, std::string name);
	int get_week_num();
	std::string get_week_name();
};

class Category {
private:
	int ctg_num;
	std::string ctg_name;
public:
	Category(int num, std::string name);
	int get_ctg_num();
	std::string get_ctg_name();
};

class Amount {
private:
	int week_num;
	int ctg_num;
	float amount;
public:
	Amount(int num1, int num2, float the_amount);
	int get_week_num();
	int get_ctg_num();
	float get_amount();
};

class ExpenseRecords {
private:
	std::vector<Week> weeks;
	std::vector<Category> categories;
	std::vector<Amount> amounts;
public:
	void add_week(int, std::string);
	void add_category(int, std::string);
	void add_amount(int, int, float);

	std::string get_week_name(int);
	std::string get_ctg_name(int);
	float get_total_amounts();
	int get_total_weeks();
	void report_records(int, std::ostream&);
	void report_file(std::ofstream&);
};