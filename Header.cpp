#include "Header.h"
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue,
	LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void User::Print()
{
	cout << "Id number: " << id << "\nGender: " << gender << "\nAge: " << age << "\nCity: " << city << "\nEducation: " << edu << "\nInterests: ";
	vector<string > ::iterator it;
	it = interests.begin();
	for (; it != interests.end(); it++)
	{
		if (it < interests.end() - 1)
			cout << *it << ", ";
		else
			cout << *it << endl;
	}
	char a = 3;
	for (int i = 0; i < 48; i++)
	{
		cout << a;
	}

	cout << endl << "Looking for a " << wish_gender << " from " << age_from << " to " << age_to << " from " << wish_city << endl;
	cout << "Preferable education: " << wish_edu << endl;
	cout << "Preferable interests: ";

	vector<string> ::iterator it1;
	it1 = wish_interests.begin();
	for (; it1 != wish_interests.end(); it1++)
	{
		if (it1 < wish_interests.end() - 1)
			cout << *it1 << ", ";
		else
			cout << *it1 << endl;
	}
	cout << "Points scored:" << points << endl << endl;
}

void User::Print_points()
{
	cout << "User " << id << " got " << points << " points" << endl;
}

string User::Get_id()
{
	return id;
}

int User::Get_points()
{
	return points;
}

char User::Get_gender()
{
	return gender;
}

char User::Get_wish_gender()
{
	return wish_gender;
}

void Find_match(User& user1, User& user2)
{
	if (user1.age >= user2.age_from && user1.age <= user2.age_to && user2.age >= user1.age_from && user2.age <= user1.age_to)
		user2.points++;
	transform(user2.city.begin(), user2.city.end(), user2.city.begin(), tolower);
	transform(user2.wish_city.begin(), user2.wish_city.end(), user2.wish_city.begin(), tolower);
	if (user1.city == user2.wish_city && user1.wish_city == user2.city)
		user2.points++;
	transform(user2.edu.begin(), user2.edu.end(), user2.edu.begin(), tolower);
	transform(user2.wish_edu.begin(), user2.wish_edu.end(), user2.wish_edu.begin(), tolower);
	if (user1.edu == user2.wish_edu && user1.wish_edu == user2.edu)
		user2.points++;
	for (int i = 0; i < user1.interests.size(); i++)
	{
		for (int j = 0; j < user2.wish_interests.size(); j++)
		{
			if (user1.interests[i] == user2.wish_interests[j])
				user2.points++;
		}
	}
	for (int i = 0; i < user2.interests.size(); i++)
	{
		for (int j = 0; j < user1.wish_interests.size(); j++)
		{
			if (user2.interests[i] == user1.wish_interests[j])
				user2.points++;
		}
	}
}

void Final_result(User& you, vector<User>& users, vector<User>& your_gender_group, vector<User>& top, vector<string> _interests)
{
	if (you.Get_gender() == 'F' && you.Get_wish_gender() == 'F')
	{
		copy_if(users.begin(), users.end(), back_inserter(your_gender_group), [](User& u) {return u.Get_gender() == 'F' && u.Get_wish_gender() == 'F'; });
		for (int i = 0; i < your_gender_group.size(); i++)
		{
			Find_match(you, your_gender_group[i]);
		}
		sort(your_gender_group.begin(), your_gender_group.end(), [](User& user1, User& user2) {return user1.Get_points() > user2.Get_points(); });
		copy(your_gender_group.begin(), your_gender_group.end(), back_inserter(top));

		if (top.size() >= 3)
		{
			cout << "Your top three partners:" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				top[i].Print();
			}
			cout << endl << endl;
		}
		Sleep(6000);
		system("cls");
		cout << "YOUR PROFILE:" << endl << endl;
		you.Print();
		cout << endl << endl;
		cout << "!!YOUR PERFECT MATCH!!" << endl << endl;
		top[0].Print();

	}

	if (you.Get_gender() == 'M' && you.Get_wish_gender() == 'F')
	{
		copy_if(users.begin(), users.end(), back_inserter(your_gender_group), [](User& u) {return u.Get_gender() == 'F' && u.Get_wish_gender() == 'M'; });
		for (int i = 0; i < your_gender_group.size(); i++)
		{
			Find_match(you, your_gender_group[i]);
		}
		sort(your_gender_group.begin(), your_gender_group.end(), [](User& user1, User& user2) {return user1.Get_points() > user2.Get_points(); });
		copy(your_gender_group.begin(), your_gender_group.end(), back_inserter(top));
		if (top.size() >= 3)
		{
			cout << "Your top three partners:" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				top[i].Print();
			}
			cout << endl << endl;
		}
		Sleep(6000);
		system("cls");
		cout << "YOUR PROFILE:" << endl << endl;
		you.Print();
		cout << endl << endl;
		cout << "!!YOUR PERFECT MATCH!!" << endl << endl;
		top[0].Print();

	}

	if (you.Get_gender() == 'M' && you.Get_wish_gender() == 'M')
	{
		copy_if(users.begin(), users.end(), back_inserter(your_gender_group), [](User& u) {return u.Get_gender() == 'M' && u.Get_wish_gender() == 'M'; });
		for (int i = 0; i < your_gender_group.size(); i++)
		{
			Find_match(you, your_gender_group[i]);
		}
		sort(your_gender_group.begin(), your_gender_group.end(), [](User& user1, User& user2) {return user1.Get_points() > user2.Get_points(); });
		copy(your_gender_group.begin(), your_gender_group.end(), back_inserter(top));
		if (top.size() >= 3)
		{
			cout << "Your top three partners:" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				top[i].Print();
			}
			cout << endl << endl;
		}
		Sleep(6000);
		system("cls");
		cout << "YOUR PROFILE:" << endl << endl;
		you.Print();
		cout << endl << endl;
		cout << "!!YOUR PERFECT MATCH!!" << endl << endl;
		top[0].Print();

	}



	if (you.Get_gender() == 'F' && you.Get_wish_gender() == 'M')
	{
		copy_if(users.begin(), users.end(), back_inserter(your_gender_group), [](User& u) {return u.Get_gender() == 'M' && u.Get_wish_gender() == 'F'; });
		for (int i = 0; i < your_gender_group.size(); i++)
		{
			Find_match(you, your_gender_group[i]);
		}
		sort(your_gender_group.begin(), your_gender_group.end(), [](User& user1, User& user2) {return user1.Get_points() > user2.Get_points(); });
		copy(your_gender_group.begin(), your_gender_group.end(), back_inserter(top));
		if (top.size() >= 3)
		{
			cout << "Your top three partners:" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				top[i].Print();
			}
			cout << endl << endl;
		}
		Sleep(6000);
		system("cls");
		cout << "YOUR PROFILE:" << endl << endl;
		you.Print();
		cout << endl << endl;
		cout << "!!YOUR PERFECT MATCH!!" << endl << endl;
		top[0].Print();

	}
}

string Choose_interest(vector<string>& v)
{

	int k = 1;
	char en = 0;
	int n;
	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 15)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 14;
		}
		if (en == 13)
		{
			system("cls");
			if (k == 1)
			{
				return v[0];
			}
			system("cls");
			if (k == 2)
			{
				return v[1];
			}
			system("cls");
			if (k == 3)
			{
				return v[2];

			}
			system("cls");
			if (k == 4)
			{
				return v[3];

			}
			system("cls");
			if (k == 5)
			{
				return v[4];

			}
			system("cls");
			if (k == 6)
			{
				return v[5];

			}
			system("cls");
			if (k == 7)
			{
				return v[6];

			}
			system("cls");
			if (k == 8)
			{
				return v[7];

			}
			system("cls");
			if (k == 9)
			{
				return v[8];

			}
			system("cls");
			if (k == 10)
			{
				return v[9];

			}
			system("cls");
			if (k == 11)
			{
				return v[10];

			}
			system("cls");
			if (k == 12)
			{
				return v[11];

			}
			system("cls");
			if (k == 13)
			{
				return v[12];

			}
			system("cls");
			if (k == 14)
			{
				return v[13];

			}
			system("cls");
		}
		gotoxy(15, 0);
		if (k == 1)
			SetColor(13);
		gotoxy(25, 2);
		cout << "dancing" << endl;
		SetColor(7);

		if (k == 2)
			SetColor(13);
		gotoxy(25, 3);
		cout << "singing" << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(25, 4);
		cout << "cooking" << endl;
		SetColor(7);
		if (k == 4)
			SetColor(13);
		gotoxy(25, 5);
		cout << "theater" << endl;
		SetColor(7);
		if (k == 5)
			SetColor(13);
		gotoxy(25, 6);
		cout << "cinema" << endl;
		SetColor(7);
		if (k == 6)
			SetColor(13);
		gotoxy(25, 7);
		cout << "football" << endl;
		SetColor(7);
		if (k == 7)
			SetColor(13);
		gotoxy(25, 8);
		cout << "shopping" << endl;
		SetColor(7);
		if (k == 8)
			SetColor(13);
		gotoxy(25, 9);
		cout << "party" << endl;
		SetColor(7);
		if (k == 9)
			SetColor(13);
		gotoxy(25, 10);
		cout << "gym" << endl;
		SetColor(7);
		if (k == 10)
			SetColor(13);
		gotoxy(25, 11);
		cout << "fishing" << endl;
		SetColor(7);
		if (k == 11)
			SetColor(13);
		gotoxy(25, 12);
		cout << "gardening" << endl;
		SetColor(7);
		if (k == 12)
			SetColor(13);
		gotoxy(25, 13);
		cout << "yoga" << endl;
		SetColor(7);
		if (k == 13)
			SetColor(13);
		gotoxy(25, 14);
		cout << "reading" << endl;
		SetColor(7);
		if (k == 14)
			SetColor(13);
		gotoxy(25, 15);
		cout << "TV" << endl;
		SetColor(7);
	} while (en = _getch());

}

string Choose_education(vector<string>& v)
{
	int k = 1;
	char en = 0;
	int n;
	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 4)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 3;
		}
		if (en == 13)
		{
			system("cls");
			if (k == 1)
			{
				return v[0];
			}
			system("cls");
			if (k == 2)
			{
				return v[1];
			}
			system("cls");
			if (k == 3)
			{
				return v[2];

			}
			system("cls");
		}
		gotoxy(15, 0);
		if (k == 1)
			SetColor(13);
		gotoxy(25, 2);
		cout << "school" << endl;
		SetColor(7);

		if (k == 2)
			SetColor(13);
		gotoxy(25, 3);
		cout << "university " << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(25, 4);
		cout << "PhD " << endl;
		SetColor(7);
	} while (en = _getch());

}
