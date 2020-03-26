#include<iostream>
#include<cstring>
#include<string>

using namespace std;
void RemoveEnd(string&);

main()
{   string str;

    cout<<"Enter your string:";
    cin>>str;
    
    cout<<str<<endl;
    RemoveEnd(str);
    cout<<"After Remove:";
    cout<<str<<endl;
   return 0;
}

void RemoveEnd(string& msg)
{ 

   char cstr[msg.size()+1];
   
   strcpy(cstr,msg.c_str());
   
   cstr[msg.size()-1]='\0';

  // cout<<"In Func: "<<cstr<<endl;
   
   msg = string(cstr);
}