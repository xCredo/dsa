#!/usr/bin/gnuplot

set termoption enhanced
set terminal png size 2560,1440 font "Arial, 16"
set output "plot.png"

set style line 1 lc rgb "0xDC143C" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x6495ED" lt 1 lw 4 pt 7 ps 1
set style line 3 lc rgb "0x008000" lt 1 lw 4 pt 5 ps 1

set border lw 3
set grid
set key top left

set xlabel "Number of elements in the array"
set ylabel "Execution time, s" rotate by 90
set xtics 100000
set mxtics
set format x "%6.0f"
set format y "%.2f"

plot 'Quick_Sort.txt' using 1:2 title "Quick Sort" with linespoints ls 1, 'Radix_Sort.txt' using 1:2 title "Radix Sort" with linespoints ls 2, 'Selection_Sort.txt' using 1:2 title "Selection Sort" with linespoints ls 3

/*gnuplot --persist graph.gp*/