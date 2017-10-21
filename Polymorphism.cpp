#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class shape
{
    public:
    virtual double area()=0;
    virtual void tostring()=0;


};


class circle:public shape
{
    double r;
    public:
        circle(double n)
        {
            r=n;
        }
        void tostring()
        {
            cout << "I'm a circle"<<endl;
        }
        double area()
        {
            return r*r*atan(1.0)*4;
        }

};

class Square:public shape
{
    double len;
public:
    Square(double n)
    {
        len=n;
    }
    double area()
    {
        return len*len;
    }
    void tostring()
    {
        cout<<"I am a square"<<endl;
    }


};

class rectangle:public shape
{
        double len;
        double width;

    public:
        rectangle(double a,double b)
        {
            len=a;
            width=b;
        }
        void tostring()
        {
            cout<<"I am a rectangle"<<endl;

        }
        double area()
        {
            return len*width;
        }
};

class list
{
    int index;
    shape** arr;
public:
    list(){index=0;
    arr=new shape*[10];
    }
    void insert(shape* sh)
    {

        arr[index++]=sh;
    }

    double getItem(int i)
    {
        arr[i]->tostring();
        return arr[i]->area();
    }
    void sort()
    {
        for(int i=0; i < index;i++)
         {
             for(int j=0; j<i; j++)
             {
             if((arr[i]->area())>(arr[j]->area()))
             {
                 shape* t = arr[i];
              arr[i] = arr[j];
              arr[j]= t;
             }
         }
         }


    }

};

int main()
{
    Square s(100);

    circle c(5);
    rectangle r(10,5);
    Square s2(10);
    Square s3(30);
    rectangle r2(10,3);
    list l;
    l.insert(&s);
    l.insert(&c);
    l.insert(&s2);
    l.insert(&r);
    l.insert(&r2);
    l.insert(&s3);
    l.sort();
    cout<<l.getItem(0)<<endl;
    cout<<l.getItem(1)<<endl;
    cout<<l.getItem(2)<<endl;
    cout<<l.getItem(3)<<endl;
    cout<<l.getItem(4)<<endl;
    cout<<l.getItem(5)<<endl;

}
