#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv) {

  // parent -> child pipe
  int p1[2];

  // child -> parent pipe 
  int p2[2];
  pipe(p1);
  pipe(p2);
  char buf[128];

  // the child process(pid) copies all information of the parent process
  int pid = fork();
  if(pid != 0 ){
    // parent process
    
    write(p1[1], "pong",4);
    read(p2[0], buf, 4);
    printf("%d: received ping\n", getpid());
  } else {

    //child process

    // the most important sentance!!!
    // If no data is available, a read on a pipe waits for either data to be written or for all file descriptors referring to the write end to be closed
    // because of the feature of read call, we can achieve such information exchange
    read(p1[0], buf, 4);
    printf("%d: received %s\n", getpid(), buf);
    write(p2[1], "ping", 4);
  }
  exit(0);
}
