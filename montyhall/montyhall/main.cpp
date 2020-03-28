
/* Approximate solution of the Monty Hall problem.
 * from: http://www.codecodex.com/wiki/Monty_Hall_problem_analysis
 * must add "/usr/local/lib/python2.7/site-packages/numpy/core/include/numpy/"
 * and
 * "/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7"
 * to the header search path in project settings.
 *
 * Also, must add "-std=c++11 -I/usr/include/python2.7 -lpython2.7" to the Other Linker Flags
 * in the project settings.
 *
 */


#include<iostream>
#include<cstdlib>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;


int doors[ 3] = { 0, 0, 0};
int r; // r - keeps choice of door

void clear_doors( void); // clears all doors
void draw( void); // places the car - at random - behind the doors; then 'contestant' picks, also at random, one door

int main()
{

    
    long int n, w = 0, w_s = 0; // n - number of games, w - number of winning games without switching, w_s - number of winning games with switching
    double p, p_s, n_copy; // p - percent of winning games without switching, p_s - percent of winning games with switching
    
    cout << "Give number of games: ";
    cin >> n;
    n_copy = n;
    
    srandom( time( NULL));
    
    for( n; n > 0; n--) // this loop is for games without switching
    {
        draw();
        
        if( doors[ r] == 1) // if contestant chose winning door, increament winning games counter and clear all doors
        {
            w++;
            clear_doors();
        }
        else // if didn't, only clear all doors
        {
            clear_doors();
        }
    }
    
    n = n_copy; //reset counter of number of games to play, to previous value given by user
    
    for( n; n > 0; n--) // this loop if for games with switching
    {
        draw();
        
        /*
         How does it work:
         If contestant picked door with the car then switch to losing door.
         If contestant picked losing door then switch to winning door [because he chose the losing one at the first pick and second losing he saw when he could change his decision].
         [It shows that knowledge of the game host is essential!]
         */
        
        if( doors[ r] == 0) // if contestant chose winning door, increament winning games counter and clear all doors
        {
            w_s++;
            clear_doors();
        }
        else // if didn't, only clear all doors
        {
            clear_doors();
        }
    }
    
    cout << endl;
    p = (w / n_copy)*100;
    p_s = (w_s / n_copy)*100;
    cout << "Number of winning games without switching: " << w << " [ " << p << "% ]" << endl;
    cout << "Number of winning games with switching: " << w_s << " [ " << p_s << "% ]" << endl;
    
    cout << endl;
    
    plt::plot({1,3,2,4});
    plt::show();
    
    return 0;
}

void clear_doors( void)
{
    doors[ 0] = doors[ 1] = doors[ 2] = 0;
}

void draw( void)
{
    doors[ random() % 3] = 1; // places the car, at random, behind the doors
    r = random() % 3; // picks one door at random
}

