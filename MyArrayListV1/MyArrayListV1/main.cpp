#include <iostream>
#include "MyArrayListV2.h"
#include "MyArrayListV3.h"
#include "Point.h"
#include "MyArrayListV3.cpp"

using namespace std;


template<typename T>
ostream& operator<<(ostream& os, const MyArrayListV3<T>& x);


struct MyArrayListV1
{
    int * data;
    int size;
    int capacity;
};




void MyArrayListV1_init(MyArrayListV1 * A)
{
    int n = 10;
    A->data = new int[n];
    //A->data = (int*)malloc(sizeof(int)* n );
    
    (*A).capacity = n;
    A->size = 0;
}

void MyArrayListV1_add(MyArrayListV1 * A,int x)
{
    if(A->size >= A->capacity) // full
    {
        int *t = A->data;
        A->data = new int [A->size*2];
        for(int i = 0;i< A->size;i++)
        {
            A->data[i] = t[i];
        }
        A->capacity =A->size*2;
        delete[] t;
    }
    
    A->data[A->size] = x;
    A->size += 1;
    
    
}

int MyArrayListV1_get(MyArrayListV1 * A,int i)
{
    if(i >= 0 && i < A->size)
    {
        return A->data[i];
    }
    return 0;
}

void MyArrayListV1_removeAt(MyArrayListV1 * A,int i)
{
    if(i < 0 || i >= A->size)
    {
        return;
    }
    
    
    for(int j=i ;j < A->size - 1 ;j++ )
    {
        A->data[j] = A->data[j+1];
    }
    
    A->size --;
    
    
}

void MyArrayListV1_cleanUp(MyArrayListV1 * A)
{
    delete[] A->data;
    //free(A->data);
}



int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    MyArrayListV1 v;
    MyArrayListV1_init(&v);
    for(int i = 0 ; i < 1000;i++)
    {
        MyArrayListV1_add(&v, i*i);
    }
    //v.size = 10; // ERROR kak krean ***
    
    for(int i = 0 ; i < 1000;i++)
    {
        cout<<"xxxx"<<MyArrayListV1_get(&v, i) <<"\n";
    }
    MyArrayListV1_cleanUp(&v);
    
    ////////////////
    
    MyArrayListV2 v2;
    for(int i = 0 ; i < 1000;i++)
    {
        v2.add(i*i);
    }
    for(int i = 0 ; i < v2.getSize();i++)
    {
        cout<<v2.get(i)<<endl;
    }
    /////////////////////
    
    cout<<"------\n";
    
    MyArrayListV2 v3; // default constructor
    // feel good
    // easy to unstand
    // hidden !!!
    MyArrayListV2 v4(v2); // default constructor &
    
    // show
    MyArrayListV2 v5(&v2); // default constructor *
    
    MyArrayListV2 vx1;
    vx1.add(1);
    vx1.add(2);
    vx1.add(3);
    
    MyArrayListV2 vx2;
    vx2.add(11);
    vx2.add(21);
    vx2.add(300);
    
    MyArrayListV2 * vx3 = vx2 + vx1;
    
    for(int i = 0 ; i < vx3->getSize();i++)
    {
        cout<<(*vx3)[i]<<" ";
    }
    cout<<endl;
    cout<<(*vx3)<<endl;;
    vx3->add(5);
     cout<<(*vx3)<<endl;;
    MyArrayListV2  vxxxx = (*vx3); // call copy constructor
    cout<<"vxxxx "<< vxxxx<<endl;
    MyArrayListV2  vx4;
    vx4=(*vx3); // operator =
    cout<<"vx4 "<<(vx4)<<endl;;
    
    
    cout<<"---------------------\n";
   ///*
    MyArrayListV3<int> b1;
    MyArrayListV3<float> b2;
    MyArrayListV3<Point> b3;
    
    b1.add(5);
    b1.add(6);
    
    b2.add(44);
    b2.add(55);
    Point pp1 ;
    pp1.x = 3;
    pp1.y = 6;
    b3.add(pp1);
    Point pp2 ;
    pp2.x = 13;
    pp2.y = 16;
    b3.add(pp2);

    
    cout<<b1;
    cout<<b2;
    cout<<b3;
    //*/
    
    return 0;
}
