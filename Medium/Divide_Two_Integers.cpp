int divide(int dividend, int divisor) {
		if(divisor==-1 && dividend == INT_MIN)
			return INT_MAX;
		bool sign = (dividend>=0) == (divisor>=0) ? true : false;
		long int did = abs(dividend);
		long int div = abs(divisor);
		long int result=0;
		// int count=0, temp=divisor;
		while(did - div >= 0){
			int count=0;
			while((did - (div<<1<<count))>=0)
				count++;
			result += 1<<count;
			did -= div<<count;
		}
		return sign ? result : -result;
	}
