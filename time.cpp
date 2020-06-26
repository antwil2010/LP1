#include <iostream>
#include <string>
#include <sstream>
#include "time.h"

using namespace std;

Time::Time() : hour(0), minute(0), second(0)
{
}

void Time::set_from_string(const std::string& time){
	stringstream t(time);
	char descarte;
	t >> hour;
	t >> descarte;
	t >> minute;
	t >> descarte;
	t >> second;
}
    
std::string Time::hour_to_string(){
	string hora = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	return hora;	
}
