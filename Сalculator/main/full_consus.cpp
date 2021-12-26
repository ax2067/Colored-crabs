#include "full_consus.hpp"
void Full_conus()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int radius=0,obrazuys=0;
    float square=0;
    cout<<"Введите радиус \n";
    cin>>radius;
    cout<<"Введите образующую \n";
    cin>>obrazuys;
    if ((radius<=0) or (obrazuys<=0))
    {cout<<"Данные некорректны \n"; break;}
    square=(3.14*radius*radius)+(3.14*radius*obrazuys);
    cout<<square<<"\n";
}
