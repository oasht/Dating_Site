#include "Header.h"

void main()
{
	bool b;
	string id, city, edu, interest, wish_city, wish_edu, wish_interest, age_tmp;
	char gender, wish_gender;
	int age, age_from, age_to;
	vector<string>interests, wish_interests;
	vector<User>top;
	vector<User>your_gender_group;
	vector<string>interests_choice{ "dancing", "singing", "cooking", "theater","cinema", "football", "shopping", "party", "gym", "fishing", "gardening", "yoga", "reading", "TV" };
	vector<string>education{ "school", "university", "phd" };
	vector<User>users
	{
		User("bdjhfb1", 'M', 35, "Moscow", "School",{"hockey", "table games", "fishing", "video games"}, 'F', 18, 30, "Moscow","University", {"dancing", "cooking", "theater"}),
		User("nfvf45", 'M', 43, "Kaliningrad", "University", {"football", "cinema", "cooking"}, 'F', 30, 40, "Moscow", "School", {"singing", "cinema"}),
		User("kjfvn56", 'M', 22, "Saint-Petersburg","University", {"shopping", "party", "gym"}, 'M', 18, 50, "Moscow", "", {"shopping", "party"}),
		User("jjnvkj777", 'M', 56, "Krasnoyarsk", "PhD", {"fishing", "gardening", "yoga"}, 'F', 40, 50, "Krasnoyarsk", "University",{"gardening", "travelling", "yoga"}),
		User("jnrknrf8587", 'M', 33, "Moscow", "University", {"yachting", "polo", "golf"}, 'F', 18, 25, "Moscow", "University", {"reading", "dancing", "yoga", "art"}),
		User("fcsfc473", 'M', 28, "Anapa", "School", {"swimming", "TV"}, 'F', 18, 20, "Anapa", "School", {}),
		User("rfrknr75475", 'M', 65, "Moscow", "University", {"reading", "cycling", "running"}, 'F', 30, 60, "Moscow", "University", {"running"}),
		User("nfj56", 'M', 44, "Krasnoyarsk", "School", {"TV"}, 'F', 18, 18, "Krasnoyarsk", "School", {"cooking"}),
		User("kflu354", 'M', 32, "Kaliningrad", "PhD", {"reading", "fishing", "hunting"}, 'F', 18, 30, "Moscow", "University", {"reading", "yoga"}),
		User("ndkdm34", 'M', 55, "Sochi", "School", {"swimming", "running", "reading"}, 'F', 25, 50, "Sochi", "University", {"running", "cooking"}),
		User("njnrn33", 'F', 18, "Moscow", "School", {"dancing", "yoga"}, 'M', 18, 30, "Moscow", "University", {"swimming", "reading"}),
		User("ashdf76", 'F', 43, "Anapa", "University", {"knitting", "cooking"}, 'M', 18, 60, "Anapa", "School", {"hunting"}),
		User("jnekjnrf33", 'F', 22, "Kaliningrad", "University", {"reading", "party"}, 'F', 18, 30, "Moscow", "University", {"party"}),
		User("ajfur88", 'F', 65, "Saint-Petersburg", "Phd", {"reading", "swimming", "gardening"}, 'M', 60, 65, "Saint-Petersburg", "Phd", {"gardening"}),
		User("kjrenfkr858", 'F',77, "Moscow", "University", {"reading", "gardening"}, 'M', 60, 70, "Moscow", "University", {"yoga"}),
		User("nrjnfr99", 'F', 33, "Sochi", "University", {"TV", "table games"}, 'M', 40, 45, "Sochi", "University", {"reading", "cooking"}),
		User("jdjdj33", 'F', 30, "Krasnoyarsk", "School", {"TV", "party"}, 'M', 30, 35, "Moscow", "University", {"party", "sport"}),
		User("jrjre2", 'F',40, "Moscow", "PhD", {"reading", "cooking", "poetry"}, 'M', 40, 60, "Moscow", "PhD", {"reading", "yoga"}),
		User("orjnf55", 'F', 28, "Sochi", "School", {"dancing", "swimming", "yoga"}, 'M', 30, 40, "Sochi", "University", {"party", "yoga"}),
		User("hhssih43", 'F', 21, "Anapa", "School", {"swimming", "cooking"}, 'M', 20, 30, "Anapa", "School", {"swimming", "hiking", "hunting"})
	};

	FILE* f_users{ nullptr };

	//fopen_s(&f_users, "users.txt", "w");
 // if (!f_users)cout << "Error" << endl;
 // else  
 // {
 //     for (int i = 0; i < users1.size(); i++)
 //     {
 //         fwrite(&users1[i], sizeof(User), 1, f_users);
 //     }   
 // 
 //     fclose(f_users);
 // }
	//

	//reading from file

	//fopen_s(&f_users, "users.txt", "r");
	//if (!f_users)
	//{
	//	cout << "Error " << endl;
	//}
	//else
	//{
	//	
	//	while (!feof(f_users))
	//	{
	//		User us1;
	//		fread(&us1, sizeof(User), 1, f_users);
	//		users.push_back(us1);
	//	}
	//	
	//	fclose(f_users);
	//}


	do
	{
		b = 0;
		system("cls");
		cout << "Please enter your user name" << endl << endl;
		cin >> id;
		transform(id.begin(), id.end(), id.begin(), tolower);

		for (int i = 0; i < users.size(); i++)
		{
			if (id == users[i].Get_id())
				b = 1;
		}

		try
		{
			if (b)
				throw exception("This id already exists");


		}

		catch (exception& str)
		{
			cout << str.what() << endl;
		}
		Sleep(1500);
	} while (b == 1);
	do
	{
		b = 0;
		system("cls");
		cout << "Please enter your gender - F or M" << endl << endl;
		cin >> gender;
		if (gender == 'f') { gender = 'F'; }
		if (gender == 'm') { gender = 'M'; }
		if (gender != 'F' && gender != 'M')
		{
			b = 1;
		}
		try
		{
			if (b)
				throw exception("Incorrect data");
		}

		catch (exception& str)
		{
			cout << str.what() << endl;
		}
		Sleep(1500);
	} while (b == 1);
	do
	{
		b = 0;
		system("cls");
		cout << "Please enter your age" << endl << endl;
		cin >> age_tmp;
		age = atoi(age_tmp.c_str());
		if (age == 0 || age < 0 || age>100)
			b = 1;
		try
		{
			if (b)
				throw exception("Incorrect data");
		}

		catch (exception& str)
		{
			cout << str.what() << endl;
		}
		Sleep(1500);
	} while (b == 1);


	system("cls");
	cout << "Please enter your city" << endl << endl;
	cin >> city;
	transform(city.begin(), city.end(), city.begin(), tolower);


	system("cls");
	cout << "Please enter your education" << endl;
	Sleep(3000);
	system("cls");
	edu = Choose_education(education);


	system("cls");
	cout << "Please enter your interests" << endl; Sleep(3000);
	bool q;
	do
	{
		system("cls");
		q = 0;
		interest = Choose_interest(interests_choice);
		interests.push_back(interest);
		cout << "Add one more? 1 - yes, 0 - no" << endl << endl;
		cin >> q;
	} while (q == 1);

	system("cls");
	sort(interests.begin(), interests.end());
	auto it = unique(interests.begin(), interests.end());
	interests.erase(it, interests.end());




	do
	{
		b = 0;
		system("cls");
		cout << "Please enter your partner preferable gender - F or M" << endl << endl;
		cin >> wish_gender;
		if (wish_gender == 'f')wish_gender = 'F';
		if (wish_gender == 'm')wish_gender = 'M';
		if (wish_gender != 'F' && wish_gender != 'M')
		{
			b = 1;
		}
		try
		{
			if (b)
				throw exception("Incorrect data");
		}

		catch (exception& str)
		{
			cout << str.what() << endl;
		}
		Sleep(1500);
	} while (b == 1);


	do
	{
		b = 0;
		system("cls");
		cout << "Please set the lower age boundary for your partner" << endl << endl;
		cin >> age_tmp;
		age_from = atoi(age_tmp.c_str());
		system("cls");
		cout << "Please set the upper age bound for your partner" << endl << endl;
		cin >> age_tmp;
		age_to = atoi(age_tmp.c_str());
		if (age_from == 0 || age_from < 0 || age_from>100)
			b = 1;
		if (age_to == 0 || age_to < 0 || age_to>100)
			b = 1;
		if (age_from > age_to)
			b = 1;
		try
		{
			if (b)
				throw exception("Incorrect data");
		}

		catch (exception& str)
		{
			cout << str.what() << endl;
		}
		Sleep(1500);
	} while (b == 1);


	system("cls");
	cout << "Please enter the city you want to find your partner at" << endl << endl;
	cin >> wish_city;
	transform(wish_city.begin(), wish_city.end(), wish_city.begin(), tolower);


	system("cls");
	cout << "Please enter your partner's preferable education" << endl;
	Sleep(3000);
	system("cls");
	wish_edu = Choose_education(education);

	system("cls");
	cout << "Please enter your partner's interests" << endl; Sleep(3000);
	do
	{
		q = 0;
		system("cls");
		wish_interest = Choose_interest(interests_choice);
		wish_interests.push_back(wish_interest);
		cout << "Add one more? 1 - yes, 0 - no" << endl << endl;
		cin >> q;
	} while (q == 1);

	system("cls");
	sort(wish_interests.begin(), wish_interests.end());
	auto it1 = unique(wish_interests.begin(), wish_interests.end());
	wish_interests.erase(it1, wish_interests.end());


	User you(id, gender, age, city, edu, interests, wish_gender, age_from, age_to, wish_city, wish_edu, wish_interests);
	Final_result(you, users, your_gender_group, top, interests);


}