#include<iostream>
#include<string>
#include<cstring>

using namespace std;
void Removefirst(string&);

main()
{  
    string str;
    cout<<"Enter Your String: ";
    cin>>str;
    
    cout<<str<<endl;
    Removefirst(str);
    cout<<str<<endl;
        
}

void Removefirst(string& msg)
{
    char cstr[msg.size()+1];

    for(int i=0;i<msg.length();i++)
    {    
        if(i==msg.length()-1)
        {   
            cstr[i]='\0';
            break;
        }
         cstr[i]=msg[i+1];
         
    }

    cout<<"In func(): "<<cstr<<endl;
    
    msg = string(cstr);
}