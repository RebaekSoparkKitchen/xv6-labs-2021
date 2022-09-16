
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2)
  {
    printf("Need a parameter number\n");
    exit(-1);
  }
  int input = atoi(argv[1]);
  sleep(input);
  exit(0);
}
