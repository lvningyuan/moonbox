#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t  t=fork();
  if(t < 0)
  {
    perror("fork");
    return 0;
  }
  if(t == 0)
  {
    printf("i'am  child  pid:%d   ppid: %d",getpid(),getppid()); 
    sleep(5);
    exit(1);
  }
  else 
  {
    int status = 0;
    printf("i'am father pid: %d   ppid: %d\n",getpid(),getppid());
    pid_t ret =  waitpid(-1,&status,0); //阻塞式等待5秒
    while(ret == 0)
    if(ret  == -1)
    {
      perror("waitpid");
      exit(-1);
    }
    else 
    {
      if( (status & 0x7f) == 0)
      {
        printf("正常退出  退出信息%d\n",(status >>8) & 0xff  );
      }
      else 
      {
        printf("异常终止 , 信号源为%d\n",status & 0x7f);
      }
    }
  }

  return 0;
}
