// ConsoleApplication3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
	string name;
	string email;
public:
	User(string name="", string email=""): name{name}, email{email} {}
	string getname() const {return name;}
	string getemail() const { return email;}
	void setname(string new_name) { name = new_name; }
	void setemail(string new_eamil) { email = new_eamil; }
};

class User_Array
{
protected:
	User* Users;
	int n;
public:
	User_Array(int n)
	{
		if (n < 0) n = 0;
		Users = new User[n];
		this->n = n;
	}
	void addUser(string name, string email)
	{
		for (int i = 0; i < n; i++)
		{
			if ((Users[i].getname() != "") && (Users[i].getemail() != ""))
			{
				Users[i].setname(name);
				Users[i].setemail(email);
			}
		}
		
	}
	string getUser_name(int index) { return Users[index].getname(); }
	int length()
	{
		for (int i = 0; i < n; i++)
		{
			if ((Users[i].getname() != "") && (Users[i].getemail() != ""))
			{
				return i + 1;
			}
		}
		return n;
	}
	//void delete_User(int index) { delete UserArray[index];}
};

class Room
{
protected:
	int room;
public:
	Room(int n=0): room{n} {}
	int getRoom() { return room; }
};

class Room_Array
{
protected:
	Room* Rooms;
	int n;
	int nofr;
public:
	Room_Array(int n):nofr{0}
	{
		if (n < 0) n = 0;
		Rooms = new Room[n];
		this->n = n;
	}
	void addRoom(int k)
	{
		++nofr;
		Rooms[nofr] = k;
	}
	int getRoom(int index) { return Rooms[index].getRoom(); }
	int length() { return nofr; }
	//void delete_Room
};

class Meeting
{
protected:
	int start;
	int end;
	string Day;
	int day;
	string topic;
	int room;
	User_Array UserArray;
public:
	Meeting(int start = 0, int end = 0, string Day = "", string topic = "", int room = 0) : start{ start }, end{ end }, Day{ Day }, topic{ topic }, room{ room }, UserArray { 100 }  {}
	void set_start(int n) { start = n; }
	void set_end(int n) { end = n; }
	void set_day(string d)
	{
		//switch문 조건문??
		if (d == "Mon")
		{
			day = 0;
			Day = "Mon";
		}
		else if (d == "Tue")
		{
			day = 1;
			Day = "Tue";
		}
		else if (d == "Wed")
		{
			day = 2;
			Day = "Wed";
		}
		else if (d == "Thu")
		{
			day = 3;
			Day = "Thu";
		}
		else if (d == "Fri")
		{
			day = 4;
			Day = "Fri";
		}
		else if (d == "Sat")
		{
			day = 5;
			Day = "Sat";
		}
		else if (d == "Sun")
		{
			day = 6;
			Day = "Sun";
		}
	}
	void set_room(int n) { room = n; }
	void set_topic(string t) { topic = t; }
	void add_user(string name, string email) { UserArray.addUser(name, email); }
	
	int get_room() { return room; }
	string get_day() { return Day; }
	int get_start() { return start; }
	string get_topic() { return topic; }
};

class Meeting_Array
{
public:
	Meeting* meetings;
	int n;

	Meeting_Array(int n) :n{ n } { meetings = new Meeting[n]; }
	int length() { return n; }
	void setMeeting(int start = 0, int end = 0, string Day = "", string topic = "",int room=0)
	{
		for (int i = 0;; i++)
		{
			if (meetings[i].get_topic() != "")
			{
				meetings[i].set_start(start);
				meetings[i].set_end(end);
				meetings[i].set_day(Day);
				meetings[i].set_room(room);
				meetings[i].set_topic(topic);
				break;
			}
		}
			
	}
};

class Day_Meeting
{
protected:
	Meeting_Array daymeeting;
public:
	Day_Meeting():daymeeting{24} {}
	void get_meeting()
	{
		for (int i = 0; i < 24; i++)
		{
			if (daymeeting.meetings[i].get_topic() != "")
			{
				cout << daymeeting.meetings[i].get_start() << endl;
				cout << daymeeting.meetings[i].get_day() << endl;
				cout << daymeeting.meetings[i].get_room() << endl;
				cout << daymeeting.meetings[i].get_topic() << endl;
			}
		}
	}
};

class Week_Meeting
{
protected:
	Day_Meeting* weekmeeting;
public:
	Week_Meeting() { weekmeeting = new Day_Meeting[7]; }
	void get_meeting()
	{
		for (int i = 0; i < 7; i++)
		{
			weekmeeting[i].get_meeting();
		}
	}
};
int main()
{
    return 0;
}

