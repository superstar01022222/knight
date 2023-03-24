#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void tiny();
void frog();
void is_continue();
void end_event();

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
bool is_prime(int n);
int to_next_prime(int n);
int fibo(int n);
bool is_fibo(int n);
void event1( int order);
void event2( int order);
void event3( int order);
void event4( int order);
void event5( int order);
void event6( int order);
void event7( int order);
void event11();
void event12();
void mushtype1(int &maxi, int &mini, int length);
void mushtype2(int &mtx, int &mti, int length);
void mushtype3(int &maxi2, int &mini2, int length);
void mushtype4(int &max2_3x, int &max2_3i);
void event13( int num, string pack1);
void event15();
void event16();
void event17();
void event19( string pack2);
bool check_in_string(string s, string check);
void event18( string pack3);
void event99();
void read_input(string a, string l1, string l2, string l3);
void read_pack(string pack1, string pack2, string pack3, string line3);




#endif // __KNIGHT_H__