#ifdef MECHANICS_H
#define MECHANICS_H

#include "user.h"

void levelUp(User usr);

bool gameOver(User usr);

void printInventory(int * p_inv);

int * store(User usr);

#endif
