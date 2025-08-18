void search() {
    int small = 0;
    int large = 100;
    while (large - small > 1) {
        int mid = (small + large)/2;
        if (isLarge(mid)) {
            large = mid;
        } else { // isSmall(mid)
            small = mid;
        }
    }
    // large == small + 1
    // small es el ultimo que no cumple
    // large es el primero que cumple
}
