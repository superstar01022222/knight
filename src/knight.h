#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
int tiny(int &remedy,int &HP,int &phoenixdown);
int frog(int &maidenkiss,int &level,int &phoenixdown);
int is_continue(int &HP,int &phoenixdown,int &rescue);
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
bool is_prime(int n);
int to_next_prime(int &n);
int fibo(int n);
bool is_fibo(int n);
void event1( int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event2(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event3( int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event4( int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event5(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event6(int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event7( int order,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event11(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event12(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void mushtype1(int &maxi, int &mini, int length);
void mushtype2(int &mtx, int &mti, int length);
void mushtype3(int &maxi2, int &mini2, int length);
void mushtype4(int &max2_3x, int &max2_3i,int length);
void event13(int num, string pack1,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event15(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event16(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event17(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event19(string pack2,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
bool check_in_string(string s, string check);
void event18(string pack3,int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
void event99(int &HP,int &level, int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);

#endif // __KNIGHT_H__