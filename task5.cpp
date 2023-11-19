#include <iostream>
#include <fstream>
#include <string>

// Подключение библиотеки Gnuplot
#include "gnuplot-iostream.h"

int main() {
    // Создание объекта для работы с Gnuplot
    Gnuplot gp;

    // Создание временного файла для данных
    std::ofstream data("plot_data.txt");
    
    // Расчет и запись данных
    for (double t = 0; t <= 2 * M_PI; t += 0.01) {
        double mean_anomaly = 2 * M_PI * t / (27.322 * 24 * 3600);  // Пример значения периода обращения Луны
        double eccentric_anomaly = mean_anomaly;  // Пример значения эксцентриситета
        double true_anomaly = 2 * atan2(sqrt(1 + 0.2) * sin(eccentric_anomaly / 2), sqrt(1 - 0.2) * cos(eccentric_anomaly / 2));  // Пример значения эксцентриситета

        data << t << " " << mean_anomaly << " " << eccentric_anomaly << " " << true_anomaly << std::endl;
    }

    // Закрытие файла
    data.close();

    // Построение графика
    gp << "set terminal png\n";
    gp << "set output 'lunar_anomalies_plot.png'\n";
    gp << "set title 'Lunar Anomalies vs Time'\n";
    gp << "set xlabel 'Time (s)'\n";
    gp << "set ylabel 'Anomaly (radians)'\n";
    gp << "plot 'plot_data.txt' using 1:2 with lines title 'Mean Anomaly (M)', "
       << "'plot_data.txt' using 1:3 with lines title 'Eccentric Anomaly (E)', "
       << "'plot_data.txt' using 1:4 with lines title 'True Anomaly (θ)'\n";

    return 0;
}