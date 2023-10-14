#include "../include/errorTreatment.h"

void checkEntryArgs(string p, string s) {
    int pSize = p.size();
    int sSize = s.size();
    if (pSize > 1000000 || sSize > 100) {
        throw new invalid_argument("Args with invalid size.");
    }
}