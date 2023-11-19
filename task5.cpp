#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main() {
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

    // Создание скрипта gnuplot
    std::ofstream gnuplot_script("gnuplot_script.gnu");
    gnuplot_script << "set terminal png\n";
    gnuplot_script << "set output 'lunar_anomalies_plot.png'\n";
    gnuplot_script << "set title 'Lunar Anomalies vs Time'\n";
    gnuplot_script << "set xlabel 'Time (s)'\n";
    gnuplot_script << "set ylabel 'Anomaly (radians)'\n";
    gnuplot_script << "plot 'plot_data.txt' using 1:2 with lines title 'Mean Anomaly (M)', "
                   << "'plot_data.txt' using 1:3 with lines title 'Eccentric Anomaly (E)', "
                   << "'plot_data.txt' using 1:4 with lines title 'True Anomaly (θ)'\n";
    gnuplot_script.close();

    // Выполнение скрипта gnuplot через терминал
    system("gnuplot gnuplot_script.gnu");

    return 0;
}