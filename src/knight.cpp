#include "knight.h"

int r,t,k;   //temp

bool is_prime(int n)
{
	if (n == 0 || n == 1)
		return false;
	else if (n == 2)
		return true;
	else {
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
}

int to_next_prime(int &n)
{
	//cout<<n<<endl;
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

int maxHP;
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
int tempPhoenixdown = 0; 

int tiny(int &remedy,int &HP,int &phoenixdown)
{
	if (is_tiny)
	{
		if (tempPhoenixdown>phoenixdown){
			is_tiny = false;
			countdown_tiny = 0;
			return 1;
		}
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
	return 1;
}

int frog(int &maidenkiss,int &level,int &phoenixdown)
{
	if (is_frog)
	{
		if (tempPhoenixdown>phoenixdown){
			is_frog = false;
			countdown_frog = 0;
			level = prelevel;
			return 1;
		}
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
	return 1;
}

int is_continue(int &HP,int &phoenixdown,int &rescue)
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
	return 1;
}



void event1(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order ;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 10;
	k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
}

void event2(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 15;
	k = is_continue(HP,phoenixdown,rescue);	
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);

	
}

void event3(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 45;
k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
}
void event4(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 75;
k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
}
void event5(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 1);
	else if (level < levelO)
		HP -= levelO * 95;
k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
}
void event6(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	if (is_frog || is_tiny)
	{
		k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
		return;
	}
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order ;
	if (level > levelO || is_arthur || is_lancelot)
		level = min(10, level + 2);
	else if (level < levelO)
	{
		if(remedy>0){
			remedy--;
		}
		else{
			is_tiny = true;
			countdown_tiny = 3;
			HP = max(1, HP / 5);
		}
	}
k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);
	
}

void event7(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	if (is_frog || is_tiny)
	{	
		k = is_continue(HP,phoenixdown,rescue);
		r = tiny(remedy,HP,phoenixdown);
		t = frog(maidenkiss,level,phoenixdown);
		return;
	}
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order;
	if (level > levelO || is_arthur || is_lancelot)
	{
		level = min(10, level + 2);
	}
	else if (level < levelO)
	{	
		if(maidenkiss>0){
			maidenkiss--;
		}
		else{
			is_frog = true;
			countdown_frog = 3;
			prelevel = level;
			level = 1;
		}
	}

	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}

void event11(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	int n1 = ((level + phoenixdown) % 5 + 1) * 3;
	int s1 = 0;
	for (int i = 99; i >= 99 - (n1-1)*2  ; i -= 2)
	{
		s1 += i;
	}
	HP += (s1 % 100);
	to_next_prime(HP);
	HP = min(maxHP,HP);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}
void event12(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	if (HP > 1)
	{
		HP--;
		while (!is_fibo(HP))
		{
			HP--;
		}
	}k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	
}
// declare array for number sequence in MushhostPack
int a[100], aa[100];

// 4 type mushroom
void mushtype1(int &maxi, int &mini, int length)
{
	int min = 2e9;
	int max = -2e9;
	for (int i = length-1; i >=0; i--)
	{
		
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

void mushtype4(int &max2_3x, int &max2_3i, int length)
{

	max2_3x = -5;
	max2_3i = -7;
	int mx = max(max(aa[0], aa[1]), aa[2]);
	int mn = min(min(aa[0], aa[1]), aa[2]);
	
	if (length==2){
		if (mx==mn)
			return;
		else{
			max2_3x=mn;
			if(mn==aa[1])
				max2_3i = 1;
			else
				max2_3i = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (aa[i] != mx && aa[i] != mn)
		{
			max2_3x = aa[i];
			max2_3i = i;
		}
	}
}
void event13(int num, string pack1,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
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

		aa[i] = (17 * aa[i] + 9) % 257;
	}

	int m, n;
	for (auto i = 2; i < (int)ss.length() ; i++)
	{
		if (ss[i] == '1')
			mushtype1(m, n, length);
		else if (ss[i] == '2')
			mushtype2(m, n, length);
		else if (ss[i] == '3')
			mushtype3(m, n, length);
		else if (ss[i] == '4')
			mushtype4(m, n, length);
		HP = min(maxHP, HP - (m + n));
k = is_continue(HP,phoenixdown,rescue);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	
	//cout<<ss[i]<<" "<<HP<<endl;
	}
}

void event15(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	remedy = min(remedy + 1, 99);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}
void event16(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	maidenkiss = min(maidenkiss + 1, 99);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}
void event17(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	phoenixdown = min(phoenixdown + 1, 99);
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}

void event19(string pack2,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	
	ifstream file;
	file.open(pack2);
	int array[100][100];
	int x, y;
	file >> x >> y;

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			file >> array[i][j];
		}
	}
	file.close();
	//cout<<"hellơ"<<endl;
	for (int i = 0; i < x; ++i)
	{
		int take_line = 0;
		for (int j = 0; j < y; ++j)
		{
			if (take_line == 3)
				break;
			if (array[i][j] == 16)
			{
				if (remedy<99)
					remedy++;
				take_line++;
			}
			if (array[i][j] == 17)
			{
				if (maidenkiss<99)
					maidenkiss++;
				take_line++;
			}
			if (array[i][j] == 18)
			{
				if (phoenixdown<99)
					phoenixdown++;
				take_line++;
			}
		}
	}
	

	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);

	asclepius_yet = true;
	//cout<<"hello"<<endl;
}

// check a string in the string
bool check_in_string(string s, string check)
{
	if (s.find(check) != string::npos)
		return true;
	else
		return false;
}

void event18(string pack3,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{ // merlin
	const string s1 = "Merlin";
	const string s2 = "merlin";
	string name;
	ifstream file;
	file.open(pack3);
	int n;
	string name_thing[100];
	file >> n;
	getline(file,name);
	for (int i = 0; i < n; ++i)
	{
		getline(file, name_thing[i]);
	}
	file.close();

	int HP_gain = 0;
	for (int i=0; i < n; ++i)
	{
		name = name_thing[i];
		if (check_in_string(name, s1) || check_in_string(name, s2))
			HP_gain += 3;
		else if ((check_in_string(name, "m") || check_in_string(name, "M")) && (check_in_string(name, "e") || check_in_string(name, "E")) && (check_in_string(name, "r") || check_in_string(name, "R")) && (check_in_string(name, "l") || check_in_string(name, "L")) && (check_in_string(name, "i") || check_in_string(name, "I")) && (check_in_string(name, "n") || check_in_string(name, "N")))
			HP_gain += 2;
	}
	HP = min(maxHP, HP + HP_gain);
	merlin_yet = true;
	r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
}


void event99(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
	if (level == 10 || is_arthur || (is_lancelot && level >= 8))
	{
		level = 10;
		r = tiny(remedy,HP,phoenixdown);
	t = frog(maidenkiss,level,phoenixdown);;
	k = is_continue(HP,phoenixdown,rescue);
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


// read file name in line 3


void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{	
	string l1, l2, l3;
	
	rescue=-1;
	HP=0;
	level=0;
	remedy=0;
	maidenkiss=0;
	phoenixdown=0;

	ifstream file;
	file.open(file_input,ios::in);
	file >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
	getline(file, l1);
	getline(file, l2);
	getline(file, l3);
	file.close();

	//display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

	maxHP = HP;
	if (maxHP == 999)
		is_arthur = true;
	//display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
	if (is_prime(maxHP))
		is_lancelot = true;


	string pack1, pack2, pack3;
	stringstream fil(l3);
	getline(fil, pack1, ',');
	getline(fil, pack2, ',');
	getline(fil, pack3, ',');

	
	int order = 1;
	long int num, numTest;
	l2 += "120";
	//cout<<l2<<endl;
	auto l5 = l2;
	stringstream event(l2);
	stringstream eventk(l5);
	//cout<<"hello"<<endl;	
	event>>num;
	eventk>>numTest;
	while (rescue == -1)
	{
		//cout<<num<<endl;
		eventk>>numTest;
		tempPhoenixdown=phoenixdown;
		if (num == 1)
		{
			event1(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 2)
		{
			event2(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 3)
		{
			event3(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 4)
		{
			event4(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 5)
		{
			event5(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 6)
		{
			event6(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 7)
		{
			event7(order,HP,level, remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 11)
		{
			event11(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 12)
		{
			event12(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}

		if (num == 15)
		{
			event15(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 16)
		{
			event16(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 17)
		{
			event17(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 18 && !merlin_yet)
		{
			event18(pack3,HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (num == 19 && !asclepius_yet)
		{
			event19(pack2,HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}

		if (num == 0)
		{
			rescue = 1;
		}
		if (num == 99)
		{
			event99(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
	
		if (num > 130)
		{
			event13(num, pack1,HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
		if (numTest == 120)
		{
			rescue = 1;
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
			break;
		}
		if (rescue == 1 || rescue == 0)
		{
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
		}
		else
		{
			display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
			order++;
		}
		event>>num;
	}
}