#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig)
{
  signal_count++;
  if (signal_count < 3)
  {
    printf("Press CTRL + C %d times more to end the process\n",
           3 - signal_count);
    fflush(stdout); // NOTE: fflush(stdout) makes the output appear immediately
  }
  else
  {
    printf("TERMINATING THE PROCESS - SIGINT called 3 times\n");
    fflush(stdout);
    exit(EXIT_SUCCESS);
  }
}

int main()
{
  signal(SIGINT, handle_sigint);
  printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

  while (1)
  {
    sleep(1);
  }

  return 0;
}