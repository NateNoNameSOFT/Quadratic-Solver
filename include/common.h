#ifndef COMMON_H_
#define COMMON_H_

#include <string.h>

#define MAX_BUF 255

#define REMOVE_NEWLINE(str) str[strcspn(str, "\n")] = '\0'

#ifdef DEBON
/*
    if DEBON is defined you can use the
    DEBUG macro to display debug info
    from the console
    fmt = what you want to display
*/
#define DEBUG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
/*
    does nothing if DEBON is not defined
*/
#define DEBUG(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#endif // DEBON


#define RED "\x1b[31m"      
#define GRE "\x1b[32m"      
#define YEL "\x1b[33m"      
#define BLU "\x1b[34m"
#define MAG "\x1b[35m"
#define CYA "\x1b[36m"
#define WHT "\x1b[37m" 
#define RESET "\x1b[0m"

#define BACBLK "\x1b[40m"
#define BACRED "\x1b[41m"
#define BACGRE "\x1b[42m"
#define BACYEL "\x1b[43m"
#define BACBLU "\x1b[44m"
#define BACMAG "\x1b[45m"
#define BACCYA "\x1b[46m"
#define BACWHT "\x1b[47m"

#endif