#include <iostream>
#include <memory>
#include <string>
#include "name.h"
#include "person.h"
#include "cat.h"
#include "city.h"

void InputName(Name& name) {
    std::string first, surname, patronymic;

    std::cout << "������� ������ ��� (�����������): ";
    std::getline(std::cin, first);

    std::cout << "������� ������� (����� �������� ������): ";
    std::getline(std::cin, surname);

    std::cout << "������� �������� (����� �������� ������): ";
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
        std::cout << "������ �����, ������� �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cin.ignore(10000, '\n');  // ������� ������� ������
    return value;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    std::cout << "������ 1 - �������� ����.\n";
    Name n1, n2, n3, n4;
    std::cout << "�������� ����� 1:\n";
    InputName(n1);
    std::cout << "�������� ����� 2:\n";
    InputName(n2);
    std::cout << "�������� ����� 3:\n";
    InputName(n3);
    std::cout << "�������� ����� 4:\n";
    InputName(n4);

    std::cout << "\n�������� �����:\n";
    n1.Print();
    n2.Print();
    n3.Print();
    n4.Print();

    std::cout << "\n������ 2 - �������� ����� � ������� � ������.\n";

    int height1 = InputInt("������� ���� ��� ������� ��������: ");
    int height2 = InputInt("������� ���� ��� ������� ��������: ");
    int height3 = InputInt("������� ���� ��� �������� ��������: ");

    auto p1 = std::make_shared<Person>(n1, height1);
    auto p2 = std::make_shared<Person>(n2, height2);
    auto p3 = std::make_shared<Person>(n3, height3);

    std::cout << "\n����:\n";
    std::cout << p1->ToString() << "\n" << p2->ToString() << "\n" << p3->ToString() << std::endl;

    std::cout << "\n������ 3 - �������� ����� � ����������.\n";

    // ���� ��� ����� � ���������� �����
    std::cout << "������� ������ ��� �������� 1 (����� �����):\n";
    Name father1_name;
    InputName(father1_name);
    int father1_height = InputInt("����: ");
    auto father1 = std::make_shared<Person>(father1_name, father1_height);

    std::cout << "������� ������ ��� �������� 2 (��� �������� 1):\n";
    Name father2_name;
    InputName(father2_name);
    int father2_height = InputInt("����: ");
    auto father2 = std::make_shared<Person>(father2_name, father2_height, father1);

    std::cout << "������� ������ ��� �������� 3 (��� �������� 2):\n";
    Name father3_name;
    InputName(father3_name);
    int father3_height = InputInt("����: ");
    auto father3 = std::make_shared<Person>(father3_name, father3_height, father2);

    std::cout << "\n���� � ����������:\n";
    std::cout << father1->ToString() << "\n" << father2->ToString() << "\n" << father3->ToString() << std::endl;

    std::cout << "\n������ 4 - ��� �������.\n";
    std::cout << "������� ��� ����: ";
    std::string cat_name;
    std::getline(std::cin, cat_name);
    Cat cat(cat_name);

    cat.Meow();
    int meow_count = InputInt("�������, ������� ��� ��� ������ �������: ");
    cat.Meow(meow_count);

    std::cout << "\n������ 5 - ������.\n";

    std::cout << "������� �������� ������ 1: ";
    std::string city1_name;
    std::getline(std::cin, city1_name);
    City city1(city1_name);

    std::cout << "������� �������� ������ 2: ";
    std::string city2_name;
    std::getline(std::cin, city2_name);
    City city2(city2_name);

    std::cout << "������� �������� ������ 3: ";
    std::string city3_name;
    std::getline(std::cin, city3_name);
    City city3(city3_name);

    int cost12 = InputInt("������� ��������� ���� �� ������ 1 � ����� 2: ");
    int cost13 = InputInt("������� ��������� ���� �� ������ 1 � ����� 3: ");

    city1.AddPath(&city2, cost12);
    city1.AddPath(&city3, cost13);

    std::cout << "\n����� 1: " << city1.ToString() << std::endl;
    std::cout << "����� 2: " << city2.ToString() << std::endl;
    std::cout << "����� 3: " << city3.ToString() << std::endl;

    return 0;
}
