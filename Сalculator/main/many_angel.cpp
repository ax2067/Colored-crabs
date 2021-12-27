#include "many_angel.hpp"
void Many_angel()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int initial_data=0;
    cout<<"Что вам известно?"<<endl;
    cout<<"1) Длина стороны и кол-во"<<endl;
    cout<<"2) Радиус висанной окружности и кол-во сторон"<<endl;
    cout<<"3) Радиус описаной окружности и кол-во сторон"<<endl;
    cin>>initial_data;
    switch (initial_data)
    {
        default:{cout<<"Такого варианта не существует"<<endl;break;}
        case 1:
        {
            int side=0, amount=0;
            float square=0;
            cout<<"Введите сторону \n";
            cin>>side;
            cout<<"Введите количество сторон \n";
            cin>>amount;
            square=(amount*side*side)/(4*tan(3.14/amount));
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int rad_vpis=0,amount=0;
            float square=0;
            cout<<"Введите радиус \n";
            cin>>rad_vpis;
            cout<<"Введите количество сторон \n";
            cin>>amount;
            square=rad_vpis*rad_vpis*amount*tan(3.14/amount);
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 3:
        {
            int rad_opis=0,amount=0;
            float square=0;
            cout<<"Введите радиус \n";
            cin>>rad_opis;
            cout<<"Введите количество сторон \n";
            cin>>amount;
            square=0.5*rad_opis*rad_opis*amount*sin(3.14*2/amount);
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
            
    }
}
