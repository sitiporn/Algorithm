#include<iostream>

using namespace std;
int c=0;
 int a;
int minMoveTower(int,char,char,char);
int ReturnC()
{  cout<<"Call C"<<endl;
   return 2;
}
int ReturnB()
{  cout<<"Call B"<<endl;
   a = ReturnC();
  // cout<<"finish B"<<endl;
   //return a;
}
int checkReturn()
{  cout<<"call checkReturn"<<endl;
   ReturnB();
  //cout<<"finish checkReturn"<<endl;
}

int main()
{ int number;
  char _source,_dest,_spare;
  int _count=0;
  
 // cout<<"Check Return:"<<checkReturn()<<endl;
  cout<<"Hello tower Hanoi"<<endl;
  cout<<"Enter your disk : ";
  cin>>number;

  cout<<"Source : ";
  cin>>_source;

  cout<<"Dest : ";
  cin>>_dest;

  cout<<"Spare : ";
  cin>>_spare;
 
  
  
  _count = minMoveTower(number,_source,_dest,_spare);

  cout<<"Minimum move of Disk = "<<_count<<endl;
}
int minMoveTower(int disk,char source,char dest,char spare)
{  
    if(disk==1)
   {  
      c++;
      cout<<disk<<" source "<<source<<" to "<<"dest"<<dest<<" count = "<<c<<endl;
      
     return c;
   
   }  
    else
    {  
       minMoveTower(disk-1,source,spare,dest);
       c++;
       cout<<disk<<" source "<<source<<" to "<<"dest"<<dest<<" count = "<<c<<endl;
       minMoveTower(disk-1,spare,dest,source);
       //cout<<"finish"<<endl;
       
    }
       
 // return 2;
    
}
