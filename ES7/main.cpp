#include <iostream>
#include<windows.h>
#include <fstream>
using namespace std;


int main()
{
   int _count[4]={0,0,0,0},_max_count=1e-6;
   string msg[4]={"MAI EK","MAI THO","MAI TRI","MaI CHATTAWA "};
    cout<<"Hello ES7"<<endl;
    wstring line; 
    wifstream myfile;

    myfile.open("C:\\Users\\maple\\Desktop\\ES7\\riwords.txt");



    if (myfile.is_open()){


       while (getline(myfile,line)) {

           for(int i=0;i<(line.length());i+=3)
            {   // if(/*line[i] == 0xb9 &&*/line[i]==0x88)
                //{   
                 if(line[i]==224)
                 {
                     if(line[i+1]==185)
                     {
                         if(line[i+2]==136)
                              _count[0]++;
                         else if(line[i+2]==137)
                              _count[1]++;
                        else if(line[i+2]==138)
                             _count[2]++;
                        else if(line[i+2]==139)
                            _count[3]++;
                     }
                 }
                wcout<<line; 
                             // cout<<line[i+1]<<"|";
            }
                       
                  //cout<<endl;
       }
        myfile.close();
    }
    else
     cout<<"Unable to open file"<<endl;
     
        int index;
            for(int i=0;i<4;i++)
            {
                if(_max_count< _count[i])
                { 
                    _max_count= _count[i];
                    index = i;
                }
                cout<<msg[i]<<":"<<_count[i]<<endl;
            }
     
    cout<<"So Max value:"<<msg[index]<<" ="<<_max_count<<endl;
  // system("pause");

    return 0;
}
