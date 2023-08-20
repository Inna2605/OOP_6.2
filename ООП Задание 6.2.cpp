//Создать класс ноутбук. На основе других объектов, таких как :
//Процессор
//ОЗУ
//Мышка
//Веб - камера
//Принтер
//Видеокарта
//Каждый объект представлен отдельным классом.Собрать ноутбук, используя агрегацию и композицию.

#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;

class Mouse
{
    string name;
public:
    Mouse()
    {
        name = "Миша 2E Gaming M280 LED USB Black (2E-MG280UB)";
    }
    Mouse(const char* N)
    {
        name = N;
    }
    void Show()
    {
        cout << name << endl;
    }
};
class Webcam
{
    string name;
public:
    Webcam()
    {
        name = "Веб - камера Logitech HD Pro C920 1080p Черный";
    }
    Webcam(const char* N)
    {
        name = N;
    }
    void Show()
    {
        cout << name << endl;
    }
};
class Printer
{
    string name;
public:
    Printer()
    {
        name = "БФП Canon PIXMA Ink Efficiency E414 (1366C009)";
    }
    Printer(const char* N)
    {
        name = N;
    }
    void Show()
    {
        cout << name << endl;
    }
};
class CPU
{
    string name;
    int frequency;
public:
    CPU()
    {
        name = "Процесор Intel Core i5 - 10400F 2.9 GHz / 12 MB(BX8070110400F) s1200 BOX";
        frequency = 2900;
    }
    CPU(int d1)
    {
        frequency = d1;
    }
    void Show()
    {
        cout << name << endl;
        cout << "CPU frequency = " << frequency << endl;
    }
};
class RAM
{
    string name;
    int size;
public:
    RAM()
    {
        name = "ОЗУ Kingston SODIMM DDR4 32GB(2x16GB) 3200Mhz FURY Impact Black(KF432S20IBK2 / 32)";
        size = 32;
    }
    RAM(int v1)
    {
        size = v1;
    }
    void Show()
    {
        cout << name << endl;
        cout << "RAM size = " << size << endl;
    }
};
class VideoCard
{
    string name;
    int frequency;
    int memory;
public:
    VideoCard()
    {
        name = "Відеокарта ASUS GeForce RTX 3060 12GB GDDR6 TUF OC TUF - RTX3060 - O12G - V2 - GAMING(90YV0GC0 - M0NA10)";
        frequency = 1852;
        memory = 12;
    }
    VideoCard(int d2, int v2)
    {
        frequency = d2;
        memory = v2;
    }
    void Show()
    {
        cout << name << endl;
        cout << "Graphics processor frequency = " << frequency << endl;
        cout << "Video card memory = " << memory << endl;
    }
};
class laptop
{
    Mouse* obj1;//Агрегирование!
    Printer* obj2;//Агрегирование!
    Webcam* obj3;//Агрегирование!
    CPU a;//Композиция!
    RAM b;//Композиция!
    VideoCard c;//Композиция!
    int year;
public:
    laptop(Mouse* s, Printer* x, Webcam* h, int d1, int v1, int d2, int v2, int y) :obj1(s), obj2(x), obj3(h), a(d1), b(v1), c(d2,v2)
    {
        year = y;
    }
    void Show()
    {
        cout << year << endl;
        obj1->Show();
        obj2->Show();
        obj3->Show();
        a.Show();
        b.Show();
        c.Show();
    }
    ~laptop()
    {
        cout << "Destruct\n";
    }
};

int main()
{
    setlocale(LC_ALL, "uk-ua");
    Mouse obj1{ "Миша бездротова M185 Cordless, червона Logitech (910-002240/910-002237)"};
    Printer obj2{ "Багатофункціональний принтер HP DeskJet 2710e (26K72B)" };
    Webcam obj3{ "ВЕБ-КАМЕРА VERTUX ODIN-4K UHD С LED ПОДСВЕТКОЙ USB BLACK" };
    laptop* ptr = new laptop(&obj1, &obj2, &obj3, 3500, 32, 2490, 8192, 2018);
    ptr->Show();
    delete ptr;
    cout << "\n----obj2--------------\n";
    laptop new_obj(&obj1, &obj2, &obj3, 3100, 32, 1700, 1333, 1999);
    new_obj.Show();
}
