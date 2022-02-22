
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void LOGINadmin();
void LOGINuser();
void StoringRecords();
void ShowAllRecords();
void EnterRecord(int);
void DeleteRecord(int);
void SearchRecords();
void SearchMusic();
void SearchMovies();
void SearchSeries();
void ShowRecord(int);

const int size = 64;
string Title[size] = {"Bridgerton", "House", "Parasite", "Inception", "Tightrope", "Rare"};
string Type[size] = {"Series", "Series", "Movie", "Movie", "Music", "Music"};
string Genre[size] = {"Drama", "Mystery", "Drama", "Action", "Pop", "Pop"};
string ReleaseYear[size] = {"2020", "2004", "2019", "2010", "2021", "2020"};
string Country[size] = {"USA", "USA", "USA", "UK", "USA", "USA"};
string Language[size] = {"English", "English", "English", "English", "English", "English"};
string Artist[size] = {" ", " ", " ", " ", "Zayn", "Gomez"};
string Album[size] = {" ", " ", " ", " ", "NIL", "Rare"};
string LeadingCast[size] = {"Dyenvor", "Laurie", "So-Dam", "Dicaprio", " ", " "};
string LeadingCrew[size] = {"Coughlan", "Edelstein", "Yeo-Jeong", "Murphy", " ", " "};
string Availability[size] = {"yes", "yes", "yes", "no", "yes", "no"};
string Rating[size] = {"8.3", "7.5", "7.9", "6.7", "9.8", "8.0"};

bool valid;

int main()
{
	int profile, trial = 0;
	cout << "================================================================================" << endl;
	cout << "\t\t\t ENTERTAINMENT SYSTEM" << endl;
	cout << "================================================================================" << endl
	     << endl
	     << endl
	     << endl;
	// profile type selection and validation
	cout << " SELECT PROFILE TYPE:\n\n\t(1) ADMIN\n\t(2) USER" << endl
	     << endl
	     << endl;
	cout << "Enter number to select: ";
	cin >> profile;
	while (profile != 1 && profile != 2)
	{
		cout << "\n\nERROR !   ENTER 1 FOR ADMIN AND 2 FOR USER.\n\n\tenter again: ";
		cin >> profile;
	}

	switch (profile)
	{
		// ADMIN PROFILE
		case 1:
			{

				cout << "=====================================================" << endl
				     << endl
				     << endl;
				cout << "pls enter valid login credentials below to enter as ADMIN." << endl;
				do
				{
					LOGINadmin();
					trial++;

					if (trial == 2 && valid == false)
					{
						cout << "\nLAST TRY TO ENTER VALID LOGIN CREDENTIALS.";
					}
				} while (valid == false && trial < 3);

				if (valid == false)
				{
					return 0;
				}

				StoringRecords();

				cout << "\n\n====================================================" << endl;
				break;
			}

		// USER PROFILE
		case 2:
			{

				cout << "===========================================================" << endl
				     << endl
				     << endl;
				cout << "pls enter valid login credentials below to enter as USER. " << endl;
				do
				{
					LOGINuser();
					trial++;

					if (trial == 2 && valid == false)
					{
						cout << "\nLAST TRY TO ENTER VALID LOGIN CREDENTIALS.";
					}
				} while (valid == false && trial < 3);

				if (valid == false)
				{
					return 0;
				}

				SearchRecords();

				cout << "\n\n==============================================================" << endl;
				break;
			}
	}

	return 0;
}

// functions definitions

void LOGINadmin()
{
	valid = false;
	cout << "\n\n\n\n\t\t USERNAME: ";
	string username;
	cin >> username;

	cout << "\n\t\t PASSWORD: ";
	string password;
	cin >> password;

	if (username == "admin" && password == "mcs123")
	{
		valid = true;
		cout << "\n\n\n\nACCESS GRANTED. PLEASE PROCEED." << endl;
	}
	else
	{
		cout << "\n\n ACCESS DENIED.....Invalid login credentials.";
	}
}

void LOGINuser()
{
	valid = false;
	cout << "\n\n\n\n\t\t USERNAME: ";
	string username;
	cin >> username;

	cout << "\n\t\t PASSWORD: ";
	string password;
	cin >> password;

	if (username == "user" && password == "mcs123")
	{
		valid = true;
		cout << "\n\n\tACCESS GRANTED. PLEASE PROCEED." << endl;
	}
	else
	{
		cout << "\n\n ACCESS DENIED.....Invalid login credentials.";
	}
}

void StoringRecords()
{
	char Choice;
	int count = 6;
	do
	{
		cout << "\n\n\nWhat would you like to do:\n\n\tSee (a)ll Records\n\t(S)earch for a Specific Record\n\t(E)nter a Record"
		     << "\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
		Choice = getche();
		while (Choice != 'a' && Choice != 'A' && Choice != 'e' && Choice != 'E' && Choice != 's' && Choice != 'S')
		{
			cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
			Choice = getche();
		}
		do
		{
			if (Choice == 'a' || Choice == 'A')
			{
				if (count < size)
				{
					ShowAllRecords();
					cout << "\n\nWhat would you like to do next:\n\n\t(E)nter a new Record\n\tE(x)it the Program\nEnter your choice: ";
					Choice = getche();
					while (Choice != 'e' && Choice != 'E' && Choice != 'x' && Choice != 'X')
					{
						cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
						Choice = getche();
					}
				}
				else
				{
					ShowAllRecords();
					Choice = 'X';
				}
			}
			if (Choice == 'e' || Choice == 'E')
			{
				if (count < size)
				{
					EnterRecord(count);
					++count;
					cout << "\n\nWhat would you like to do next:\n\t(E)nter another Record\n\t(D)elete previous Record"
					     << "\n\tSee (a)ll Records\n\t(S)earch for a Specific Record\n\tE(x)it the Program\nEnter your choice: ";
					Choice = getche();
					while (Choice != 'e' && Choice != 'E' && Choice != 'd' && Choice != 'D' && Choice != 'a' && Choice != 'A' && Choice != 's' && Choice != 'S' && Choice != 'x' && Choice != 'X')
					{
						cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
						Choice = getche();
					}
				}
				else
				{
					cout << "\n\n\aThe limit has been reached you cannot enter any more records.\nWhat would you like to do now:"
					     << "\n\tSee (a)ll Records\n\t(S)earch for a Specific Record\n\tE(x)it the Program\nEnter your choice: ";
					Choice = getche();
					while (Choice != 's' && Choice != 'S' && Choice != 'a' && Choice != 'A' && Choice != 'x' && Choice != 'X')
					{
						cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
						Choice = getche();
					}
				}
			}
			if (Choice == 'd' || Choice == 'D')
			{
				--count;
				DeleteRecord(count);
				cout << "\n\nWhat would you like to do next:\n\t(E)nter a new Record\n\tSee (a)ll Records\n\t(S)earch for a Specific Record\n\tE(x)it the Program\nEnter your choice: ";
				Choice = getche();
				while (Choice != 'e' && Choice != 'E' && Choice != 's' && Choice != 'S' && Choice != 'a' && Choice != 'A' && Choice != 'x' && Choice != 'X')
				{
					cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
					Choice = getche();
				}
			}
			if (Choice == 's' || Choice == 'S')
			{
				SearchRecords();
				cout << "\n\nWhat would you like to do next:\n\t(E)nter a new Record\n\tE(x)it the Program\nEnter your choice: ";
				Choice = getche();
				while (Choice != 'e' && Choice != 'E' && Choice != 'x' && Choice != 'X')
				{
					cout << "\n\t\aInvalid Choice!\nEnter the letter enclosed in brackets to\n select one of the above mentioned choices: ";
					Choice = getche();
				}
			}
		} while (Choice != 'x' && Choice != 'X');
	} while (Choice != 'x' && Choice != 'X');
}

void ShowAllRecords()
{
	if (Type[0] == "")
		cout << "\n\n\aNo records have been added yet!";
	for (int count = 0; count < size && Type[count] != ""; count++)
	{
		cout << "\n\n--------------------------------------------------";
		cout << "\n\n        Serial No.         : " << count + 1;
		cout << "\n          Title            : " << Title[count];
		cout << "\n       Content Type        : " << Type[count];
		cout << "\n          Genre            : " << Genre[count];
		cout << "\n       Release Year        : " << ReleaseYear[count];
		cout << "\n         Country           : " << Country[count];
		cout << "\n         Language          : " << Language[count];
		if (Type[count] == "Music")
		{
			cout << "\n          Artist           : " << Artist[count];
			cout << "\n          Album            : " << Album[count];
			cout << "\n  Availability of Lyrics   : " << Availability[count];
		}
		else if (Type[count] == "Movie" || Type[count] == "Series")
		{
			cout << "\n    Leading Cast Member    : " << LeadingCast[count];
			cout << "\n    Leading Crew Member    : " << LeadingCrew[count];
			cout << "\n Availability of Subtitles : " << Availability[count];
		}
		cout << "\n          Rating           : " << Rating[count] << "/10.00";
		cout << "\n----------------------------------------------------\n";
		Sleep(1000);
	}
}

void EnterRecord(int count)
{
	char Choice;
	cout << "\n\nWhat type of content would you like to add:\n\t1) Music\n\t2) Movie\n\t3) Series\nEnter your choice: ";
	do
	{
		Choice = getche();
		switch (Choice)
		{
			case '1':
				Type[count] = "Music";
				break;
			case '2':
				Type[count] = "Movie";
				break;
			case '3':
				Type[count] = "Series";
				break;
			default:
				cout << "\n\t\aInvalid Choice!\nTo select one of the above mentioned choices,\n enter its corresponding number: ";
				break;
		}
	} while (Choice != '1' && Choice != '2' && Choice != '3');
	string error;
	getline(cin, error);
	cout << "\n\nTitle: ";
	getline(cin, Title[count]);
	cout << "Genre: ";
	getline(cin, Genre[count]);
	cout << "Release Year: ";
	getline(cin, ReleaseYear[count]);
	cout << "Country: ";
	getline(cin, Country[count]);
	cout << "Language: ";
	getline(cin, Language[count]);
	switch (Choice)
	{
		case '1':
			cout << "Artist: ";
			getline(cin, Artist[count]);
			cout << "Album: ";
			getline(cin, Album[count]);
			cout << "Availability of Lyrics (Yes/No): ";
			getline(cin, Availability[count]);
			break;
		case '2':
		case '3':
			cout << "Leading Cast Member: ";
			getline(cin, LeadingCast[count]);
			cout << "Leading Crew Member: ";
			getline(cin, LeadingCrew[count]);
			cout << "Availability of Subtitles (Yes/No): ";
			getline(cin, Availability[count]);
			break;
	}
	cout << "Rating (out of 10): ";
	getline(cin, Rating[count]);
}

void DeleteRecord(int count)
{
	Title[count] = "";
	Type[count] = "";
	Genre[count] = "";
	ReleaseYear[count] = "";
	Country[count] = "";
	Language[count] = "";
	Artist[count] = "";
	Album[count] = "";
	LeadingCast[count] = "";
	LeadingCrew[count] = "";
	Availability[count] = "";
	Rating[count] = "";
}

void SearchRecords()
{
	int opt;
	do
	{
		cout << "\n\n What would you like to search for:\n\t 1) Music\n\t 2) Movies\n\t 3) T.V. Series\n\t 4) Nothing\nEnter your choice: ";
		cin >> opt;
	} while (opt > 4 || opt < 1);

	switch (opt)
	{
		case 1:
			SearchMusic();
			break;
		case 2:
			SearchMovies();
			break;
		case 3:
			SearchSeries();
			break;
		case 4:
			return;
			break;
	}
}

void SearchMusic()
{
	int MusicSearch, matchT, matchG, matchC, matchL, matchAr, matchA, matchLy, matchRD, matchR;
	string a, b, c, d, e, f, g, h, j;
	char t;
	do
	{
		do
		{
			cout << "\n\n\n What would you like to search by?\n 1) Title\n 2) Genre\n 3) Release Year\n 4) Country\n 5) Language\n 6) Rating\n 7) Artist\n 8) Album\n 9) Availability of Lyrics\nEnter your choice: ";
			cin >> MusicSearch;
			if (MusicSearch > 7 || MusicSearch < 1)
				cout << "\n\nPlease enter the number between 1 and 7" << endl;
		} while (MusicSearch > 7 || MusicSearch < 1);

		switch (MusicSearch)
		{
			case 1:
				matchT = 0;
				cout << "\n\n Please enter title of the song: ";
				cin >> a;
				for (int i = 0; i < sizeof(Title) / sizeof(Title[0]); i++)
				{

					if (Title[i] == a && Type[i] == "Music")
					{
						ShowRecord(i);
						matchT++;
					}
				}

				if (matchT == 0)
				{
					cout << "\n\nThis Title does not exist" << endl;
				}

				cout << "\n\nWould you like to search through Music again (y/n) ?" << endl;
				cin >> t;
				break;

			case 2:
				matchG = 0;
				cout << "\n\n Please enter genre of the song: ";
				cin >> b;
				for (int i = 0; i < sizeof(Genre) / sizeof(Genre[0]); i++)
				{

					if (Genre[i] == b && Type[i] == "Music")
					{
						ShowRecord(i);
						matchG++;
					}
				}
				if (matchG == 0)
				{
					cout << "\n\nSongs of this Genre do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ?" << endl;
				cin >> t;
				break;

			case 3:
				matchRD = 0;
				cout << " \n\nPlease enter Release year of the TV Series: ";
				cin >> h;
				for (int i = 0; i < sizeof(ReleaseYear) / sizeof(ReleaseYear[0]); i++)
				{

					if (ReleaseYear[i] == h && Type[i] == "Series")
					{
						ShowRecord(i);
						matchRD++;
					}
				}
				if (matchRD == 0)
				{
					cout << "\n\nShows from this Release Year do not exist" << endl;
				}
				cout << "\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 4:
				matchC = 0;
				cout << "\n\n Please enter country of the song: ";
				cin >> c;
				for (int i = 0; i < sizeof(Country) / sizeof(Country[0]); i++)
				{
					if (Country[i] == c && Type[i] == "Music")
					{
						ShowRecord(i);
						matchC++;
					}
				}

				if (matchC == 0)
				{
					cout << "\n\nSongs of this Country do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 5:
				matchL = 0;
				cout << "\n\n Please enter Language of the song: ";
				cin >> d;
				for (int i = 0; i < sizeof(Language) / sizeof(Language[0]); i++)
				{
					if (Language[i] == d && Type[i] == "Music")
					{
						ShowRecord(i);
						matchL++;
					}
				}
				if (matchL == 0)
				{
					cout << "\n\nSongs of this Language do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 6:
				matchR = 0;
				cout << "\n\nPlease enter Ratings of the movie: ";
				cin >> j;
				for (int i = 0; i < sizeof(Rating) / sizeof(Rating[0]); i++)
				{

					if (Rating[i] == j && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchR++;
					}
				}
				if (matchR == 0)
				{
					cout << "\nMovie of this Rating does not exist" << endl;
				}

				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 7:
				matchAr = 0;
				cout << "\n\n Please enter Aritst of the song: ";
				cin >> e;
				for (int i = 0; i < sizeof(Artist) / sizeof(Artist[0]); i++)
				{

					if (Artist[i] == e && Type[i] == "Music")
					{
						ShowRecord(i);
						matchAr++;
					}
				}
				if (matchAr == 0)
				{
					cout << "\n\nSongs of this artist do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 8:
				matchA = 0;
				cout << "\n\n Please enter Album of the song: ";
				cin >> f;
				for (int i = 0; i < sizeof(Album) / sizeof(Album[0]); i++)
				{

					if (Album[i] == f && Type[i] == "Music")
					{
						ShowRecord(i);
						matchA++;
					}
				}
				if (matchA == 0)
				{
					cout << "\n\nSongs from this Album do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;

			case 9:
				matchL = 0;
				cout << "\n\n Please enter if there is availability Lyrics of the song: ";
				cin >> g;
				for (int i = 0; i < sizeof(Availability) / sizeof(Availability[0]); i++)
				{

					if (Availability[i] == g && Type[i] == "Music")
					{
						ShowRecord(i);
						matchL++;
					}
				}
				if (matchL == 0)
				{
					cout << "\nNo songs exist with this availablity of lyrics" << endl;
				}
				cout << "\n\nWould you like to search through Music again (y/n) ? ";
				cin >> t;
				break;
		}
	} while (t != 'n');
	if (t == 'n')
	{
		cout << "\n\nThen ";
		SearchRecords();
	}
}

void SearchMovies()
{
	int MovieSearch, matchT, matchG, matchRD, matchC, matchL, matchR, matchD, matchP, matchS;
	string a, b, c, d, e, f, g, h, j;
	char t;

	do
	{
		do
		{
			cout << "\n\n What would you like to search by?\n 1) Title\n 2) Genre\n 3) Release Year\n 4) Country\n 5) Language\n 6) Rating\n 7) Leading Cast Member\n 8) Leading Crew Member\n 9) Availability of Subtitles\n Enter your choice: ";
			cin >> MovieSearch;
			if (MovieSearch > 9 || MovieSearch < 1)
				cout << "\nPlease enter the number between 1 and 9" << endl;
		} while (MovieSearch > 9 || MovieSearch < 1);

		switch (MovieSearch)
		{
			case 1:
				matchT = 0;
				cout << "\n\n Please enter title of the movie: ";
				cin >> a;
				for (int i = 0; i < sizeof(Title) / sizeof(Title[0]); i++)
				{

					if (Title[i] == a && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchT++;
					}
				}
				if (matchT == 0)
				{
					cout << "\nMovie Title does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 2:
				matchG = 0;
				cout << "\n\nPlease enter genre of the movie: ";
				cin >> b;
				for (int i = 0; i < sizeof(Genre) / sizeof(Genre[0]); i++)
				{

					if (Genre[i] == b && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchG++;
					}
				}
				if (matchG == 0)
				{
					cout << "\nMovie of this Genre do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 3:
				matchRD = 0;
				cout << "\n\nPlease enter Release Year of the movie: ";
				cin >> c;
				for (int i = 0; i < sizeof(ReleaseYear) / sizeof(ReleaseYear[0]); i++)
				{

					if (ReleaseYear[i] == c && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchRD++;
					}
				}
				if (matchRD == 0)
				{
					cout << "\n\nMovie of this Release Year does not exist" << endl;
				}
				cout << "\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 4:
				matchC = 0;
				cout << "\n\nPlease enter Country of the movie: ";
				cin >> d;
				for (int i = 0; i < sizeof(Country) / sizeof(Country[0]); i++)
				{

					if (Country[i] == d && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchC++;
					}
				}
				if (matchC == 0)
				{
					cout << "\nMovies of this Country does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 5:
				matchL = 0;
				cout << "\n\nPlease enter Language of the movie: ";
				cin >> e;
				for (int i = 0; i < sizeof(Language) / sizeof(Language[0]); i++)
				{

					if (Language[i] == f && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchL++;
					}
				}
				if (matchL == 0)
				{
					cout << "\n\nMovies in this Language do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 6:
				matchR = 0;
				cout << "\n\nPlease enter Ratings of the movie: ";
				cin >> f;
				for (int i = 0; i < sizeof(Rating) / sizeof(Rating[0]); i++)
				{

					if (Rating[i] == f && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchR++;
					}
				}
				if (matchR == 0)
				{
					cout << "\nMovie of this Rating does not exist" << endl;
				}

				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 7:
				matchD = 0;
				cout << "\n\n Please enter Leading Cast Member of the movie: ";
				cin >> g;
				for (int i = 0; i < sizeof(LeadingCast) / sizeof(LeadingCast[0]); i++)
				{

					if (LeadingCast[i] == g && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchD++;
					}
				}
				if (matchD == 0)
				{
					cout << "\nThis Leading Cast Member Movie does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 8:
				matchP = 0;
				cout << "\n\nPlease enter Leading Crew Member of the movie: ";
				cin >> h;
				for (int i = 0; i < sizeof(LeadingCrew) / sizeof(LeadingCrew[0]); i++)
				{

					if (LeadingCrew[i] == h && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchP++;
					}
				}
				if (matchP == 0)
				{
					cout << "\n\nMovie of this Crew does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;

			case 9:
				matchS = 0;
				cout << "\n\nPlease enter Availability of Subtitles of the movie yes/no: ";
				cin >> j;
				for (int i = 0; i < sizeof(Availability) / sizeof(Availability[0]); i++)
				{

					if (Availability[i] == j && Type[i] == "Movie")
					{
						ShowRecord(i);
						matchS++;
					}
				}
				if (matchS == 0)
				{
					cout << "\nMovies of this availaibility Subtitles do not exist" << endl;
				}
				if (matchS == 1)
				{
				}
				cout << "\n\nWould you like to search through Movies again (y/n) ? ";
				cin >> t;
				break;
		}
	} while (t != 'n');
	if (t == 'n')
	{
		cout << "\n\nThen ";
		SearchRecords();
	}
}

void SearchSeries()
{
	int ShowSearch, matchT, matchG, matchRD, matchC, matchL, matchR, matchA, matchAl, matchS;
	string a, b, c, d, e, f, g, h, j;
	char t;
	do
	{
		do
		{
			cout << "\n\n What would you like to search by?\n 1) Title\n 2) Genre\n 3) Release Year\n 4) Country\n 5) Language\n 6) Rating\n 7) Leading Cast Member\n 8) Leading Crew Member\n 9) Availability of Lyrics/Subtitles\nEnter your choice: ";
			cin >> ShowSearch;
			if (ShowSearch > 9 || ShowSearch < 1)
				cout << "\nPlease enter the number between 1 and 9" << endl;
		} while (ShowSearch > 9 || ShowSearch < 1);

		switch (ShowSearch)
		{
			case 1:
				matchT = 0;
				cout << "\n\n Please enter title of the TV Series: ";
				cin >> a;
				for (int i = 0; i < sizeof(Title) / sizeof(Title[0]); i++)
				{

					if (Title[i] == a && Type[i] == "Series")
					{
						ShowRecord(i);
						matchT++;
					}
				}
				if (matchT == 0)
				{
					cout << "\n\nShow Title does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 2:
				matchG = 0;
				cout << "\n\n Please enter genre of the TV Series: ";
				cin >> b;
				for (int i = 0; i < sizeof(Genre) / sizeof(Genre[0]); i++)
				{

					if (Genre[i] == b && Type[i] == "Series")
					{
						ShowRecord(i);
						matchG++;
					}
				}
				if (matchG == 0)
				{
					cout << "\nShow of this Genre does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 3:
				matchRD = 0;
				cout << " \n\nPlease enter Release year of the TV Series: ";
				cin >> c;
				for (int i = 0; i < sizeof(ReleaseYear) / sizeof(ReleaseYear[0]); i++)
				{

					if (ReleaseYear[i] == c && Type[i] == "Series")
					{
						ShowRecord(i);
						matchRD++;
					}
				}
				if (matchRD == 0)
				{
					cout << "\n\nShows from this Release Year do not exist" << endl;
				}
				cout << "\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 4:
				matchC = 0;
				cout << "\n\n Please enter Country of the TV Series: ";
				cin >> d;
				for (int i = 0; i < sizeof(Country) / sizeof(Country[0]); i++)
				{

					if (Country[i] == d && Type[i] == "Series")
					{
						ShowRecord(i);
						matchC++;
					}
				}
				if (matchC == 0)
				{
					cout << "\n\nShows of this Country does not exist" << endl;
				}
				cout << "\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 5:
				matchL = 0;
				cout << "\n\n Please enter Language of the TV Series: ";
				cin >> e;
				for (int i = 0; i < sizeof(Language) / sizeof(Language[0]); i++)
				{

					if (Language[i] == e && Type[i] == "Series")
					{
						ShowRecord(i);
						matchL++;
					}
				}
				if (matchL == 0)
				{
					cout << "\n\nShows in this Language do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 6:
				matchR = 0;
				cout << "\n\n Please enter Ratings of the TV Series: ";
				cin >> f;
				for (int i = 0; i < sizeof(Rating) / sizeof(Rating[0]); i++)
				{

					if (Rating[i] == f && Type[i] == "Series")
					{
						ShowRecord(i);
						matchR++;
					}
				}
				if (matchR == 0)
				{
					cout << "\n\nShow of this Rating does not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 7:
				matchA = 0;
				cout << "\n\n Please enter Leading Cast Member of the TV Series(last name): ";
				cin >> g;
				for (int i = 0; i < sizeof(LeadingCast) / sizeof(LeadingCast[0]); i++)
				{

					if (LeadingCast[i] == g && Type[i] == "Series")
					{
						ShowRecord(i);
						matchA++;
					}
				}
				if (matchA == 0)
				{
					cout << "\n\nShows of this Leading Cast Member do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 8:
				matchAl = 0;
				cout << "\n\n Please enter Leading Crew of the TV Series: ";
				cin >> h;
				for (int i = 0; i < sizeof(LeadingCrew) / sizeof(LeadingCrew[0]); i++)
				{

					if (LeadingCrew[i] == h && Type[i] == "Series")
					{
						ShowRecord(i);
						matchAl++;
					}
				}
				if (matchAl == 0)
				{
					cout << "\n\nShows of this Leading Crew Member do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;

			case 9:
				matchS = 0;
				cout << " \n\nPlease enter AVailability of Subtitles of the TV Series: ";
				cin >> j;
				for (int i = 0; i < sizeof(Availability) / sizeof(Availability[0]); i++)
				{

					if (Availability[i] == j && Type[i] == "Series")
					{
						ShowRecord(i);
						matchS++;
					}
				}
				if (matchS == 0)
				{
					cout << "\n\nShows with this availability of Subtitles do not exist" << endl;
				}
				cout << "\n\nWould you like to search through Series again (y/n) ? ";
				cin >> t;
				break;
		}
	} while (t != 'n');
	if (t == 'n')
	{
		cout << "\n\nThen ";
		SearchRecords();
	}
}

void ShowRecord(int count)
{
	cout << "\n\n####################################################";
	cout << "\n          Title            : " << Title[count];
	cout << "\n       Content Type        : " << Type[count];
	cout << "\n          Genre            : " << Genre[count];
	cout << "\n       Release Year        : " << ReleaseYear[count];
	cout << "\n         Country           : " << Country[count];
	cout << "\n         Language          : " << Language[count];
	if (Type[count] == "Music")
	{
		cout << "\n          Artist           : " << Artist[count];
		cout << "\n          Album            : " << Album[count];
		cout << "\n  Availability of Lyrics   : " << Availability[count];
	}
	else if (Type[count] == "Movie" || Type[count] == "Series")
	{
		cout << "\n    Leading Cast Member    : " << LeadingCast[count];
		cout << "\n    Leading Crew Member    : " << LeadingCrew[count];
		cout << "\n Availability of Subtitles : " << Availability[count];
	}
	cout << "\n          Rating           : " << Rating[count] << "/10.00";
	cout << "\n####################################################\n";
}
