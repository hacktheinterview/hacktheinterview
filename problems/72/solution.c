
int isPower(int a) {
	if (a == 1) {
       return 1;
    }
    int x, y;
    for (x = 2; x <= sqrt(a); x++) {
        for (y = 2; pow(x, y) <= a; y++) {
            if (pow(x, y) == a)
                return 1;
        }
    }
    return 0;
}

