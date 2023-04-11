// Copyright [2023]
#include "TwoDArray.h"
#include <string>
#include <sstream>
#include <iomanip>

void set_row(double *the_array, int row_num, int col_size, double *row_vals)
{
    for (int i = 0; i < col_size; ++i)
    {
        *(the_array + row_num * col_size + i) = *(row_vals + i);
    }
}

double *get_row(double *the_array, int row_num, int col_size)
{
    double *returnArray = new double[col_size];
    for (int i = 0; i < col_size; ++i)
    {
        *(returnArray + i) = *(the_array + i);
    }
    return returnArray;
}

void set_element(double *the_array, int row_num, int col_size, int col_num, double val)
{
    *(the_array + row_num * col_size + col_num) = val;
}

double get_element(double *the_array, int row_num, int col_size, int col_num)
{
    return *(the_array + row_num * col_size + col_num);
}

double sum(double *the_array, int row_size, int col_size)
{
    double sum = 0;
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            sum += *(the_array + i * col_size + j);
        }
    }
    return sum;
}

double find_max(double *the_array, int row_size, int col_size)
{
    double max = *(the_array + 0 * row_size + 0);
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            if (*(the_array + i * col_size + j) > max)
            {
                max = *(the_array + i * col_size + j);
            }
        }
    }
    return max;
}

double find_min(double *the_array, int row_size, int col_size)
{
    double min = *(the_array + 0 * row_size + 0);
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            if (*(the_array + i * col_size + j) < min)
            {
                min = *(the_array + i * col_size + j);
            }
        }
    }
    return min;
}

std::string to_string(double *the_array, int row_size, int col_size)
{
    std::ostringstream OSS;
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
        {
            OSS << std::setw(10) << std::setprecision(2) << std::fixed << *(the_array + i * col_size + j);
        }
        OSS << std::endl;
    }
    return OSS.str();
}
