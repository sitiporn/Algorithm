#include<iostream>
#include<map>
#include<iterator>
#include<fstream>
#include<string>
#include<math.h>
/*#include <io.h>
#include <fcntl.h>
*/
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

using namespace std;
void int2text(int);
int countDigit(int);
int powNumber(int,int);
int main()
{    int number;
    //_setmode( _fileno( stdin ), _O_BINARY );
    //_setmode(_fileno(stdout), 0x00040000);
  /*  _setmode(_fileno(stdout), 0x00040000);
    wstring str = L"unicode 한글 hangul";
    wcout << str << endl; */
    cout<<"Enter your number : ";
    cin>>number;

    int2text(number);
    
    return 0;
}

void int2text(int number)
{    
     map<int,wstring>::iterator itr; 
     map<int,wstring> data;
     map<int,wstring> pos_data;
     map<int,wstring> pos;
     map<int,wstring> ex;
     wstring line;
     wifstream infile,col_file,extra;
     bool negative_flag=false;
     int neg = -1,num=20;
     infile.open("decimal.txt");
     col_file.open("colum.txt");
     extra.open("extra.txt");

     if(extra.is_open())
        {     
                while(getline(extra,line))
                {   
                    ex.insert(pair<int,wstring>(num,line));                  
                }
            extra.close();
        }
        else
            cout<<"can not open extra file"<<endl;

     itr = ex.find(num);
     cout<<itr->first<<endl;
     if(col_file.is_open())
     { 

       int i=0;
       while(getline(col_file,line))
       {   
           pos.insert(pair<int,wstring>(powNumber(10,i),line));
           i++;
       }
       
        col_file.close();
     }
     else
       cout<<"Call file can't open";
     
      for (itr = pos.begin(); itr != pos.end(); ++itr) { 
        cout <<itr->first <<endl;
            
     } 
     
     if(infile.is_open())
     {  
        
        if(number < 0)
        {   negative_flag=true;
            number*=-1;
            wifstream sign;
            sign.open("sign.txt");

            if(sign.is_open())
            {  
                while (getline(sign,line))
               {  
                   pos_data.insert(pair<int,wstring>(neg,line));
               }
              
               sign.close();
            }
            else
              cout<<"unable to open sign file";
             
       }
       int i=0;
        while (getline(infile,line))
        {  
          
          data.insert(pair<int,wstring>(i,line));
          i++; 
          /*cout<<endl;
           int sum=0;
            for(int i=0;i<line.length();i++)
             {
                cout<<line[i]<<" ";
                sum+=line[i];
                if((i+1)%3 == 0)
                     cout<<"|";
             }
             cout<<" "<<"sum = "<<sum<<endl;
             cout<<"-----------------------------------------"<<endl;
             */
         }
          infile.close();
     } 
     else
     {
         cout<<"file can't open";
     }
    
   /*  for(itr = data.begin(); itr != data.end(); ++itr) { 
        
        int sum=0;  
        cout <<itr->first<<": "; 
        for(int i=0;i< itr->second.length();i++)
        {
                cout<<itr->second[i]<<" ";
                sum+=itr->second[i];
                if((i+1)%3 == 0)
                     cout<<"|";
        }
        cout<<" "<<"sum = "<<sum<<endl;
        cout<<"-----------------------------------------"<<endl;
    } */
    wofstream myfile("output.txt");
    
    if(myfile.is_open())
    {
         wstring str;
         
          
         int length = countDigit(number);  
         cout<<"Length ="<<length<<endl;                               //                        do{
         int val[length];
         
         /*cout<<"100="<<powNumber(10,2)<<endl;
         cout<<"10="<<powNumber(10,1)<<endl;
         cout<<"1="<<powNumber(10,0)<<endl;*/
         for(int i=0;i<length;i++)
         {   
            val[i] = (number%powNumber(10,i+1))/powNumber(10,i);
            cout<<val[i]<<endl;
         }
                 
         if(negative_flag)
         {
             itr = pos_data.find(neg);
             cout<<itr->first<<endl;
             myfile<<itr->second;
             negative_flag=false;
         }
         
         
         int col;
         bool col_flag = false;
         for(uint8_t i=0;i<length;i++)
         {  
            col = (length-i)%7;
         
            if(col==6||length<=6)
                 col_flag=true;
            if(col_flag)
               col-=1;
            if(i==(length-1))
              cout<<"i=0, col ="<<col<<endl; 

           /* if(col==1&&val[length-1-i]==1)
                  
            else if(col=0&&val[length-1-i]==1)
              */ 
            bool ed_flag = false;
            if(val[length-1-i]==1&&col==1)
            {}   
            else if(val[length-1-i]==1&&col==0)
            {
                if(length==7)
                {
                    
                  itr = data.find(val[length-1-i]);
                  myfile<<itr->second;
                  ed_flag = true;
                }
                if(length==1)
                {
                    itr = data.find(val[length-1-i]);
                    myfile<<itr->second;
                    continue;                               
                }
            }
            else if(val[length-1-i]==0)
            {
                continue;
            }
            else if(val[length-1-i]==2&&col==1)
            {
                itr = ex.find(num);
                myfile<<itr->second;
            }
            else
            {  
                itr = data.find(val[length-1-i]);
                myfile<<itr->second;
                
            }
           
            cout<<col<<" ";
           //if(i)
            
          /* if(val[length-1-i]!=1&&col==0)
                 continue;*/
           if(val[length-1-i]!=1&&col==0)
           {}
           else if(ed_flag)
           {
               ed_flag = false;
           }
           else
           {
               itr = pos.find(powNumber(10,col)); 
               myfile<<itr->second;
           }
            if(i<4&&col==0&&length>6)
           {
               itr= pos.find(pow(10,6));
               myfile<<itr->second;
           }
         }
         
         myfile<<endl;
                                                              
                                                //    myfile<<itr->second<<endl;
                                                                            
                                                                        
                                                                        //++itr;
                                                                    
                                                                  //  }while(itr != data.end()); 

        myfile.close();
    }
    else
    {
        cout<<"Unable to open file";
    }
    
  
}
int countDigit(int n) 
{ 
    if (n == 0) 
        return 0; 
    return 1 + countDigit(n / 10); 
} 
 int powNumber(int a,int b)
 {  int result=1;
     for(int i=0;i<b;i++)
     {
         result *= a;
     }


     return result;
 }