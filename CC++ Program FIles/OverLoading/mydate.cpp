#include "mydate.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& output, const Date& date){
	if(date.Month == 1){
		if(date.Day >0 && date.Day < 32){
			output << "January " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 2){
		if(date.Day >0 && date.Day < 29){
			output << "February " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 3){
		if(date.Day >0 && date.Day < 32){
			output << "March " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 4){
		if(date.Day >0 && date.Day < 31){
			output << "April " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 5){
		if(date.Day >0 && date.Day < 32){
			output << "May " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 6){
		if(date.Day >0 && date.Day < 31){
			output << "June " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 7){
		if(date.Day >0 && date.Day < 32){
			output << "July " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 8){
		if(date.Day >0 && date.Day < 32){
			output << "August " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 9){
		if(date.Day >0 && date.Day < 31){
			output << "September " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 10){
		if(date.Day >0 && date.Day < 32){
			output << "October " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 11){
		if(date.Day >0 && date.Day < 31){
			output << "November " << date.Day << ", " << date.Year << endl;
		}
	}else if(date.Month == 12){
		if(date.Day >0 && date.Day < 32){
			output << "December " << date.Day << ", " << date.Year << endl;
		}
	}else{
		output << date.Month << date.Day << ", " << date.Year << endl<< endl;
	}
	return output;
}

Date Date::operator++(){
	++Day;
	Date date(Month, Day, Year);
	return date;
}
Date Date::operator++(int){
	Date date(Month, Day, Year);
	Day++;
	return date;
}
Date Date::operator+=(int day){
	Day += day;
	Date date(Month, Day, Year);
	return date;
}
Date::Date(){
	Year = 1900;
	Month = 1;
	Day = 1;
}
Date::Date(int month, int day, int year){
	this->Year = year;
	this->Month = month;
	this->Day = day;
}