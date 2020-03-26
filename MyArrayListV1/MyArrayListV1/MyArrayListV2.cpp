//
//  MyArrayListV2.cpp
//  MyArrayListV1
//
//  Created by Nattapol on 8/13/2558 BE.
//  Copyright (c) 2558 Nattapol. All rights reserved.
//

#include "MyArrayListV2.h"
#include <iostream>
using namespace std;
MyArrayListV2::MyArrayListV2()
{
    //int n = 10;
    this->data = new int[START_BUFF_SIZE];
    (*this).capacity = START_BUFF_SIZE;
    this->size = 0;
    cout<<"MyArrayListV2::MyArrayListV2()\n";
}
MyArrayListV2::MyArrayListV2(const MyArrayListV2 &x) : MyArrayListV2()
{
    add(x);
   
    cout<<"&\n";
}

MyArrayListV2::MyArrayListV2(const MyArrayListV2 *x) : MyArrayListV2()
{
    add(x);
    cout<<"*\n";
}

void MyArrayListV2::add(int x)
{
    if(this->size >= this->capacity) // full
    {
        int *t = this->data;
        this->data = new int [this->size*2];
        for(int i = 0;i< this->size;i++)
        {
            this->data[i] = t[i];
        }
        this->capacity =this->size*2;
        delete[] t;
    }
    
    this->data[this->size] = x;
    this->size += 1;
    
    
}

int MyArrayListV2::get(int i) const
{
    if(i >= 0 && i < this->size)
    {
        return this->data[i];
    }
    return 0;
}

int MyArrayListV2::operator[](int i) const
{
    return get(i);
}
void MyArrayListV2::removeAt(int i)
{
    if(i < 0 || i >= size)
    {
        return;
    }
    
    
    for(int j=i ;j < size - 1 ;j++ )
    {
        data[j] =data[j+1];
    }
    
    size --;
    
    
}

MyArrayListV2::~MyArrayListV2()
{
    delete[] data;
    cout<<"MyArrayListV2::~MyArrayListV2()\n";
}


void MyArrayListV2::add(const MyArrayListV2 *x) //pointer
{
    for(int i=0;i< (*x).size ;i++)
    {
        this->add(x->get(i));
    }
}
void MyArrayListV2::add(const MyArrayListV2& x) // const pointer
{
    for(int i=0;i< x.size ;i++)
    {
        this->add(x.get(i));
    }
       //!!!!!!! x = new MyArrayListV2;
}

MyArrayListV2* MyArrayListV2::operator+(const MyArrayListV2& x) const
{
    MyArrayListV2* result = new MyArrayListV2(this);
    result->add(x);
    return result;
}


ostream& operator<<(ostream& os, const MyArrayListV2& x) {
    for(int j = 0; j < x.size; j++)
    {
        os << x.data[j];
        if(j !=  x.size -1)
        {
            os << ", ";
        }
    }
    os << endl;
    return os;
}


MyArrayListV2& MyArrayListV2::operator=(const MyArrayListV2& x)
{
    this->size = x.size;
    this->capacity = x.capacity;
    
    //
    this -> data = x.data;
    if(this -> data == 0 )
    {
        delete [] this -> data;
    }
    this -> data = new int[x.capacity];
    memcpy(this -> data, x.data,x.size*sizeof(int) );
    this->add(1000);
    cout<<"operator = "<<endl;
    return *this;
}
