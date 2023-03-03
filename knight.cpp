#include "knight.h"

void work_data(){
	ifstream file;
	file.open(file_input);
	string line1, line2, line3;
	getline(file, line1);
	getline(file, line2);
	getline(file, line3);
	file.close();
}

bool isPrime(int n){
	if (n==0||n==1) return false;
	if (n==2) return true;
	for (unsigned int i=2; i<0; i++){
		if (n%2==0) return false;		
	}
	return true;
}
int nextprime(int n){
	n++;
	while (!isPrime(n)){
		n++;
	}
	return n;
}

int fibonacci(int n){
	int fibo[50];
	fibo[0]=1; 
	fibo[1]=1;
	for (int i=2; i<n; i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	return fibo[n-1];
}

bool check_fibo(int n){
	int i=0;
	while(fibonacci(i)<n){
		i++;
	}
	if (n==fibonacci(i+1)||n==fibonacci(i)) return true;
	else return false;
}

struct knight{
	int maxHP, HP, level, remedy, maidenkiss, phoenixdown;
	void info(string s){
		stringstream first_data(s);
		first_data>>HP>>level>>remedy>>maidenkiss>>phoenixdown;
		maxHP=HP;
	}
	bool is_tiny;
	int time_tiny;
	bool is_frog;
	int time_frog;
	int prelevel;
	int rescue;
	bool merlin=false;
	bool asclepius=false;
	bool is_arthur;
	bool is_lancelot;
	void tiny(){
	if (is_tiny){
		if (remedy){
			HP=min(maxHP,HP*5);
			is_tiny=false;
			time_tiny=0;
			remedy--;
		}
		else if (time_tiny==1){
			is_tiny=false;
			HP=min(maxHP,HP*5);
			time_tiny=0;	
		}
		else time_tiny--;
	}
	}
	void frog(){
	if (is_frog){
		if (maidenkiss){
			is_frog=false;
			time_frog=0;
			level=prelevel;
		}
		else if (time_frog==1){
			is_frog=false;
			level=prelevel;
			time_frog=0;
		}
		else time_frog--;
	}
	}
	void end_event(){
		tiny();
		frog();
		if (HP<=0&&phoenixdown){
			HP=maxHP;
			phoenixdown--;
			rescue=-1;
		}
		else if (HP<=0&&phoenixdown==0){
			rescue=0;
		}
		else if(HP>0 )rescue=-1;
	}
	} knight;


void event1(knight& knight, int order){
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+1);
		else if (knight.level<levelO){
			knight.HP-=levelO*10;
		}
	}
	knight.end_event();
}

void event2(knight& knight, int order){
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+1);
		else if (knight.level<levelO){
			knight.HP-=levelO*15;
		}
	}
	knight.end_event();
}
void event3(knight& knight, int order){
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+1);
		else if (knight.level<levelO){
			knight.HP-=levelO*45;
		}
	}
	knight.end_event();
}
void event4(knight& knight, int order){
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+1);
		else if (knight.level<levelO){
			knight.HP-=levelO*75;
		}
	}
	knight.end_event();
}
void event5(knight& knight, int order){
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+1);
		else if (knight.level<levelO){
			knight.HP-=levelO*95;
		}
	}
	knight.end_event();
}
void event6(knight& knight, int order){
	if (knight.is_frog||knight.is_tiny){
		knight.end_event();
		return;
	}
	int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO||knight.is_arthur||knight.is_lancelot){
		knight.level=min(10, knight.level+2);
		else if (knight.level<levelO){
			knight.is_tiny=true;
			knight.time_tiny=3;
			knight.HP=max(1,knight/5);
		}
	}
	knight.end_event();	
}
void event7(knight& knight, int order){
	if (knight.check_frog||knight.check_tiny){
		knight.end_event();
		return;
		int levelO = order > 6 ? (order % 10 > 5 ? order % 10 : 5) : order % 10;
	if (knight.level>levelO){
		knight.level=min(10, knight.level+2);
		else if (knight.level<levelO||knight.is_arthur||knight.is_lancelot){
			knight.is_frog=true;
			knight.time_frog=3;
			knight.prelevel=knight.level;
			knight.level=1;
		}
	}
	knight.end_event()
}
}
void event11(knight& knight){
	int n1 = ((knight.level + knight.phoenixdown)%5 + 1)*3;
	int s1=0;
	for (int i=99; i>=1 && n1>0; i-=2 ){
		s1+=i;
		n1--;
	}
	knight.HP+=(s1%100);
	knight.HP=min(knight.HP,nextprime(knight.HP));
	knight.end_event();
}
void event12(knight& knight){
	if (knight.HP>1){
		knight.HP--;
		while (!check_fibo(knight.HP)){
			knight.HP--;
		}
	}
	knight.end_event();
}
void event13(knight& knight, int n) {
    string ss = to_string(n);
    mushghost.data_mushghost(file_mush_ghost);
    mushghost.transform();
    int x, y;
    for (int i = 2; i < ss.length() - 1; i++) {
        if (ss[i] == '1') mushghost.mushtype1(x, y);
        else if (ss[i] == '2') mushghost.mushtype2(x, y);
        else if (ss[i] == '3') mushghost.mushtype3(x, y);
        else if (ss[i] == '4') mushghost.mushtype4(x, y);
        knight.HP = min(knight.maxHP, knight.HP - (x + y));
        if (knight.HP <= 0 && knight.phoenixdown > 0) {
            knight.HP = knight.maxHP;
            knight.phoenixdown--;
            knight.is_tiny = false;
            knight.time_tiny = 0;
        } else if (knight.HP <= 0 && knight.phoenixdown == 0) {
            knight.rescue = 0;
            return;
        }
    }
    knight.end_event();
}

void evennt15(knight& knight){
	knight.remedy=min(knight.remedy+1,99);
	knight.end_event();
}
void event16(knight& knight){
	knight.maidenkiss=min(knight.maidenkiss+1,99);
	knight.end_event();
}
void event17(knight& knight){
	knight.phoenixdown=min(knight.phoenixdown+1,99);
	knight.end_event();
}

void event19(knight& knight){
	ifstream file;
	file.open(file_asclepius_pack);
	int array[100][100];
	int x,y;
	file>>x>>y;
	for (int i=0; i<x;++i){
		for (int j;i<y;++j){
			file>>array[i][j];
		}
	}
	file.close();
	for (int i=0; i<x;++i){
		int take_line=0;
		for (int j=0; i<y && take_line<3 ;++i){
			if (array[i][j]==15){
				knight.remedy++;
				take_line++;
			if (array[i][j]==16){
				knight.maidenkiss++;
				take_line++;
			}
			if (array[i][j]==17){
				knight.phoenixdown++;
				take_line++;
			}
			}
		}
	}
	
	knight.end_event();
	knight.asclepius=true; 
	
}

bool check_in_string(string s, string check){
	if (s.find(check) != string::npos) return true; 
	else  return false;
}


void event18(knight& knight){  //merlin 
	const string s1="Merlin";
	const string s2="merlin";
	ifstream file;
	file.open(file_merlin_pack);
	int n;
	string name_thing[100];
	file>>n;
	for (int i=0; i<n;++i){
		file>>name_thing[i];
	}
	file.close();
	
	int HP_gain=0;
	for (int i; i<n; ++i){
		string name_thing=name_thing[i];
		if (check_in_string(name_thing,s1)||check_in_string(name_thing,s2)) HP_gain+=3;
		if else ((check_in_string(name_thing,"m")||check_in_string(name_thing,"M"))&&(check_in_string(name_thing,"e")||check_in_string(name_thing,"E"))&&(check_in_string(name_thing,"r")||check_in_string(name_thing,"R"))&&(check_in_string(name_thing,"l")||check_in_string(name_thing,"L"))&&(check_in_string(name_thing,"i")||check_in_string(name_thing,"I"))&&(check_in_string(name_thing,"n")||check_in_string(name_thing,"N"))) 
				HP_gain+=2;
		}
	knight.HP=min(knight.maxHP,knight.HP+HP_gain);
	knight.end_event();
	knight.merlin=true;
	}



struct mushghost{
	void data_mushghost(){
		ifstream file;
		int n;
		file.open(file_mush_ghost);
		file>>n;
		string sqnum;
		getline(file,sqnum);getline(file,sqnum);
		stringstream num_mushghost(sqnum);
		int arr[100];
    	for (int i = 0; i < n; ++i) {
        string num_str;
        if (getline(num_mushghost, num_str, ',')) {
            arr[i] = stoi(num_str);
        }
    }
    file.close()
	}
	void transform(){
		data_mushghost();
		int trans[100];
    	for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            trans[i] = -arr[i];
        } else {
            trans[i] = arr[i];
        }

        trans[i] = (17 * trans[i] + 9) % 257;

        if (arr[i] < 0) {
            trans[i] = -trans[i];
        }
    }
	}
	void mushtype1(int &maxi, int &mini) {
		data_mushghost();
    	int mx=-2e9, mn=2e9;
    	for (int i = 0; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            maxi = i;
        }
        if (arr[i] < mn) {
            mn = arr[i];
            mini = i;
        }
    }  
}

	void mushtype2(int &mtx, int &mti){
		data_mushghost();
		mtx=-2;
		mti=-3;
		int begin=0;
		int end=n-1;
		while (arr[begin]<arr[begin+1]) begin++;
		while (arr[end]<arr[end-1]) end--;
		if (begin==end){
			mtx=arr[begin];
			mti=begin;
		}
	}
	void mushtype3(int &maxi2, int &mini2){
	transform();
	int mx=-2e9, mn=2e9;
    	for (int i = 0; i < n; i++) {
        if (trans[i] > mx) {
            mx = trans[i];
            maxi2 = i;
        }
        if (trans[i] < mn) {
            mn = trans[i];
            mini2 = i;
        }
    }  	
	}
	
	void mushtype4(int &max2_3x, int &max2_3i){
	transform();
	max2_3x=-5; 
	max2_3i=-7;
	int mx=max(max(trans[0],trans[1]),trans[2]);
	int mn=min(min(trans[0],trans[1]),trans[2]);
	for (int i=0; i<3; i++){
		if (trans[i]!=mx&&trans[i]!=mn){
			max2_3x=trans[i];
			max2_3i=i;
		}
	}
	}
	
};

void event99(knight& knight){
	if(knight.level==10||knight.is_arthur||(knight.is_lancelot&&knight.level>=8)){
		knight.level=10;
		knight.end_event();
	}
	else knight.rescue=0;
}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    knight knight;
	work_data();
	knight.info();
	if (knight.maxHP==999) knight.is_arthur=true;
	else knight.is_arthur=false;
	if (isPrime(knight.maxHP)) knight.lancelot=true;
	else knight.lancelot=false;
	stringstream event(line2);
	int order=1;
	int num;


while (event>>num) {
    if (num == 1) {
        event1(knight, order);
    }
    else if (num == 2) {
        event2(knight, order);
    }
    else if (num == 3) {
        event3(knight, order);
    }
    else if (num == 4) {
        event4(knight, order);
    }
    else if (num == 5) {
        event5(knight, order);
    }
    else if (num == 6) {
        event6(knight, order);
    }
    else if (num == 7) {
        event7(knight, order);
    } 
    else if (num == 11) {
        event11(knight);
    }
    else if (num == 12) {
        event12(knight);
    }
    
    else if (num == 15) {
        evennt15(knight);
    }
    else if (num == 16) {
        event16(knight);
    }
    else if (num == 17) {
        event17(knight);
    }
    else if (num == 18&&!knight.merlin) {
        event18(knight);
    }
    else if (num == 19&&!knight.asclepius){
        event19(knight);
    }
	
	else if (num==0){
		rescue=1;
	}
	else if (num==99){
		event99(knight);
	}
	else if (num>130){
		event13(knight,num);
	}
    

	if(rescue==1||rescue==0){
		display(knight);
		break;
	}
	else {
		display(knight);
		order++;
	}


    
}
}

	
	
