#include "romb.hpp"
void Romb()
{
    int initial_data=0;
    cout<<"Что вам известно? \n";
    cout<<"1) Cторона и угол"<<endl;
    cout<<"2) Диагонали"<<endl;
    cout<<"3) Сторона и высота"<<endl;
    cin>>initial_data;
    switch(initial_data)
    {
        default:{cout<<"Такого варианта не существует"<<endl; break;}
        case 1:
        {
            int side1=0,angel=0;
            float square=0;
            cout<<"Введите сторону 1 \n";
            cin>>side1;
            cout<<"Пожалуйста, введите угол в градусах"<<endl;
            cin>>angel;
            square=side1*side1*sin(3.14/360*angel);
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int diag1=0,diag2=0;
            float square=0;
            cout<<"Введите диагональ 1 \n";
            cin>>diag1;
            cout<<"Введите диагональ 2 \n";
            cin>>diag2;
            square=0.5*diag1*diag2;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 3:
        {
            int height=0,side1=0;
            float square=0;
            cout<<"Введите сторону \n";
            cin>>side1;
            cout<<"Введите высоту \n";
            cin>>height;
            square=height*side1;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
}
