#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class MySet
{
    private:
    T *set;
    int card;

    public:  
    MySet()
    {
        card = 0;
        set = new T[1];
    } 
    MySet(int size)
    {
        card = size;
        set = new T[card];
    }
    void inputset(int num)
    {
        int i;
        cout<<"\nEnter set "<<num<<" :";
        for(i=0; i<card; i++)
        cin>>set[i];
    }
    void removej(T ar[],int j)
    {
        while(j<card-1)
        {
            ar[j] = ar[j+1];
            j++;
        }
        card--;
    }
    void duplicate()
    {
       int i,j;
       for(i=0; i<card; i++)
       {
           for(j=i+1; j<card; )
           {
               if(set[i]==set[j])
               {
                   removej(set,j);
               }
               else
               {
                   j++;
               }    
           }
       }
    }
    void displayset()
    {
        if(card>0)
        {
            duplicate();
            cout<<"{ ";
            for(int i=0; i<card; i++)
            {
                cout<<set[i];
                if(i==card-1)
                cout<<" }";

                else
                cout<<" , ";
            }
        }
        else
        cout<<"{ }";
        cout<<"\tCardinality = "<<cardinality();
    }
    MySet operator+(MySet &obj)
    {
        int tempcard,i,j=0;
        tempcard = card + obj.card;
        MySet<T> tempset(tempcard);
        for(i=0; i<card; i++)
        {
            tempset.set[i] = set[i];
        }
        for(i=card; i<tempcard; i++)
        {
            tempset.set[i] = obj.set[j++];
        }
        return tempset;
    }
    MySet& operator=(const MySet &obj)
    {
        card = obj.card;
        for(int i=0; i<card; i++)
        set[i] = obj.set[i];
        return *this;
    }
    MySet operator-(MySet &obj)
    {
        int i=0,j=0,count=0;
        bool flag = true;
        T *temparr;
        temparr = new T[card];
        for(i=0; i<card; i++)
        {
            flag=true;
            for(j=0; j<obj.card; j++)
            {
                if(set[i]==obj.set[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                temparr[count++] = set[i];
            }
        }
        if(count)
        {
            MySet<T> tempset(count);
            for(i=0; i<count; i++)
            {
                tempset.set[i] = temparr[i];
            }
            return tempset;
        }
        else
        {
            MySet<T> tempset; 
            return tempset;
        }
    }
    int cardinality()
    {
        return card;
    }
    void powerset()
    {
        int i,j,t,count=0;
        int powcard = pow(2,card);
        cout<<"{ ";
        for(i=0; i<powcard; i++)
        {
            if(i>0)
            cout<<", { ";
            else
            cout<<" { ";
                count=0;
                for(t=i, j=0; j<card; j++)
                {
                    if( t & 1 )
                    {
                        if(count>=1)
                        cout<<", ";
                        cout<<set[j]<<" "; 
                        count++;
                    }
                    t = t>>1;
                }
                cout<<"} ";
        }
        cout<<" }";
        cout<<"\tCardinality = "<<powcard;
    }
    MySet operator*(MySet &obj)
    {
        int i,j,count=0;
        T *temparr;
        temparr = new T[card];
        for(i=0; i<card; i++)
        {
            for(j=0; j<obj.card; j++)
            {
                if(set[i]==obj.set[j])
                {
                    temparr[count++] = set[i];
                    break;
                }
            }
        }
        MySet<T> tempset(count);
        for(i=0; i<count; i++)
        tempset.set[i] = temparr[i];

        return tempset;
    }
    void operator==(MySet &obj)
    {
        int i=0,j=0;
        bool check = false;
        if( card==obj.card )
        {
            for(i=0; i<card; )
            {
                check = false;
                for(j=0; j<card; j++)
                {
                    if(set[i]==obj.set[j])
                    {
                        check = true;
                        break;
                    }
                }
                if(check)
                i++;
                else
                break;
            }
        }
        else
        check=false;

        if(check)
        cout<<"\nSets are equal";
        else
        cout<<"\nSets are NOT equal";
    }
    MySet operator^(MySet &obj)
    {
        MySet<T> temp1 = *this + obj;
        MySet<T> temp2 = (*this) * obj;
        return temp1 - temp2;
    }
};
template<class T>
    void setmenu(T variable)
    {
        char ans = 'n';
        int size1,size2,choice;
        cout<<"\nEnter number of elements of set 1: ";
        cin>>size1;
        cout<<"\nEnter number of elements of set 2: ";
        cin>>size2;

        MySet<T> obj1(size1);
        MySet<T> obj2(size2);

        obj1.inputset(1);
        obj2.inputset(2);
        MySet<T> obj3;
        MySet<T> obj4;
        MySet<T> obj5;
        MySet<T> obj6;


        cout<<"\nSet A = ";
        obj1.displayset();
        cout<<"\nSet B = ";
        obj2.displayset();
        do
        {
            cout<<"     \nSET MENU      ";
            cout<<"\n1. Union(U)";
            cout<<"\n2. Intersection(*)";
            cout<<"\n3. Difference(-)";
            cout<<"\n4. Symmetric Difference(^)";
            cout<<"\n5. PowerSet of A";
            cout<<"\n6. PowerSet of B";
            cout<<"\nEnter your choice(1-5): ";
            cin>>choice;
            switch(choice)
            {
                case 1: {
                            obj3 = obj1 + obj2;
                            cout<<"\nAUB = ";
                            obj3.displayset();
                            break;
                        }
                case 2: {
                            obj4 = obj1 * obj2;
                            cout<<"\nA*B = ";
                            obj4.displayset();
                            break;
                        }
                case 3: {
                            obj5 = obj1 - obj2;
                            cout<<"\nA-B = ";
                            obj5.displayset();
                            break;
                        }
                case 4: {
                            obj6 = obj1 ^ obj2;
                            cout<<"\nA^B = ";
                            obj6.displayset();
                            break;
                        }
                case 5: {
                            cout<<"\nP(A) = ";
                            obj1.powerset();
                            break;
                        }
                case 6: {
                            cout<<"\nP(B) = ";
                            obj2.powerset();
                            break;
                        }
                default: cout<<"\nINVALID CHOICE !";
            }
            cout<<"\n\nDo you wish to continue?(y/n): ";
            cin>>ans;
        }while(ans=='y');
    }
int main()
{
    int in,choice;
    char ch;
    double d;
    cout<<"\nSelect datatype of set elements: ";
    cout<<"\n 1. Integer (int)";
    cout<<"\n 2. Character(char)";
    cout<<"\n 3. Double(double)";
    cout<<"\n Enter your choice(1-3): ";
    cin>>choice;
    switch(choice)
    {
        case 1: setmenu(in);
                break;
        case 2: setmenu(ch);
                break;
        case 3: setmenu(d);
                break;
        default: cout<<"\nINVALID TYPE !";
    }
    return 0;
}
