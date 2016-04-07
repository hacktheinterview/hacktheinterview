
bool Solution::isPower(int a) {
if (a == 1) {
       return true;
    }
    for (int x = 2; x <= sqrt(a); x++) {
        for (int y = 2; pow(x, y) <= a; y++) {
            if (pow(x, y) == a)
                return true;
        }
    }
    return false;
}

