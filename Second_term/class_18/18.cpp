#include <iostream>
#include <string>

using namespace std;

class Enemy {
protected:
    string name;
    int attackPower;

public:
    // Конструктор
    Enemy(const string& _name, int _attackPower) : name(_name), attackPower(_attackPower) {}

    virtual void attack() const = 0;

    // Виртуальный деструктор
    virtual ~Enemy() {}
};

class Lancer : public Enemy {
public:
    // Конструктор
    Lancer(const string& _name, int _attackPower) : Enemy(_name, _attackPower) {}

    // Переопределение функции attack
    void attack() const override {
        cout << "Рыцарь " << name << " атакует" << endl;
    }
};

// Класс Dragon, наследующийся от Enemy
class Dragon : public Enemy {
public:
    // Конструктор
    Dragon(const string& _name, int _attackPower) : Enemy(_name, _attackPower) {}

    // Переопределение функции attack
    void attack() const override {
        cout << "Дракон " << name << " атакует" << endl;
    }
};

int main() {
    // Массив персонажей
    const int numEnemies = 3;
    Enemy* enemies[numEnemies];
    enemies[0] = new Lancer("Лансер1", 10);
    enemies[1] = new Dragon("Дракон1", 20);
    enemies[2] = new Lancer("Лансер2", 15);

    for (int i = 0; i < numEnemies; ++i) {
        cout << "Персонаж " << i + 1 << ": " << endl;
        enemies[i]->attack();
    }

    enemies[0]->attack();
    enemies[1]->attack();

    return 0;
}