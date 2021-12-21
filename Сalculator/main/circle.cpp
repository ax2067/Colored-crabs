#include "circle.hpp"

void Circle()
{
    setlocale(LC_ALL, "Ru-ru");
    int initial_data=0;
    cout<<"Что вам известно? \n"<<endl;
    cout<<"1) Радиус \n";
    cout<<"2) Длина окружности \n";
    cin>>initial_data;
    switch (initial_data)
    {
        default:{cout<<"Такого варианта не существует"<<endl;break;}
        case 1:
        {
            int radius=0;
            float square=0;
            cout<<"Введите радиус \n";
            cin>>radius;
            square=3.14*radius*radius;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int length=0;
            float square=0;
            cout<<"Введите длину окружности (без П) \n";
            cin>>length;
            length=length*3.14;
            square=length/(2*3.14);
            square=square*square*3.14;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
}
