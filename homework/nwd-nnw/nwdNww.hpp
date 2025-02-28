#pragma once

int NWD(int lhs, int rhs) {
    if (lhs == 0)
        return rhs;
    if (rhs == 0)
        return lhs;
    if (lhs == 0 && rhs == 0)
        return 0;
    if (lhs < 0)
        lhs *= -1;
    if (rhs < 0)
        rhs *= -1;
    while (lhs != rhs)
        if (lhs > rhs)
            lhs -= rhs;
        else
            rhs -= lhs;
    return rhs;
}

int NWW(int lhs, int rhs) {
    // TODO: Implement me :)
    return -1;
}
