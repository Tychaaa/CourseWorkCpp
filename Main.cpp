#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Bestiary.h"
#include "Function.h"
#include "CombatSystem.h"


using namespace std;


int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");

    //������� ����
    mainMenu();

    // ������� ������ ���������
    Character mainCharacter = createMainCharacter();

    //// ����� "����������"
    //introduction(mainCharacter);

    //// ����� "������"
    //prologue(mainCharacter);

    //// ������� ��������� �������
    //Location emerdealLocation("�.��������", "����� ������������� ������������� ����������� ��� �����������, �� �������� � ������� �� ������������ ������������ ���� � ��� ������������.\n�������� - �����, ��� ���������� ������� �������, � ������ �������� ������� �������� ����� ������������.");

    //// ��������� ������� �����������
    //createEmerdealNPC(emerdealLocation, mainCharacter);

    //// ������� �������
    //gameTitle();

    //// ������ � ��������� �������
    //emerdealLocation.onEnter();

    // ������ ���������� ���
    combatTraining(mainCharacter);

    return 0;
}