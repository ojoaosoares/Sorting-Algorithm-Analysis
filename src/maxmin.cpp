#include "maxmin.hpp"

template <typename T>
void maxMin(T array[], long long n, T &max, T &min)
{
    if (n == 1) { max = array[0]; min = array[0]; } 

    else if (n > 1)
    {
        if (array[0] >= array[1])
        {
            max = array[0];
            min = array[1];
        }

        else
        {
            max = array[1];
            min = array[0];
        }

        int i;

        for (i = 2; i + 1 < n; i+= 2)
        {
            if (array[i] >= array[i + 1])
            {
                if (array[i] > max) max = array[i];
                if (array[i + 1] < min) min = array[i + 1];
            }

            else
            {
                if (array[i + 1] > max) max = array[i + 1];
                if (array[i] < min) min = array[i];
            }
        }

        i--;

        if (i < n)
        {
            if (array[i] > max) max = array[i];
            else if(array[i] < min) min = array[i];
        }
    }

    

}

template void maxMin<long long>(long long array[], long long n, long long &max, long long &min);
template void maxMin<int>(int array[], long long n, int &max, int &min);
template void maxMin<double>(double array[], long long n, double &max, double &min);
