#include "kvadrat.hpp"
void Kvadrat()
{
    char ElementValue[SIZE];
    setlocale(LC_ALL, "en_US.UTF8");
    int initial_data=0;
    cout<<"Что вам известно? \n";
    cout<<"1) Cторона \n";
    cout<<"2) Диагональ \n";
    cin>>initial_data;
    switch (initial_data) {
        default:
        {
            cout<<"Такого варианта не существует "<<endl;
            break;
        }
        case 1:
        {
            int side1=0;
            float square=0;
            cout<<"Введите сторону \n";
            cin>>side1;
            if(side1<=0){cout<<"Неверные данные \n";break;}
            square=side1*side1;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
        case 2:
        {
            int diag1=0;
            float square=0;
            cout<<"Введите диагональ 1 \n";
            cin>>diag1;
            if(diag1<=0){cout<<"Неверные данные \n";break;}
            square=diag1*diag1;
            cout<<"Площадь равна "<<square<<endl;
            break;
        }
    }
    
}
