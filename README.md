# Sorting Algorithms

`Code/Code_Sorting.cpp` draws six sorts as bar charts with the old Borland graphics interface (`graphics.h`).

After you type the length and the values, it runs each algorithm on a copy of that array and redraws the bars:

1. Bubble sort
2. Selection sort
3. Merge sort
4. Heap sort
5. Radix sort (counting sort by digit)
6. Timsort (insertion sort on runs of 32, then merge)

`printarray` highlights two index ranges while a step runs. `printarray2` redraws the finished array and pauses.

## Build

This file is not a standard Linux C++ program. It calls `initgraph` with `C:\TC\BGI`, `initwindow`, `delay`, and `getch`, and it includes `direct.h`. Build it with a WinBGIm or Turbo C setup that provides `graphics.h`, on Windows.

A screen recording of the charts is at https://photos.app.goo.gl/HZUCkEQLbtJRqnp98.
