#include "side_pyramid.hpp"
void Side_pyramid()
{
    setlocale(LC_ALL, "Ru-ru");
    int initial_data=0;
    cout<<"Что вам известно?"<<endl;
    cout<<"1) Количество боковых граней и их площадь"<<endl;
    cout<<"2) Периметр основания и апофема"<<endl;
    cin>>initial_data;
    switch(initial_data)
    {
        default:{cout<<"Такого варианта не существует"<<endl;break;}
        case 1:
        {
            int amount=0,side_squrae=0,square=0;
            cout<<"Введите количество сторон \n";
            cin>>amount;
            cout<<"Введите площадь боковой грани \n";
            cin>>side_squrae;
            square=side_squrae*amount;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int perimetr=0, apofema=0;
            float square=0;
            cout<<"Введиет периметр \n";
            cin>>perimetr;
            cout<<"Введиет апофему \n";
            cin>>apofema;
            square=apofema*perimetr;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
}
