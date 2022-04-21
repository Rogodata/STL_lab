#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "extension.hpp"
#include "subvector.h"

using namespace std;

long const MAX_N = 10000000; //Максимальное количество элементов в контейнере
long const SHAG = 10000; // Шаг изменения size

//Среднее время удаления элемента из произвольного места вектора. Ре-
//ализуйте для своего контейнера erase, измерьте среднее время для раз-
//личного размера контейнера (size) при вставке в произвольное место,
//сравните со стандартным контейнером


int main() {
    std::ofstream file_out("task_2.txt");
    Timer t;
    Utils util(0, 100);
    for ( long i = SHAG; i < MAX_N; i += SHAG) {
        //Создаём вектор из одинаковых элементов
        std::vector<long> test(i);
        unsigned long long all_time = 0;
        long inserts_num = sqrt(i) / 10;
        long norm_num = inserts_num;
        for (long j = 1; j < inserts_num; j ++) {
            util.change_uni(0, i - j - 1);
            long position = util.get_rand_long();
            auto pos = test.begin() + position;
            t.start();
            test.erase(pos);
            t.stop();
            long elapsed_time = t.elapsed();
            std::cout << elapsed_time << endl;
            if (elapsed_time != 0) {
                all_time += elapsed_time;
            }
            else{
                norm_num --;
            }
        }
        all_time /= norm_num;
        file_out << i << " " << all_time << endl;
        cout << "here00000000000000000000000000000000" << endl;
    }
    file_out.close();
    return 0;
}