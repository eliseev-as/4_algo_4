#include <iostream>
using namespace std;

// Сравнить занятия по времени окончания
bool compare(const pair<int, int> &left, const pair<int, int> &right) {
    return left.second < right.second;
}

// Получить максимальное количество занятий
int getMaxClasses(vector<pair<int, int> > classes) {
    // Количество занятий
    int count = 0;
    // Время окончания последнего добавленного занятия
    int endClass = 0;

    // Сортируем занятия по времени окончания
    ranges::sort(classes, compare);

    // Перебираем отсортированный по времени окончания список занятий
    for (const auto [begin, end]: classes) {
        // Если время начала текущего занятия меньше времени окончания последнего добавленного занятия,
        // то такое занятие пропускаем
        if (begin < endClass) {
            continue;
        }

        // Обновляем время окончания последнего добавленного занятия
        endClass = end;
        count += 1;
        cout << "Добавлено занятие: " << begin << ":" << end << endl;
    }

    return count;
}

int main() {
    const vector<pair<int, int> > classes = {
        {8, 14},
        {9, 11},
        {9, 15},
        {11, 12},
        {11, 13},
        {13, 17},
        {14, 16},
        {17, 21},
        {18, 20}
    };
    cout << "Список занятий: " << endl;
    for (const auto [begin, end]: classes) {
        cout << "Интервал времени: " << begin << ":" << end << endl;
    }

    cout << endl << "Рассчитываем максимальное количество занятий: " << endl;
    const int maxClasses = getMaxClasses(classes);
    cout << endl << "Максимальное количество занятий: " << maxClasses << endl;

    return 0;
}
