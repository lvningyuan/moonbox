#include <stdio.h>

void Swap1 (int *a ,int * b)
{
  int tmp = *a ;
  *a  = *b  ;
  *b =tmp;
}

//为解决时间复杂制度为O（n^2）  的情况  ，我们采用三数取中法


int getMid(int*a  ,int left ,int right )
{
  int mid =left + ((right-left) >> 1);

  if(a[left] < a[mid])
  {
    if(a[mid] > a[right])
      return a[right];
    if(mid > left)
      return a[mid];
    else return left; 
  }
  else 
  {
    if (a[right] > a[left])
      return a[right];
    if(a[mid] < a[left])
      return a[mid];
    else 
      return a[left] ;
  }
}

int partSort(int*a ,int begin  ,int end )
{
  int key = getMid(a , begin , end); 
  while (begin < end )
  {
    while(begin <end && a[end]  >=  a[key])
    {
      end--;

    }

    while(begin <end  && a[begin] <= a[key]   )
    {
      end++;

    }
    Swap1(&a[begin],&a[end]);

  }

  Swap1(&a[key],&a[begin]); 

  return  key;
}


void QSort(int*a ,int left , int right)
{

  if(left >= right)
    return ;
  int key = partSort(a,left,right);

  QSort(a,left,key-1);//递归左边
  QSort(a,key+1,right);//递归右边
}

