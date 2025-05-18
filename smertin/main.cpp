#include <iostream>
#include <memory>
#include <string>
#include "name.h"
#include "person.h"
#include "cat.h"
#include "city.h"

void InputName(Name& name) {
    std::string first, surname, patronymic;

    std::cout << "Введите личное имя (обязательно): ";
    std::getline(std::cin, first);

    std::cout << "Введите фамилию (можно оставить пустым): ";
    std::getline(std::cin, surname);

    std::cout << "Введите отчество (можно оставить пустым): ";
    std::getline(std::cin, patronymic);

    if (!first.empty() && surname.empty() && patronymic.empty()) {
        name = Name(first);
    }
    else if (!first.empty() && !surname.empty() && patronymic.empty()) {
        name = Name(first, surname);
    }
    else {
        name = Name(first, surname, patronymic);
    }
}

int InputInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка ввода, введите число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cin.ignore(10000, '\n');  // очистка остатка строки
    return value;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    std::cout << "Задача 1 - Создание имен.\n";
    Name n1, n2, n3, n4;
    std::cout << "Создание имени 1:\n";
    InputName(n1);
    std::cout << "Создание имени 2:\n";
    InputName(n2);
    std::cout << "Создание имени 3:\n";
    InputName(n3);
    std::cout << "Создание имени 4:\n";
    InputName(n4);

    std::cout << "\nВведённые имена:\n";
    n1.Print();
    n2.Print();
    n3.Print();
    n4.Print();

    std::cout << "\nЗадача 2 - Создание людей с именами и ростом.\n";

    int height1 = InputInt("Введите рост для первого человека: ");
    int height2 = InputInt("Введите рост для второго человека: ");
    int height3 = InputInt("Введите рост для третьего человека: ");

    auto p1 = std::make_shared<Person>(n1, height1);
    auto p2 = std::make_shared<Person>(n2, height2);
    auto p3 = std::make_shared<Person>(n3, height3);

    std::cout << "\nЛюди:\n";
    std::cout << p1->ToString() << "\n" << p2->ToString() << "\n" << p3->ToString() << std::endl;

    std::cout << "\nЗадача 3 - Создание людей с родителями.\n";

    // Ввод трёх людей и связывание отцов
    std::cout << "Введите данные для человека 1 (будет отцом):\n";
    Name father1_name;
    InputName(father1_name);
    int father1_height = InputInt("Рост: ");
    auto father1 = std::make_shared<Person>(father1_name, father1_height);

    std::cout << "Введите данные для человека 2 (сын человека 1):\n";
    Name father2_name;
    InputName(father2_name);
    int father2_height = InputInt("Рост: ");
    auto father2 = std::make_shared<Person>(father2_name, father2_height, father1);

    std::cout << "Введите данные для человека 3 (сын человека 2):\n";
    Name father3_name;
    InputName(father3_name);
    int father3_height = InputInt("Рост: ");
    auto father3 = std::make_shared<Person>(father3_name, father3_height, father2);

    std::cout << "\nЛюди с родителями:\n";
    std::cout << father1->ToString() << "\n" << father2->ToString() << "\n" << father3->ToString() << std::endl;

    std::cout << "\nЗадача 4 - Кот мяукает.\n";
    std::cout << "Введите имя кота: ";
    std::string cat_name;
    std::getline(std::cin, cat_name);
    Cat cat(cat_name);

    cat.Meow();
    int meow_count = InputInt("Введите, сколько раз кот должен мяукать: ");
    cat.Meow(meow_count);

    std::cout << "\nЗадача 5 - Города.\n";

    std::cout << "Введите название города 1: ";
    std::string city1_name;
    std::getline(std::cin, city1_name);
    City city1(city1_name);

    std::cout << "Введите название города 2: ";
    std::string city2_name;
    std::getline(std::cin, city2_name);
    City city2(city2_name);

    std::cout << "Введите название города 3: ";
    std::string city3_name;
    std::getline(std::cin, city3_name);
    City city3(city3_name);

    int cost12 = InputInt("Введите стоимость пути из города 1 в город 2: ");
    int cost13 = InputInt("Введите стоимость пути из города 1 в город 3: ");

    city1.AddPath(&city2, cost12);
    city1.AddPath(&city3, cost13);

    std::cout << "\nГород 1: " << city1.ToString() << std::endl;
    std::cout << "Город 2: " << city2.ToString() << std::endl;
    std::cout << "Город 3: " << city3.ToString() << std::endl;

    return 0;
}
