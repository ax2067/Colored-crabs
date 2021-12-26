#include "triangle.hpp"
void Triangle()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int initial_data=0;
    cout<<"Что вам известно? \n";
    cout<<"1) Три стороны \n";
    cout<<"2) Две стороны и угол между ними стороны \n";
    cout<<"3) Сторона и высота к ней \n";
    cin>>initial_data;
    switch (initial_data)
    {
        case 1:
        {
            int side1=0,side2=0,side3=0;
            float square=0,half_per=0;
            cout<<"Введите сторону 1 \n";
            cin>>side1;
            cout<<"Введите сторону 2 \n";
            cin>>side2;
            cout<<"Введите сторону 1 \n";
            cin>>side3;
            if ((side1<=0) or (side2<=0) or (side3<=0))
            {cout<<"Данные некорректны \n"; break;}
            half_per=(side1+side2+side3)/2;
            square=sqrt(half_per*(half_per-side1)*(half_per-side2)*(half_per-side3));
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int side1=0,side2=0,angel=0;
            float square;
            cout<<"Введите сторону 1 \n";
            cin>>side1;
            cout<<"Введите сторону 2 \n";
            cin>>side2;
            cout<<"Пожалуйста, введите угол в градусах \n";
            cin>>angel;
            if ((side1<=0) or (side2<=0) or (angel<=0))
            {cout<<"Данные некорректны \n"; break;}
            square=sin(3.14/360*angel)*0.5*side1*side2;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 3:
        {
            int side1=0,height=0;
            float square=0;
            cout<<"Введите сторону \n";
            cin>>side1;
            cout<<"Введите высоту \n";
            cin>>height;
            if ((side1<=0) or (height<=0))
            {cout<<"Данные некорректны \n"; break;}
            square=0.5*side1*height;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        default:{cout<<"Такого варианта не существует \n";break;}
    }
}
