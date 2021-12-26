#include "rectangle.hpp"
void Rectangle()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int initial_data=0;
    cout<<"Что вам известно? \n";
    cout<<"1) Две стороны \n";
    cout<<"2) Cторона и высота \n";
    cout<<"3) Две диагонали \n";
    cin>>initial_data;
    switch (initial_data)
    {
        default:{cout<<"Такого варианта не существует \n";break;}
        case 1:
        case 2:
        {
            float square=0,side1=0,side2=0;
            cout<<"Введите сторону \n";
            cin>>side1;
            cout<<"Введите сторону / высоту \n";
            cin>>side2;
            if ((side1<=0) or (side2<=0))
            {cout<<"Данные некорректны \n"; break;}
            square=side1*side2;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 3:
        {
            int diag1=0,diag2=0;
            float square=0;
            cout<<"Введите диагональ 1 \n";
            cin>>diag1;
            cout<<"Введите диагональ 2 \n";
            cin>>diag2;
            if ((diag1<=0) or (diag2<=0))
            {cout<<"Данные некорректны \n"; break;}
            square=0.5*diag1*diag2;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
}
