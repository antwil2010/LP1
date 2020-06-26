#include "date.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Date::Date() : year(0), month(0), day(0)
{
}

void Date::set_from_string(const std::string& date){
	stringstream d(date);
	char descarte;
	d >> day;
	d >> descarte;
	d >> month;
	d >> descarte;
	d >> year;
}

std::string Date::date_to_string(){
	string data = to_string(day) + "/" + to_string(month) + "/" + to_string(year);;
	return data;
}
