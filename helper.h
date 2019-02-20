#ifndef HELPER_H
#define HELPER_H
//header file for helper.c
extern char* resources;
extern const char* roomhtml;

extern int rManna;
extern int rGold;
extern int pManna;
extern int pGold;
extern int rOccupied;

void rRead();
void rWrite();
char* upper (char command[]);
void drop(int n);

#endif
