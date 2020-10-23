#ifndef MYDATE_H
#define MYDATE_H

#include <string>
using namespace std;

class Date {
	public:
		friend ostream& operator << (ostream& output, const Date& date);
		Date operator++();
		Date operator++(int);
		Date operator+=(int Day);
		
		Date();
		Date(int month, int day, int year);
	private:
		int Year;
		int Month;
		int Day;
		
};

#endif