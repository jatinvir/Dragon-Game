#include "gold.h"
#include "dragon.h"

Gold::Gold(int x, int y, int val, Dragon *d): x{x}, y{y}, val{val}, d{d} {}
Gold::Gold(int x, int y, Dragon *d): x{x}, y{y}, val{6}, d{d} {}
Gold::Gold(int x, int y, int val): x{x}, y{y}, val{val}, d{nullptr} {}

Gold::~Gold() {
    if (d) d->setGoldPtr(nullptr);
}
