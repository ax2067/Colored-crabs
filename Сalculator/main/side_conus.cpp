#include "side_conus.hpp"
void Side_conus()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int radius=0, obrazuyus=0;
    float square=0;
    cout<<"Введите радиус \n";
    cin>>radius;
    cout<<"Введите образующую \n";
    cin>>obrazuyus;
    if ((radius<=0) or (obrazuyus<=0))
    {cout<<"Данные некорректны \n"; break}
    square=3.14*radius*obrazuyus;
    cout<<square<<endl;
}
