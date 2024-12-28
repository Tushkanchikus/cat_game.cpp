#include <iostream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time() (инициализация генератора случайных чисел)
#include <string>
using namespace std;

// Структура, описывающая кошку
struct Cat {
    int hunger;      // Уровень голода кошки
    int happiness;   // Уровень счастья кошки
    int energy;      // Уровень энергии кошки
    int health;      // Уровень здоровья кошки
    string state;    // Состояние кошки для отображения ASCII-арта
};

// Функция для инициализации кошки
void InitializeCat(Cat& cat) {
    cat.hunger = 50;
    cat.happiness = 50;
    cat.energy = 50;
    cat.health = 50;
    cat.state = "neutral"; // Начальное состояние кошки
}

// Функция для отображения состояния кошки в виде ASCII-арта
void ShowCatStatus(const Cat& cat) {
    cout << "\nCat's Status:\n";
    cout << "Hunger: " << cat.hunger << "\n";
    cout << "Happiness: " << cat.happiness << "\n";
    cout << "Energy: " << cat.energy << "\n";
    cout << "Health: " << cat.health << "\n";

    // Отображаем ASCII-арт в зависимости от состояния кошки
    if (cat.state == "happy") {
        cout << "  /\\_/\\  \n ( ^.^ )  \n  (   )   \n";
    }
    else if (cat.state == "sad") {
        cout << "  /\\_/\\  \n ( T_T )  \n  (   )   \n";
    }
    else if (cat.state == "sleeping") {
        cout << "  /\\_/\\  \n ( -.- )  \n  ( Z )   \n";
    }
    else {
        cout << "  /\\_/\\  \n ( o.o )  \n  (   )   \n";
    }
}

// Функция для случайных событий
void RandomEvent(Cat& cat) {
    int event = rand() % 5; // Генерация случайного числа от 0 до 4

    if (event == 0) {
        cat.happiness += 10;
        cat.state = "happy"; // Кошка поймала мышь, счастлива
        cout << "The cat caught a mouse! Happiness increased!\n";
    }
    else if (event == 1) {
        cat.health -= 10;
        cat.state = "sad"; // Кошка заболела
        cout << "The cat is sick! Health decreased.\n";
    }
    else if (event == 2) {
        cat.happiness -= 5;
        cat.state = "sad"; // Кошка потеряла игрушку
        cout << "The cat lost its toy! Happiness decreased.\n";
    }
    else if (event == 3) {
        cat.energy += 15;
        cat.state = "sleeping"; // Кошка отдыхает
        cout << "The cat took a nap! Energy increased.\n";
    }
    else {
        cat.happiness += 5;
        cat.state = "neutral"; // Всё в порядке
        cout << "Everything is fine. The cat is neutral.\n";
    }
}

// Функция для кормления кошки
void FeedCat(Cat& cat) {
    if (cat.hunger < 100) {
        cat.hunger += 20;
        if (cat.hunger > 100) cat.hunger = 100;
        cat.happiness += 5;
        cout << "You fed the cat. Hunger decreased, and happiness increased!\n";
    }
    else {
        cout << "The cat is already full!\n";
    }
}

// Функция для игры с кошкой
void PlayWithCat(Cat& cat) {
    if (cat.energy > 10) {
        cat.happiness += 15;
        cat.energy -= 20;
        cout << "You played with the cat. Happiness increased, but energy decreased!\n";
    }
    else {
        cout << "The cat is too tired to play!\n";
    }
}

// Функция для укладывания кошки спать
void PutToSleep(Cat& cat) {
    cat.energy += 30;
    if (cat.energy > 100) cat.energy = 100;
    cat.happiness -= 5;
    cout << "The cat took a nap. Energy increased, but happiness slightly decreased.\n";
}

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел

    Cat myCat;  // Создаём объект кошки
    InitializeCat(myCat);  // Инициализируем кошку с начальными значениями

    int difficulty;
    cout << "Select difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ";
    cin >> difficulty;

    while (true) {
        ShowCatStatus(myCat);  // Показываем текущий статус кошки

        RandomEvent(myCat);  // Случайное событие

        // Спрашиваем у user-а, что он хочет сделать
        cout << "\nWhat do you want to do?\n";
        cout << "1. Feed the cat\n";
        cout << "2. Play with the cat\n";
        cout << "3. Put the cat to sleep\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        // В зависимости от уровня сложности делаем кошку более или менее требовательной
        if (difficulty == 1) {
            if (choice == 1) FeedCat(myCat);
            else if (choice == 2) PlayWithCat(myCat);
            else if (choice == 3) PutToSleep(myCat);
        }
        else if (difficulty == 2) {
            if (choice == 1) FeedCat(myCat);
            else if (choice == 2) PlayWithCat(myCat);
            else if (choice == 3) PutToSleep(myCat);
        }
        else if (difficulty == 3) {
            if (choice == 1) FeedCat(myCat);
            else if (choice == 2) PlayWithCat(myCat);
            else if (choice == 3) PutToSleep(myCat);
        }

        if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

