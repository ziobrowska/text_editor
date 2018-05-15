// Joanna Ziobrowska

#include "kmptextiterator.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int KMPTextIterator::getNext(const std::string & text, const std::string & term, int start_pos) {

        int P[100];

        P[0] = 0;
        P[1] = 0;

        int t = 0;

       int n = text.size();
       int m = term.size();

       for (int j = 2; j <= m; j++){
           while ((t > 0) && (term[t] != term[j - 1])){
               t = P[t];
           }

           if (term[t] == term[j - 1]){
               t++;
           }
           P[j] = t;
       }

       int i = start_pos;
       int j = 0;

       while (i <= n - m + 1){
           j = P[j];

           while((j < m)&&(term[j] == text[i + j - 1])){
               j++;
           }

           if (j == m){
               return i;
           }

           i = i + std::max(1, j - P[j]);
       }

        return -1;
}
