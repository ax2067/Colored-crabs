#include "prlgrm.hpp"
void Prglrm()
{
    char ElementValue[SIZE];
    setlocale(LC_ALL, "en_US.UTF8");
    int initial_data=0;
    cout<<"Что вам известно? \n";
    cout<<"1) Две стороны и угол между ними \n";
    cout<<"2) Сторона и проведенная к ней высота \n";
    cout<<"3) Диагонали и угол между ними \n";
    cin>>initial_data;
    switch (initial_data)
    {
        default:{cout<<"Такого варианта не существует "<<endl;break;}
        case 1:
        {
            int side1=0,side2=0,angel=0;
            float square=0;
            cout<<"Введите сторону 1 \n";
            cin>>side1;
            cout<<"Введите сторону 2 \n";
            cin>>side2;
            cout<<"Пожалуйста, введите угол в градусах \n";
            cin>>angel;
            if((side1<=0)or(side2<=0)or(angel<=0)){cout<<"Неверные данные \n";break;}
            square=sin(3.14/360*angel)*side1*side2;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int side1=0,height=0;
            float square=0;
            cout<<"Введите сторону 1 \n";
            cin>>side1;
            cout<<"Введите сторону 2 \n";
            cin>>height;
            if((height<=0)or(side1<=0)){cout<<"Неверные данные \n";break;}
            square=side1*height;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 3:
        {
            int diag1=0,diag2=0,angel=0;
            float square=0;
            cout<<"Введите диагональ 1 \n";
            cin>>diag1;
            cout<<"Введите диагональ 2 \n";
            cin>>diag2;
            cout<<"Пожалуйста, введите угол в градусах \n";
            cin>>angel;
            if((diag1<=0)or(diag2<=0)or(angel<=0)){cout<<"Неверные данные \n";break;}
            square=sin(3.14/360*angel)*diag1*diag2*0.5;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
}
