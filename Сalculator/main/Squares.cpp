#include "Squares.h"


int Squares()
{
    char ElementValue[SIZE]; //-----добавь это в каждый модуль. В файлах с расширением h, добавь #define... см. Squares.h
    setlocale(LC_ALL, "en_US.UTF8");
    int action=0;
    do 
    {
    cout<<"Ввыберите фигуру, площадь которорой необходимо найти \n";
    cout<<"1) Треугольник \n";
    cout<<"2) Прямоугольник \n";
    cout<<"3) Параллелограмм \n";
    cout<<"4) Квадрат \n";
    cout<<"5) Ромб \n";
    cout<<"6) Круг \n";
    cout<<"7) Правильный N угольник \n";
    cout<<"8) Площадь полной поверхности пирамиды \n";
    cout<<"9) Площадь боковой поверхности пирамиды \n";
    cout<<"10) Площадь боковой поверхности конуса \n";
    cout<<"11) Площадь полной поверхности конуса"<<endl;
    cout<<"12) Выход из программы \n";
    cin >> ElementValue;
    if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
        printf("Ошибка - введен неправильный символ....\n");
        system("pause");
        return 0;
    }
    //else  action = atoi(ElementValue);
    switch (ElementValue)
    {
        default:{cout<<"Такого варианта не существует \n"; break;}
            
        case 1:
        {
            Triangle();
            break;
        }
        case 2:
        {
            Rectangle();
            break;
        }
        case 3:
        {
            Prglrm();
            break;
        }
        case 4:
        {
            Kvadrat();
            break;
        }
        case 5:
        {
            Romb();
            break;
        }
        case 6:
        {
            Circle();
            break;
        }
        case 7:
        {
            Many_angel();
            break;
        }
        case 8:
        {
            Full_pyramid();
            break;
        }
        case 9:
        {
            Side_pyramid();
            break;
        }
        case 10:
        {
            Side_conus();
            break;
        }
        case 11:
        {
            Full_conus();
            break;
        }
        case 12:
            cout << "Работа окончена. Для продолжения нажмите любую кнопку." << endl; 
            break;
    }
    cin.clear();
    cin.ignore(32767, '\n');
    }while (action != 12);
    return 0;
}
