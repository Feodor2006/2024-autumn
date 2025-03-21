#include<string>
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

struct Student
{
    string name;
    int hp;
    int dmg;
    int luck;

    Student(string name, int hp = 100, int dmg = 5, int luck = 10) :
        name(name), hp(hp), dmg(dmg), luck(luck)
    {
    }

    Student(const Student& student) :
        name(student.name),
        hp(student.hp),
        dmg(student.dmg),
        luck(student.luck)
    {}

    ~Student()
    {
    }

    bool luckWorks()
    {
        return (rand() % 100 < luck);
    }

    bool isDead()
    {
        return (hp < 1);
    }

    void getDmg(int dmg)
    {
        if (luckWorks())
        {
            cout << "\t" << name << " LUCK WORKS FOR GETTING DAMAGE\n";
            dmg /= 2;
        }
        hp -= dmg;
    }

    int makeDmg()
    {
        if (luckWorks())
        {
            cout << "\t" << name << " LUCK WORKS FOR MAKING DAMAGE\n";
            return dmg * 2;
        }
        else
        {
            return dmg;
        }
    }

    void print()
    {
        cout << name << " [" << hp << "] (";
        cout << "luck=" << luck << ";";
        cout << "damage=" << dmg << ")\n";
    }
};

void battle(vector<Student>& students)
{
    int round = 1;

    while (students.size() > 1)
    {
        cout << "\t\tROUND " << round++ << "\n";

        for (size_t i = 0; i < students.size(); ++i)
        {
            students[i].print();
            cout << "versus\n";
            students[(i + 1) % students.size()].print();

            // Attack
            students[i].getDmg(students[(i + 1) % students.size()].makeDmg());
            students[(i + 1) % students.size()].getDmg(students[i].makeDmg());
        }

        // Remove dead students
        for (auto it = students.begin(); it != students.end(); )
        {
            if (it->isDead())
            {
                cout << it->name << " has been defeated!\n";
                it = students.erase(it);
            }
            else
            {
                ++it;
            }
        }

        cout << "\n";
    }

    if (students.size() == 1)
    {
        cout << students[0].name << " wins\n";
    }
    else
    {
        cout << "DRAW\n";
    }
}

int main()
{
    srand(time(0));
    vector<Student> students = {
        Student("Alice", 100, 10, 20),
        Student("Bob", 90, 12, 15),
        Student("Charlie", 80, 8, 25),
        Student("Diana", 70, 14, 10),
        Student("Ethan", 110, 9, 5),
        Student("Fern", 120, 7, 30),
        Student("George", 130, 11, 15),
        Student("Hannah", 100, 10, 20),
        Student("Ian", 90, 8, 25),
        Student("Judy", 80, 12, 10)
    };

    battle(students);
    return 0;
}