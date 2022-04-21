//
// Created by yalavrinenko on 27.09.2021.
//

#ifndef SORTS_EXTENSION_HPP
#define SORTS_EXTENSION_HPP

#include <random>
#include <chrono>

class Timer{
public:
  void start() {
    start_ = current_time();
  }
  void stop() {
    stop_ = current_time();
  }
  unsigned long long elapsed() const{
      return std::chrono::duration_cast<std::chrono::nanoseconds>(stop_ - start_).count();
  }

private:
  static std::chrono::steady_clock::time_point current_time() {
    return std::chrono::steady_clock::now();
  }

  std::chrono::steady_clock::time_point start_, stop_;
};

class Utils {
public:
    Utils()= default;

    Utils(long start, long end){
        this->uni_= std::uniform_int_distribution<long>{start, end};
    }

    template <typename STL_cont>
    void generate_data(STL_cont& container, unsigned long long int N);

    long get_rand_long(){
        return uni_(engine_);
    }

    void change_uni(long start, long end){
        uni_= std::uniform_int_distribution<long>{start, end};
    }

  //static bool check_order(long const *array, unsigned long long N);

private:
  std::mt19937_64 engine_{std::random_device{}()};
  std::uniform_int_distribution<long> uni_;
};

template <typename STL_cont>
void Utils::generate_data(STL_cont& container, unsigned long long int N) {
  Timer t;
  t.start();

  for (auto i = 0ul; i < N; ++i)
    container[i] = uni_(engine_);

  t.stop();
  std::cout << "Generated " << N << " elements. Elapsed time: " << t.elapsed() << " microseconds." << std::endl;
}

template <typename out_type_x, typename out_type_y>
void file_print(const std::string& filename, const out_type_x& entity_x, const out_type_y entity_y){
    std::ofstream fout(filename); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    fout << entity_x << " " << entity_y << std::endl; // запись строки в файл
    fout.close(); // закрываем файл
}

/*bool Utils::check_order(long const *array, unsigned long long int N) {
  for (auto i = 1; i < N; ++i)
    if (array[i - 1] > array[i]) {
      std::cout << "*****" << array[i - 1] << " is grater than " << array[i] << std::endl;
      return false;
    }

  return true;
}*/

#endif //SORTS_EXTENSION_HPP
