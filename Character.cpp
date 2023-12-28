#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

// �����������
Character::Character() : name(""), health(0), stamina(0), mana(0), level(1), experience(0), classType("") {
    maxHealth = 0;
    maxStamina = 0;
    maxMana = 0;
}

// ����������� � �����������
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic), classType(classtype) {
    maxHealth = health;
    maxStamina = health;
    maxMana = health;
}

// ����������
Character::~Character(){}

// �������
string Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return health;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getMana() const
{
    return mana;
}

// ������ ��� ������� � ������������ ���������
int Character::getMaxHealth() const
{
    return maxHealth;
}

int Character::getMaxStamina() const
{
    return maxStamina;
}

int Character::getMaxMana() const
{
    return maxMana;
}


int Character::getLevel() const
{
    return level;
}

int Character::getExperience() const
{
    return experience;
}

string Character::getClassType() const
{
    return classType;
}

Weapon* Character::getWeapon() const
{
    return weapon;
}

Magic* Character::getMagic() const
{
    return magic;
}

// �������
void Character::setName(string newName)
{
    name = newName;
}

void Character::setHealth(int newHealth)
{
    health = newHealth;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

void Character::setMana(int newMana)
{
    mana = newMana;
}

void Character::setMaxHealth(int value)
{
    maxHealth = value;
}

void Character::setMaxStamina(int value)
{
    maxStamina = value;
}

void Character::setMaxMana(int value)
{
    maxMana = value;
}

void Character::setLevel(int newLevel)
{
    level = newLevel;
}

void Character::setExperience(int newExp) {
    experience += newExp;
    while (experience >= 100) {
        levelUp();
        experience -= 100; // ��������� ���� �� 100 ����� ��������� ������
    }
}

void Character::setClassType(string newClass)
{
    classType = newClass;
}

void Character::setWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

void Character::setMagic(Magic* newMagic)
{
    magic = newMagic;
}

void Character::attack(Character& target) {
    if (weapon) {
        cout << name << " ������� " << target.name << ", ��������� " << weapon->getName() << ".\n";
        target.takeDamage(weapon->getDamage());
        decreaseStamina(weapon->getCost());
    }
    else {
        cout << "� " << name << " ��� ������ ��� �����!\n";
    }
}

void Character::castSpell(Character& target) {
    if (magic) {
        std::cout << name << " ������� " << magic->getName() << " �� " << target.name << ".\n";
        target.takeDamage(magic->getDamage());
        decreaseMana(magic->getCost());
    }
    else {
        cout << "� " << name << " ��� ����� ��� �����!\n";
    }
}

void Character::takeDamage(int dmg) {
    health -= dmg;
    cout << name << " ������� " << dmg << " ����a.\n";
}

void Character::decreaseStamina(int cost) {
    stamina -= cost;
    //cout << "������������ " << name << " ���������� �� " << cost << ".\n";
}

void Character::decreaseMana(int cost) {
    mana -= cost;
    //cout << "���� " << name << " ���������� �� " << cost << ".\n";
}

void Character::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 10 + 5 * level;
        if (stamina > maxStamina) {
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
}

void Character::regenerateMana() {
    if (mana < maxMana) {
        mana += 10 + 5 * level;
        if (mana > maxMana) {
            mana = maxMana; // ������������� �������� ���� � ��������, ���� ���������
        }
    }
}

void Character::levelUp() {
    level++; // ����������� ������� �� ����

    // ����������� ��������, ������������, ���� � �.�. �� ������������ ���������� ��� ���������� ������ ������
    maxHealth += 10;
    maxStamina += 5;
    maxMana += 8;
    health = maxHealth;
    stamina = maxStamina;
    mana = maxMana;

    // ������� ��������� � ��������� ������ ���������
    cout << "������� ����� " << name << " ������� �� " << level << "!\n";
    cout << "�������� ��������� �� " << health << "\n ������������ ��������a �� " << stamina << "\n���� ��������a �� " << mana << ".\n";
}