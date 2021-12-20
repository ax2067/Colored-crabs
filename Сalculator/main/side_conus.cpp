#include "side_conus.hpp"
void Side_conus()
{
    setlocale(LC_CTYPE, "Russian");
    int radius=0, obrazuyus=0;
    float square=0;
    cout<<"Введите радиус \n";
    cin>>radius;
    cout<<"Введите образующую \n";
    cin>>obrazuyus;
    square=3.14*radius*obrazuyus;
    cout<<square<<endl;
}
