/* Aadrij Upadya
April 29th, 2024
Closest Pair Problem, Lab 6
Find closest pair given n points in a plane
 */

#include <iostream>
#include <set>
#include <string>
#include <math.h>

using namespace std;

// creating a structure that can take parameters for x and y coordinates
struct point
{
    double x;
    double y;
};

/**
 * @brief Helper function to print contents of an array
 * @param points[] array of integers that we want to print
 * @param size number we iterate to in order to print contents
 */
void print_array(point points[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "(" << points[i].x << "," << points[i].y << ")"
             << " ";
    }
    cout << endl;
}

/**
 * @brief Helper function to sort y coordinate of an array of points (insertion sort)
 * @param points[] array of points that we want to sort
 * @param size number we iterate to in order to sort contents
 */
void sort_y(point points[], int size)
{
    // outer loop from second element to end of array
    for (int i = 1; i < size; i++)
    {
        // temporarily store element at current index for comparison

        point temp = points[i];
        int j = i - 1;
        // keep shifting elements until we find one that is greater than temporary element
        while ((j >= 0) && (temp.y < points[j].y))
        {
            // shift elements to right

            points[j + 1] = points[j];
            j = j - 1;
        }
        // place current element at whatever value of j that is left from while loop

        points[j + 1] = temp;
    }
}

/**
 * @brief Helper function to calculate distance between two points using pythagorean formula
 * @param p1 first point (with x and y coordinates)
 * @param p2 second point (with x and y coordinates)
 */
double distance(point p1, point p2)
{
    return pow((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)), 0.5);
}

/**
 * @brief Helper function to calculate smaller of two given numbers
 * @param d1 first double
 * @param d2 second double for comparison
 */
double minimum(double d1, double d2)
{
    if (d1 < d2)
    {
        return d1;
    }
    return d2;
}

/**
 * @brief recursive function to find closest distance by continuously dividing the points
 * and drawing the 8 box structure
 * @param points[] array of points that we want to find closest pair of
 * @param i starting iterator
 * @param j endpoint of iteration (constantly changes as we halve the search)
 * @param size size of points array
 */
double rec_cl_pair(point points[], int i, int j, int size)
{
    double d;

    // if 3 or less points, can compare directly without algorithm
    if (j - i < 3)
    {
        sort_y(points, size); // sort by y coordinate

        // undergo every possible comparison
        double min_distance = distance(points[0], points[1]);
        if (distance(points[1], points[2]) < min_distance)
        {
            min_distance = distance(points[1], points[2]);
        }
        if (distance(points[0], points[2]) < min_distance)
        {
            min_distance = distance(points[0], points[2]);
        }
        return min_distance;
    }

    // split array into two halves (left and right side)
    int k = (i + j) / 2;
    double l = points[k].x;
    // recursively call until we arrive at a minimum on each side
    double d_l = rec_cl_pair(points, i, k, size);
    double d_r = rec_cl_pair(points, k + 1, j, size);
    d = minimum(d_l, d_r);

    // merge both sorted arrays
    sort_y(points, size);

    // creating a vertical strip to compare our points with
    int t = -1;
    point v[j - i];
    // compare points in vertical strip to find closer pairs
    for (int k = i; k <= j; k++)
    {
        if (((points[k].x > l - d)) && (points[k].x > l + d))
        {
            t = t + 1;
            v[t] = points[k];
        }
    }

    // compare each distance to next seven points
    for (int k = 0; k < t - 1; k++)
    {
        for (int s = k + 1; k < min(t, k + 7); k++)
        {
            d = minimum(d, distance(v[k], v[s]));
        }
    }

    return d;
}

/**
 * @brief sorts x-coordinates then calls rec_cl_pair on a part of the array
 * @param points[]
 * @param size
 */
double closest_pair(point points[], int size)
{
    // selection sort code for x coordinates
    for (int i = 1; i < size; i++)
    {
        point temp = points[i];
        int j = i - 1;
        while ((j >= 0) && (temp.x < points[j].x))
        {
            points[j + 1] = points[j];
            j = j - 1;
        }
        points[j + 1] = temp;
    }
    // calling recursive function for start and end points of array
    return rec_cl_pair(points, 0, size - 1, size);
}

int main()
{
    cout << "How many points are there?" << endl;
    int size;
    cin >> size;
    point points[size];

    // taking in user input using for loop

    for (int i = 0; i < size; i++)
    {
        cout << "Enter x coordinate of point: " << i + 1 << endl;
        double temp_x;
        cin >> temp_x;
        cout << "Enter y coordinate of point: " << i + 1 << endl;
        double temp_y;
        cin >> temp_y;
        point temp_point;
        temp_point.x = temp_x;
        temp_point.y = temp_y;
        points[i] = temp_point;
    }
    cout << "Closest distance between two points: " << closest_pair(points, size) << endl;
}