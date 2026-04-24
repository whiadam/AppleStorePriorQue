 for (int i = 0; i < nameCount; ++i) {
        int arrivalNum = rand() % MAX_ARRIVAL_NUM + 1;
        Customer customer(names[i], arrivalNum);
    }