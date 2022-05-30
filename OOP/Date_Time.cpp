// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q38
#include <iostream>
#include <string>
using namespace std;

class Date {
	public:
		Date() {
			year = 1;
			month = 1;
			day = 1;
		}
		Date(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		}
		virtual string toString() { // "mm, dd, yyyy"
			string res;
			if(month < 10)
				res += '0';
			res += (to_string(month) + ", ");
			if(day < 10)
				res += '0';
			res += (to_string(day) + ", ");
			res += to_string(year);
			return res;
		}
		void setDay(int d) {
			day = d;
		}
		void setMonth(int m) {
			month = m;
		}
		void setYear(int y) {
			year = y;
		}
		int getDay()  {
			return day;
		}
		int getMonth() const {
			return month;
		}
		int getYear() const {
			return year;
		}
		void addDays(int d) { // adds the specified number of days to this instance
			day += d;
		}
		void addMonths(int m) { // adds the specified number of months to this instance
			month += m;
		}
		void addYears(int y) { // adds the specified number of years to this instance
			year += y;
		}
		static bool isLeapYear(const Date &d) {
			int y = d.getYear();
			if(y % 4 == 0) {
				if (y % 100 == 0) {
					if (y % 400 == 0)
						return true; // nh?ng nam 1000, 2000
					else return false; // nh?ng nam 1900, 2100
				}
				return true; // nh?ng nam chia h?t cho 4 còn l?i: 2020
			}
			return false;
		}
	private:
		int year, month, day;
};
class TimeSpan {
	public:
		TimeSpan();
		TimeSpan(int d, int hh, int mm, int ss) {
			day = d;
			hour = hh;
			minute = mm;
			second = ss;
		}
		int toTotalDays() {
			return day;
		}
		int toTotalHours() {
			return (hour + day*24);
		}
		int toTotalMinutes() {
			return (minute + toTotalHours() * 60);
		}
		int toTotalSeconds() {
			return (second + toTotalMinutes() * 60);
		}
		string toString() { //// dd HH:MM:SS
			string res;
			res = to_string(day) + " ";
			res += (to_string(hour) + ":");
			res += (to_string(minute) + ":");
			res += to_string(second);
			return res;
		}
	private:
		int day, hour, minute, second;
};
class DateTime : public Date {
	public:
		virtual string toString() { // "mm/dd/yyyy HH:MM:SS"
			string res;
			if(getMonth() < 10)
				res += ("0");
			res += (to_string(getMonth()) + "/");
			if(getDay() < 10)
				res += ("0");
			res += (to_string(getDay()) + "/");
			res += (to_string(getYear()) + " ");
			if(hour < 10)
				res += '0';
			res += (to_string(hour) + ":");
			if(minute < 10)
				res += '0';
			res += (to_string(minute) + ":");
			if(second < 10)
				res += '0';
			res += (to_string(second));
			return res;
		}
		DateTime() : Date() {
			hour = 0;
			minute = 0;
			second = 0;
		}
		DateTime(int y, int m, int d, int hh, int mm, int ss) : Date(y, m, d) {
			hour = hh;
			minute = mm;
			second = ss;
		}
		void setHour(int h) {
			hour = h;
		}
		void setMinute(int m) {
			minute = m;
		}
		void setSecond(int s) {
			second = s;
		}
		int getHour() const {
			return hour;
		}
		int getMinute() const {
			return minute;
		}
		int getSecond() const {
			return second;
		}
		void addHours(int h) { // adds the specified number of hours to this instance
			hour += h;
		}
		void addMinutes(int m) { // adds the specified number of minutes to this instance
			minute += m;
		}
		void addSeconds(int s) { // adds the specified number of seconds to this instance
			second += s;
		}
		TimeSpan operator-(const DateTime &dt)  { // return a TimeSpan object represents a time interval
			int d = getDifference(dt, *this);
			int h = this->getHour() - dt.getHour();
			int m = this->getMinute() - dt.getMinute();
			int s = this->getSecond() - dt.getSecond();
			return TimeSpan(d, h, m, s);
		}
	private:
		int hour, minute, second;
		const int monthDays[12]
		    = { 31, 28, 31, 30, 31, 30,
		        31, 31, 30, 31, 30, 31
		      };

		int countLeapYears(Date d) {
			int years = d.getYear();

			if (d.getMonth() <= 2)
				years--;

			return years / 4
			       - years / 100
			       + years / 400;
		}

		int getDifference(Date dt1, Date dt2)  {
			long int n1 = dt1.getYear() * 365 + dt1.getDay();
			for (int i = 0; i < dt1.getMonth() - 1; i++)
				n1 += monthDays[i];
			n1 += countLeapYears(dt1);
			long int n2 = dt2.getYear() * 365 + dt2.getDay();
			for (int i = 0; i < dt2.getMonth() - 1; i++)
				n2 += monthDays[i];
			n2 += countLeapYears(dt2);
			return (n2 - n1);
		}

};
int main() {
	int y, m, d, hh, mm, ss;
	cin>>y>>m>>d>>hh>>mm>>ss;
	DateTime d1(y, m, d, hh, mm, ss);
	cin>>y>>m>>d>>hh>>mm>>ss;
	DateTime d2(y, m, d, hh, mm, ss);
	cout<<(d2 - d1).toTotalSeconds();
	return 0;
}
