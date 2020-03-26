#ifndef __MyArrayListV1__MyArrayListV2__
#define __MyArrayListV1__MyArrayListV2__

#define START_BUFF_SIZE 10
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;
class MyArrayListV2
{
private:
    int * data; // size = 8 bytes
    int size;   // size = 4 bytes
    int capacity;//size = 4 bytes
    
public:
    
    MyArrayListV2(); // default constructor
    MyArrayListV2(const MyArrayListV2& x); // copy constructor
    MyArrayListV2(const MyArrayListV2* x);// copy constructor
    ~MyArrayListV2();
    
    void add(int x); // pass by value
    // void add(MyArrayListV2 x); // copy object.
    void add(const MyArrayListV2 *x); //pointer
    void add(const MyArrayListV2& x); // const pointer
    int get(int i) const;
    void removeAt(int i);
    
    MyArrayListV2* operator+(const MyArrayListV2& x) const;
    int operator[](int i) const;
    
    MyArrayListV2& operator=(const MyArrayListV2& x) ;
    int getSize() const// inline
    {
        return size;
    }
//    int xx()
//    {
//        for(int i = 0 ; i < 100 ; i ++)
//        {
//            //jdkfgjlksdjfg
//        }
//        return 10;
//    }

    friend ostream& operator<<(ostream& os, const MyArrayListV2& ia);
    
    
};


#endif