#ifndef STATS_H
#define STATS_H

class Stats {
public:
    int virtual calcHp() = 0;
    int virtual calcAtk() = 0;
    int virtual calcDef() = 0;
};

#endif
