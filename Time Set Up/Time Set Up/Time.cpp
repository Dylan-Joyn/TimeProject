#include "Time.h"
#include <cstdlib>
Time::Time() : Time(0, 0, 0, 0) {}

Time::Time(int d, int h, int m, int s) : 
	days(d), hours(h), minutes(m), seconds(s)
{

}
Time::Time(int h, int m, int s):Time(0, h, m, s) {}

Time::Time(int h, int m) :Time(0, h, m, 0) {}


void Time::simplify() {
	if (seconds >= 60) {
		minutes += seconds / 60;
		seconds = seconds % 60;
	}

	if (seconds < 0) {
		minutes -= ((abs(seconds) / 60) + 1);
		seconds = 60-(abs(seconds) % 60);
	}

	if (minutes >= 60) {
		hours += minutes / 60;
		minutes = minutes % 60;
	}

	if (minutes < 0){
		hours -= ((abs(minutes) / 60) + 1);
		minutes = 60-(abs(minutes) % 60);
	}
	
	if (hours >= 24) {
		days += hours / 24;
		hours = hours % 24;
	}

	if (hours < 0) {
		days -= ((abs(hours) / 24) + 1);
		hours = 24-(abs(hours) % 24);
	}
}

Time Time::operator+(Time& right) {
	Time tempTime;
	tempTime.hours = this->hours + right.hours;
	tempTime.days = this->days + right.days;
	tempTime.minutes = this->minutes + right.minutes;
	tempTime.seconds = this->seconds + right.seconds;
	tempTime.simplify();
	return tempTime;
}
Time Time::operator-(Time& right) {
	Time tempTime;
	tempTime.hours = this->hours - right.hours;
	tempTime.days = this->days - right.days;
	tempTime.minutes = this->minutes - right.minutes;
	tempTime.seconds = this->seconds - right.seconds;
	tempTime.simplify();
	return tempTime;
}

Time Time::operator++() {
	seconds++;
	simplify();
	return *this;
}
Time Time::operator++(int) {
	Time oldTime = *this;
	seconds++;
	simplify();
	return oldTime;
}
Time Time::operator--() {
	seconds--;
	simplify();
	return *this;
}
Time Time::operator--(int) {
	Time oldTime = *this;
	seconds--;
	simplify();
	return oldTime;
}

int Time::getDays() const {
	return days;
}
int Time::getHours() const {
	return hours;
}
int Time::getMinutes() const {
	return minutes;
}
int Time::getSeconds() const {
	return seconds;
}