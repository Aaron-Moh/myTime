#include <iostream>

#define error "The input is invalid!\n"

using namespace std;

bool currently=true;//if this is true then the permission for printing is granted
bool is24Style=true;//if true it will print 24 style and if not it will print am-pm style

enum
{
    HOUR,
    MINUTE,
    SECOND,
    DIFFERENCESECOND,
    DIFFERENCEMINUTE
};

class myTime
{
    int hour,minute,second,differce;
    bool checker(int a,int b,int c);
    void printALL24();//prints 24 hour style
    void printALLampm();//print am or pm style
    int returnDIff(int a);//gives the differce an amount either in second or in minute!
    bool doubledigit(int a);//for making it a little more beautiful
public:
    myTime();
    ~myTime();
    void change(int switchcase,int toDo);
    void printer();
    void print_something(int a);
    void setTime(int a,int b,int c);
    void add(int caser,int amount);
};

bool myTime::doubledigit(int a)
{
    return a>=10;
}

myTime::myTime()
{
        hour=0;
        minute=0;
        second=0;
}

myTime::~myTime()
{
    delete hour,minute,second;
}

bool myTime::checker(int a,int b,int c)
{
    if(a>24||a<0||b>60||b<0||c>60||c<0)
    {
        cout << error;
        currently=false;
        return false;
    }
    else
    {
        currently=true;
        return true;
    }
}

int myTime::returnDIff(int a)
{
    if (a==MINUTE) return hour*60+minute;
    else return hour*3600+minute*60+second;
}

void myTime::setTime(int a,int b,int c)
{
    if(checker(a,b,c))
    {
        hour=a;
        minute=b;
        second=c;
    }
}

void myTime::printALL24()
{
    if(currently)
    {
        if(doubledigit(hour)) cout << hour << ":";
        else cout << "0" << hour << ":";

        if(doubledigit(minute)) cout << minute << ":";
        else cout << "0" << minute << ":";

        if(doubledigit(second)) cout << second << endl;
        else cout << "0" << second << endl;
    }
}

void myTime::printALLampm()
{
    if(currently)
    {
        bool isAM=true;
        int hour1=hour;
        if(hour >= 12) hour1=hour-12,isAM=false;

        if(doubledigit(hour1)) cout << hour1 << ":";
        else cout << "0" << hour1 << ":";

        if(doubledigit(minute)) cout << minute << ":";
        else cout << "0" << minute << ":";

        if(doubledigit(second)) cout << second;
        else cout << "0" << second;

        if(isAM) cout << " AM";
        else cout << " PM";
        cout << endl;
    }
}

void myTime::printer()
{
    if(is24Style) printALL24();
    else printALLampm();
}

void myTime::change(int switchcase,int toDo)
{
    switch(switchcase)
    {
    case HOUR:
        if(toDo>12||toDo<0) cout << error;
        else this->hour=toDo;
        break;
    case MINUTE:
        if(toDo>60||toDo<0) cout << error;
        else this->minute=toDo;
        break;
    case SECOND:
        if(toDo>60||toDo<0) cout << error;
        else this->second=toDo;
        break;
    default:
        break;
    }

}

void myTime::print_something(int a)
{
    switch (a)
    {
    case HOUR:
        cout << hour << endl;
        break;
    case MINUTE:
        cout << minute << endl;
        break;
    case SECOND:
        cout << second << endl;
        break;
    case DIFFERENCESECOND:
        differce=returnDIff(0);
        cout << "Difference in second is: " << differce << endl;
        break;
    case DIFFERENCEMINUTE:
        differce=returnDIff(1);
        cout << "Difference in minute is: " << differce << endl;
        break;
    }
}

void myTime::add(int caser,int amount)
{
    switch(caser)
    {
    case HOUR:
        this->hour+=amount;
        while(hour>23) hour-=24;
        cout << "Time is now: ";
        printer();
        break;
    case MINUTE:
        minute+=amount;
        while(minute>=60)
        {
            hour++;
            minute-=60;
            if(hour>23) hour-=24;
        }
        cout << "Time is now: ";
        printer();
        break;
    case SECOND:
        second+=amount;
        while(second>59)
        {
            minute++;
            second-=60;
            if(minute>59)
            {
                hour++;
                minute-=60;
                if(hour>23) hour-=24;
            }
        }
        cout << "Time is now: ";
        printer();
        break;
    }
}

int main()
{
    cout << "Bye world\n";
}
