#include "full_pyramid.hpp"
void Full_pyramid()
{
    setlocale(LC_ALL, "en_US.UTF8");
    int side_osn=0,amount=0,apofema=0;
    float square=0;
    cout<<"Введите сторону \n";
    cin>>side_osn;
    cout<<"Введите количество сторон \n";
    cin>>amount;
    cout<<"Введиет апофему \n";
    cin>>apofema;
    if ((side_osn<=0) or (amount<=0) or (apofema<=0))
    {cout<<"Данные некорректны \n"; break}
    square=(amount*side_osn*side_osn)/(4*tan(3.14/amount))+(apofema*amount*side_osn);
    cout<<"Введите сторону 1 \n";
}
