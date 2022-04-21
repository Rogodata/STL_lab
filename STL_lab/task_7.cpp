#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <forward_list>
#include "extension.hpp"

using namespace std;

long const MAX_N = 10000000; //Максимальное количество элементов в контейнере
long const SHAG = 10000; // Шаг изменения size


int main() {
    std::ofstream file_out("task.txt");
    Timer t;
    Utils util(0, 100);
    for (long i = SHAG; i < MAX_N; i += SHAG) {
        list<long> test(i);
        long norm_num = i;
        t.start();
        for (auto &element: test) element += 1; {
        }
        t.stop();
        long elapsed_time = t.elapsed();
        std::cout << elapsed_time << endl;
        file_out << i << " " << elapsed_time << endl;
        cout << "here00000000000000000000000000000000" << endl;
    }
    file_out.close();
    return 0;
}