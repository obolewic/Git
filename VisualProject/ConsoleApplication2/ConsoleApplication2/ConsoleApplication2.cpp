// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// you can also use includes, for example:
#include <algorithm>
#include <vector>  

int solution(int K, const std::vector<int> &A) {
    // write your code in C++98
    int result = 0;
    //long long int sum = 0;
    int elementsCount = A.size();
    std::sort(A.begin(), A.end());
    for (int i = 0 ; i< elementsCount-1 ; ++i){
        if (A[i] > K) break;
        for (int j=i+1 ; j < elementsCount ; ++j){
           if (A[i]+A[j] > K) break;
           else
               if (A[i]+A[j] == K) ++result;
        }
    }
    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

