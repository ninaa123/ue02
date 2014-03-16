set terminal epslatex color colortext 'phv,9' header '\definecolor{tics}{rgb}{0,0,0}'

#----
set style line 1 lc rgb '#00BFFF' lt 1 lw 2 # deepskyblue (hellblau)
set style line 2 lc rgb '#1874CD' lt 1 lw 2 # dodgerblue (mittelblau)
set style line 3 lc rgb '#0000FF' lt 1 lw 2 # blue (blau), kreuz

set style line 4 lc rgb '#32CD32' lt 1 lw 2 # limegreen (hellgr¸n)
set style line 5 lc rgb '#008B00' lt 1 lw 2 # green (dunkelgr¸n), kreuz

set style line 6 lc rgb '#FF4500' lt 1 lw 2 # orangered (rot) 
set style line 7 lc rgb '#CD0000' lt 1 lw 2 # red (dunkelrot)
set style line 8 lc rgb '#E066FF' lt 1 lw 2 # mediumorchid (hellila) 
set style line 9 lc rgb '#9400D3' lt 1 lw 2 # darkviolet (dunkellila) 
set style line 10 lc rgb '#AB82FF' lt 1 lw 2 # mediumpurple (hellviolett)
set style line 11 lc rgb '#CD00CD' lt 1 lw 2 # magenta (magenta)
set style line 12 lc rgb '#FF7F00' lt 1 lw 2 # darkorange (orange)
#----

#point type: x

set style line 13 lc rgb '#00BFFF' pt 2 lw 2 # deepskyblue (hellblau)
set style line 14 lc rgb '#1874CD' pt 2 lw 2 # dodgerblue (mittelblau)
set style line 15 lc rgb '#0000FF' pt 2 lw 2 # blue (blau)

set style line 16 lc rgb '#32CD32' pt 2 lw 2 # limegreen (hellgr¸n)
set style line 17 lc rgb '#008B00' pt 2 lw 2 # green (dunkelgr¸n)

set style line 18 lc rgb '#FF4500' pt 2 lw 2 # orangered (rot) 
set style line 19 lc rgb '#CD0000' pt 2 lw 2 # red (dunkelrot)
set style line 20 lc rgb '#E066FF' pt 2 lw 2 # mediumorchid (hellila) 
set style line 21 lc rgb '#9400D3' pt 2 lw 2 # darkviolet (dunkellila) 
set style line 22 lc rgb '#AB82FF' pt 2 lw 2 # mediumpurple (hellviolett)
set style line 23 lc rgb '#CD00CD' pt 2 lw 2 # magenta (magenta)
set style line 24 lc rgb '#FF7F00' pt 2 lw 2 # darkorange (orange)

#----

#point type: filled circle

set style line 25 lc rgb '#00BFFF' pt 7 lw 2 # deepskyblue (hellblau)
set style line 26 lc rgb '#1874CD' pt 7 lw 2 # dodgerblue (mittelblau)
set style line 27 lc rgb '#0000FF' pt 7 ps 0.5 # blue (blau)

set style line 28 lc rgb '#32CD32' pt 7 lw 2 # limegreen (hellgr¸n)
set style line 29 lc rgb '#008B00' pt 7 lw 2 # green (dunkelgr¸n)

set style line 30 lc rgb '#FF4500' pt 7 lw 2 # orangered (rot) 
set style line 31 lc rgb '#CD0000' pt 7 lw 2 # red (dunkelrot)
set style line 32 lc rgb '#E066FF' pt 7 lw 2 # mediumorchid (hellila) 
set style line 33 lc rgb '#9400D3' pt 7 lw 2 # darkviolet (dunkellila) 
set style line 34 lc rgb '#AB82FF' pt 7 lw 2 # mediumpurple (hellviolett)
set style line 35 lc rgb '#CD00CD' pt 7 lw 2 # magenta (magenta)
set style line 36 lc rgb '#FF7F00' pt 7 lw 2 # darkorange (orange)

set grid
unset key

set output "plot2a.eps"
plot "dat.txt" u 1:2 ls 25

set style data histogram
set style histogram cluster gap 1
set boxwidth 0.9
set auto x
set xrange[-1:10]

set output "plot1a.eps"
plot "counter.txt" u 2 ls 2 t "number of random number per bin" fill pattern