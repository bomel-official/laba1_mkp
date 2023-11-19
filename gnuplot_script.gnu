set terminal png
set output 'lunar_anomalies_plot.png'
set title 'Lunar Anomalies vs Time'
set xlabel 'Time (s)'
set ylabel 'Anomaly (radians)'
plot 'plot_data.txt' using 1:2 with lines title 'Mean Anomaly (M)', 'plot_data.txt' using 1:3 with lines title 'Eccentric Anomaly (E)', 'plot_data.txt' using 1:4 with lines title 'True Anomaly (θ)'
