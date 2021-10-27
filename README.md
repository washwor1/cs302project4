Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]


Compiling the generate_map:
g++ -g -Wall -std=gnu++11 -o generate_map generate_map.cpp

Benchmark:
| N    	| Elapsed Time 	| Memory Usage (kybtes) 	|
|------	|--------------	|-----------------------	|
| 10   	| 0:00.03      	| 1588                  	|
| 20   	| 0:00.03      	| 1596                  	|
| 50   	| 0:00.03      	| 1648                  	|
| 100  	| 0:00.03      	| 1776                  	|
| 200  	| 0:00.04      	| 2196                  	|
| 500  	| 0:00.49      	| 4036                  	|
| 1000 	| 0:01.72      	| 11392                 	|
