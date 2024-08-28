
        int rem = y%k;
        int first = y+(k-rem);
        if(y+first > n){
            print(-1);
            return;