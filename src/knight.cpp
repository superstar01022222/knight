#include "knight.h"

bool is_prime(int n)
{
	if (n == 0 || n == 1)
		return false;
	if (n == 2)
		return true;
	for (unsigned int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int to_next_prime(int n)
{
	n++;
	while (!is_prime(n))
	{
		n++;
	}
	return n;
}

int fibo(int n)
{
	int fibo[50];
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return fibo[n];
}

bool is_fibo(int n)
{
	int i = 0;
	while (fibo(i) < n)
	{
		i++;
	}
	if (n == fibo(i + 1) || n == fibo(i))
		return true;
	else
		return false;
}

int maxHP, HP, level, remedy, maidenkiss, phoenixdown;
bool is_tiny = false;
int countdown_tiny = 0;
bool is_frog = false;
int countdown_frog = 0;
int prelevel;
int rescue = -1;
bool merlin_yet = false;
bool asclepius_yet = false;
bool is_arthur = false;
bool is_lancelot = false;

void tiny()
{
	if (is_tiny)
	{
		if (remedy > 0)
		{
			HP = min(maxHP, HP * 5);
			is_tiny = false;
			countdown_tiny = 0;
			remedy--;
		}
		else if (countdown_tiny == 1)
		{
			is_tiny = false;
			HP = min(maxHP, HP * 5);
			countdown_tiny = 0;
		}
		else
			countdown_tiny--;
	}
}

void frog()
{
	if (is_frog)
	{
		if (maidenkiss)
		{
			is_frog = false;
			countdown_frog = 0;
			level = prelevel;
		}
		else if (countdown_frog == 1)
		{
			is_frog = false;
			level = prelevel;
			countdown_frog = 0;
		}
		else
			countdown_frog--;
	}
}

void is_continue()
{
	if (HP <= 0 && phoenixdown)
	{
		HP = maxHP;
		phoenixdown--;
		rescue = -1;
	}
	else if (HP <= 0 && phoenixdown == 0)
	{
		rescue = 0;
	}
	else
		rescue = -1;
}

tiny();
frog();
is_continue();

void event1(int order)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 10;

	tiny();
	frog();
	is_continue();
}

void event2(int order)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 15;
	tiny();
	frog();
	is_continue();
}

void event3(int order)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 45;

	tiny();
	frog();
	is_continue();
}
void event4(int order)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 75;

	tiny();
	frog();
	is_continue();
}
void event5(int order)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 95;

	tiny();
	frog();
	is_continue();
}
void event6(int order)
{
	if (is_frog || is_tiny)
	{
		tiny();
		frog();
		is_continue();
		return;
	}
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 2);
	else if (level < levelO)
	{
		is_tiny = true;
		countdown_tiny = 3;
		HP = max(1, HP / 5);
	}

	tiny();
	frog();
	is_continue();
}

void event7(int order)
{
	if (is_frog || is_tiny)
	{
		tiny();
		frog();
		is_continue();
		return;
	}
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (level > levelO)
	{
		level = min(10, level + 2);
	}
	else if (level < levelO || is_arthur || is_lancelot)
	{
		is_frog = true;
		countdown_frog = 3;
		prelevel = level;
		level = 1;
	}

	tiny();
	frog();
	is_continue();
}

void event11()
{
	int n1 = ((level + phoenixdown) % 5 + 1) * 3;
	int s1 = 0;
	for (int i = 99; i >= 1 && n1 > 0; i -= 2)
	{
		s1 += i;
		n1--;
	}
	HP += (s1 % 100);
	HP = min(HP, to_next_prime(HP));
	tiny();
	frog();
	is_continue();
}
void event12()
{
	if (HP > 1)
	{
		HP--;
		while (!is_fibo(HP))
		{
			HP--;
		}
	}
	tiny();
	frog();
	is_continue();
}
// declare array for number sequence in MushhostPack
int a[100], aa[100];

// 4 type mushroom
void mushtype1(int &maxi, int &mini, int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = 2e9;
		int max = -2e9;
		if (a[i] > max)
		{
			max = a[i];
			maxi = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			mini = i;
		}
	}
}

void mushtype2(int &mtx, int &mti, int length)
{
	;
	mtx = -2;
	mti = -3;
	int begin = 0;
	int end = length - 1;
	while (a[begin] < a[begin + 1])
		begin++;
	while (a[end] < a[end - 1])
		end--;
	if (begin == end)
	{
		mtx = a[begin];
		mti = begin;
	}
}
void mushtype3(int &maxi2, int &mini2, int length)
{

	int max = -2e9, min = 2e9;
	for (int i = 0; i < length; i++)
	{
		if (aa[i] > max)
		{
			max = aa[i];
			maxi2 = i;
		}
		if (aa[i] < min)
		{
			min = aa[i];
			mini2 = i;
		}
	}
}

void mushtype4(int &max2_3x, int &max2_3i)
{

	max2_3x = -5;
	max2_3i = -7;
	int mx = max(max(aa[0], aa[1]), aa[2]);
	int mn = min(min(aa[0], aa[1]), aa[2]);
	for (int i = 0; i < 3; i++)
	{
		if (aa[i] != mx && aa[i] != mn)
		{
			max2_3x = aa[i];
			max2_3i = i;
		}
	}
}
void event13(int num, string pack1)
{
	// read file mush ghost
	string ss = to_string(num);
	ifstream file;
	int length;
	file.open(pack1);
	file >> length;
	string num_line;
	getline(file, num_line);
	getline(file, num_line);
	stringstream input(num_line);

	for (int i = 0; i < length; ++i)
	{
		string num_store;
		if (getline(input, num_store, ','))
		{
			a[i] = stoi(num_store);
		}
	}
	file.close();
	// transform number into the new one

	for (int i = 0; i < length; ++i)
	{
		if (a[i] < 0)
		{
			aa[i] = -a[i];
		}
		else
		{
			aa[i] = a[i];
		}

		aa[i] = (17 * a[i] + 9) % 257;
	}

	int m, n;
	for (int i = 2; i < ss.length() - 1; i++)
	{
		if (ss[i] == '1')
			mushtype1(m, n, length);
		else if (ss[i] == '2')
			mushtype2(m, n, length);
		else if (ss[i] == '3')
			mushtype3(m, n, length);
		else if (ss[i] == '4')
			mushtype4(m, n);
		HP = min(maxHP, HP - (m + n));

		tiny();
		frog();
		is_continue();
	}
}

void event15()
{
	remedy = min(remedy + 1, 99);
	tiny();
	frog();
	is_continue();
}
void event16()
{
	maidenkiss = min(maidenkiss + 1, 99);
	tiny();
	frog();
	is_continue();
}
void event17()
{
	phoenixdown = min(phoenixdown + 1, 99);
	tiny();
	frog();
	is_continue();
}

void event19(string pack2)
{
	ifstream file;
	file.open(pack2);
	int array[100][100];
	int x, y;
	file >> x >> y;
	for (int i = 0; i < x; ++i)
	{
		for (int j; i < y; ++j)
		{
			file >> array[i][j];
		}
	}
	file.close();
	for (int i = 0; i < x; ++i)
	{
		int take_line = 0;
		for (int j = 0; i < y && take_line < 3; ++i)
		{
			if (array[i][j] == 15)
			{
				remedy++;
				take_line++;
				if (array[i][j] == 16)
				{
					maidenkiss++;
					take_line++;
				}
				if (array[i][j] == 17)
				{
					phoenixdown++;
					take_line++;
				}
			}
		}
	}

	tiny();
	frog();
	is_continue();
	asclepius_yet = true;
}

// check a string in the string
bool check_in_string(string s, string check)
{
	if (s.find(check) != string::npos)
		return true;
	else
		return false;
}

void event18(string pack3)
{ // merlin
	const string s1 = "Merlin";
	const string s2 = "merlin";
	ifstream file;
	file.open(pack3);
	int n;
	string name_thing[100];
	file >> n;
	for (int i = 0; i < n; ++i)
	{
		getline(file, name_thing[i]);
	}
	file.close();

	int HP_gain = 0;
	for (int i; i < n; ++i)
	{
		string name = name_thing[i];
		if (check_in_string(name, s1) || check_in_string(name, s2))
			HP_gain += 3;
		else if ((check_in_string(name, "m") || check_in_string(name, "M")) && (check_in_string(name, "e") || check_in_string(name, "E")) && (check_in_string(name, "r") || check_in_string(name, "R")) && (check_in_string(name, "l") || check_in_string(name, "L")) && (check_in_string(name, "i") || check_in_string(name, "I")) && (check_in_string(name, "n") || check_in_string(name, "N")))
			HP_gain += 2;
	}
	HP = min(maxHP, HP + HP_gain);
	merlin_yet = true;
	tiny();
	frog();
	is_continue();
}

void event99()
{
	if (level == 10 || is_arthur || (is_lancelot && level >= 8))
	{
		level = 10;
		tiny();
		frog();
		is_continue();
	}
	else
		rescue = 0;
}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
	cout << "HP=" << HP
		 << ", level=" << level
		 << ", remedy=" << remedy
		 << ", maidenkiss=" << maidenkiss
		 << ", phoenixdown=" << phoenixdown
		 << ", rescue=" << rescue << endl;
}
// function read data
void read_input(string a, string l1, string l2, string l3)
{
	ifstream file;
	file.open(a);
	getline(file, l1);
	getline(file, l2);
	getline(file, l3);
	file.close();
}

// read file name in line 3
void read_pack(string pack1, string pack2, string pack3, string line3)
{
	stringstream file(line3);
	getline(file, pack1, ',');
	getline(file, pack2, ',');
	getline(file, pack3, ',');
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
	string l1, l2, l3;
	read_input(file_input, l1, l2, l3);
	stringstream info(l1);
	info >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
	maxHP = HP;
	if (maxHP == 999)
		is_arthur = true;

	if (is_prime(maxHP))
		is_lancelot = true;
	string pack1, pack2, pack3;
	read_pack(pack1, pack2, pack3, l3);

	int order = 1;
	long int num;
	l2 += " -1";
	stringstream event(l2);

	while (event >> num && rescue == -1)
	{
		if (num == 1)
		{
			event1(order);
		}
		if (num == 2)
		{
			event2(order);
		}
		if (num == 3)
		{
			event3(order);
		}
		if (num == 4)
		{
			event4(order);
		}
		if (num == 5)
		{
			event5(order);
		}
		if (num == 6)
		{
			event6(order);
		}
		if (num == 7)
		{
			event7(order);
		}
		if (num == 11)
		{
			event11();
		}
		if (num == 12)
		{
			event12();
		}

		if (num == 15)
		{
			event15();
		}
		if (num == 16)
		{
			event16();
		}
		if (num == 17)
		{
			event17();
		}
		if (num == 18 && !merlin_yet)
		{
			event18(pack3);
		}
		if (num == 19 && !asclepius_yet)
		{
			event19(pack2);
		}

		if (num == 0)
		{
			rescue = 1;
		}
		if (num == 99)
		{
			event99();
		}
		if (num == -1)
		{
			rescue = 1;
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
			break;
		}
		if (num > 130)
		{
			event13(num, pack1);
		}

		if (rescue == 1 || rescue == 0)
		{
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
			break;
		}

		else
		{
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
			order++;
		}
	}
}
