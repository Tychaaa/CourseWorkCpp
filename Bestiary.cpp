#include "Bestiary.h"

Wolf::Wolf() : Character() {
}

Wolf::Wolf(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr) {
Wolf::Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // ������������� ����� � ��������� �����������
}

Wolf::~Wolf() {
}

void Wolf::regenerateStamina()
{
    if (stamina < maxStamina) {
        stamina += 10;
        if (stamina > maxStamina) {
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
}

void Wolf::bite(Character& target) {
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 15; // ������ ���� ����� �������
        cout << this->getName() << " � ����� ������ " << target.getName() << endl;
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " �������� ������� � �������� ���������.\n";
    }
}

void Wolf::clawAttack(Character& target) {
    int staminaCost = 20; // ��������� ������������ ��� ����� �������

    if (getStamina() >= staminaCost) {
        int damage = 10; // ������ ���� ����� �������
        cout << this->getName() << " ����� � ������� ������� ���� ������� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� � ���������, ���������, ��� �� � ��������� ������� ���� �������.\n";
    }
}

void Wolf::attack(Character& target) {
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

    if (choice <= 25) {
        this->clawAttack(target);
    }
    else {
        this->bite(target);
    }
}


Ogre::Ogre() : Character() {
}

Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon)
    : Character(name, health, stamina, mana, weapon, nullptr) {
Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // ������������� ���� � ��������� �����������
}

Ogre::~Ogre() {
}

void Ogre::regenerateStamina()
{
    if (stamina < maxStamina) {
        stamina += 10;
        if (stamina > maxStamina) {
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
}

void Ogre::smash(Character& target) {
    int staminaCost = 30; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 25;
        cout << this->getName() << " ����������� �������� � ������� �������������� ���� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ��������� ��������� � �� ����� ��������� ���� � ������ �����.\n";
    }
}

void Ogre::groundPound(Character& target) {
    int staminaCost = 50; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " ������� ������ ���� � �����, ����������� �����, ������ " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������ ������� �����. ��� �� ������� ������������.\n";
    }
}

void Ogre::fistAttack(Character& target) {
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ����� ������� � �������� ���������.\n";
    }
}

void Ogre::attack(Character& target) {
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

    if (choice <= 40) {
        this->fistAttack(target);
    }
    else if (choice > 40 && choice <= 80) {
        this->groundPound(target);
    }
    else {
        this->smash(target);
    }
    
}