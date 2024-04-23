#include <iostream>
#include <string>

using namespace std;

class Enemy{
protected:
    string name;
    int attackPower;

public:
    // Êîíñòðóêòîð
    Enemy(const string& _name, int _attackPower) : name(_name), attackPower(_attackPower){}

    virtual void attack() const = 0;

    // Äåñòðóêòîð
    virtual ~Enemy(){}
};

class Lancer : public Enemy{
public:
    // Êîíñòðóêòîð
    Lancer(const string& _name, int _attackPower) : Enemy(_name, _attackPower){}

    // Ïåðåîïðåäåëåíèå ôóíêöèè attack
    void attack() const override{
        cout << "Ðûöàðü " << name << " àòàêóåò" << endl;
    }
};

class Dragon : public Enemy{
public:
    // Êîíñòðóêòîð
    Dragon(const string& _name, int _attackPower) : Enemy(_name, _attackPower){}

    // Ïåðåîïðåäåëåíèå ôóíêöèè attack
    void attack() const override{
        cout << "Äðàêîí " << name << " àòàêóåò" << endl;
    }
};

int main() {
    // Ìàññèâ ïåðñîíàæåé
    const int numEnemies = 3;
    Enemy* enemies[numEnemies];
    enemies[0] = new Lancer("Ëàíñåð1", 10);
    enemies[1] = new Dragon("Äðàêîí1", 20);
    enemies[2] = new Lancer("Ëàíñåð2", 15);

    for (int i = 0; i < numEnemies; ++i){
        cout << "Ïåðñîíàæ " << i + 1 << ": " << endl;
        enemies[i]->attack();
    }

    enemies[0]->attack();
    enemies[1]->attack();

    return 0;
}
