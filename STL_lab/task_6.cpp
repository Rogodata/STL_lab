#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <forward_list>
#include <algorithm>
#include "extension.hpp"
#include "subvector.h"
#include "subforward_list.h"

using namespace std;

long const MAX_N = 100000000; //Максимальное количество элементов в контейнере
long const SHAG = 10000; // Шаг изменения size

//Среднее время удаления элемента из произвольного места вектора. Ре-
//ализуйте для своего контейнера erase, измерьте среднее время для раз-
//личного размера контейнера (size) при вставке в произвольное место,
//сравните со стандартным контейнером


int main() {
    std::ofstream file_out("task.txt");
    Timer t;
    Utils util(0, 100);
    for ( long i = SHAG; i < MAX_N; i += SHAG) {
        std::forward_list<long> test;
        t.start();
        test.pop_front();
        t.stop();
        unsigned long long all_time = t.elapsed();
        file_out << i << " " << all_time << endl;
        cout << "here00000000000000000000000000000000" << endl;
    }
    file_out.close();
    return 0;
}
