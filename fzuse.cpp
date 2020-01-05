#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t t = fork();
  if(t < 0)
  {
    perror("fork");
    return 0;
  }
  else if(t ==0 )
  {
    printf("i'am child pid : %d  ppid : %d\n",getpid(),getppid());
    printf("child starts\n");
    sleep(5);
  }
  else 
  {
    int  status = 0;
    pid_t ret ;
    do 
    {
      ret = waitpid(-1,&status,WNOHANG);//WNOHANG 轮询式等待
      if(ret == 0)
      {
        printf("father is waiting...\n");
        fflush(stdout);
        sleep(1);
      }
    }while(ret == 0);

    if((status & 0x8f) == 0)
    { 
      printf("正常退出 ,退出信息为 %d\n ",(status>>8) & 0xff);
    }
    else 
    {
      printf("异常终止，终止信号为%d\n",status & 0x7f);
      return 1;
    }

  }

  return 0;
}
