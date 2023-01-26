#include <iostream>
#include <locale.h>
#include<stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include<fstream>

using namespace std;


class User
{
	string id;
	char gender;
	int age;
	string city;
	string edu;
	vector<string> interests;
	char wish_gender;
	int age_from;
	int age_to;
	string wish_city;
	string wish_edu;
	vector<string>wish_interests;
	int points;

public:



	User()
	{
		id = "";
		gender = ' ';
		age = 0;
		city = "";
		edu = "";
		interests = {};
		wish_gender = ' ';
		age_from = 0;
		age_to = 0;
		wish_city = "";
		wish_edu = "";
		wish_interests = {};
		points = 0;

	}
	User(string id, char gender, int age, string city, string edu, vector<string>interests, char wish_gender, int age_from, int age_to, string wish_city,
		string wish_edu, vector<string>wish_interests)
	{
		this->id = id;
		this->gender = gender;
		this->age = age;
		this->city = city;
		this->edu = edu;
		this->interests = interests;
		this->wish_gender = wish_gender;
		this->age_from = age_from;
		this->age_to = age_to;
		this->wish_city = wish_city;
		this->wish_edu = wish_edu;
		this->wish_interests = wish_interests;
		this->points = 0;

	}

	void Print();
	void Print_points();
	string Get_id();
	int Get_points();

	char Get_gender();
	char Get_wish_gender();
	void friend Find_match(User& user1, User& user2);
	void friend Final_result(User& you, vector<User>& users, vector<User>& your_gender_group, vector<User>& top, vector<string> _interests);
};

string Choose_interest(vector<string>& v);
string Choose_education(vector<string>& v);
