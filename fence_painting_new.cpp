#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=567

int main() {
    
    ifstream fin ("paint.in");
    ofstream fout ("paint.out");
    
    vector<int> info;
    for (int i = 0; i < 4; i++) {
        int information; fin >> information;
        info.push_back(information);
    }

    vector<int> extra_info;
    extra_info = info;

    
    // for min and max
    sort(info.begin(), info.end());


    // below means there is overlap
    //       *-------*
    //! *------*
    // then we will take min - max for the entire amt of units painted min => *----*---* <= max 


    int ans = info[3] - info[0];


    // below means there is no overlap and bessie painted left of FJ on a number line
    //!      *--------*     *--------* 
    //?     b1        b2   f1        f2
   
   
    if (extra_info[3] < extra_info[0]) {
        // if above is true then we will delete the '$' 
            // *--------*$$$$$*--------* 

        ans -= (extra_info[0] - extra_info[3]);   
    }

 
    // below means there is no overlap and FJ painted left of bessie on a number line
    //!      *--------*     *--------* 
    //?     f1        f2   b1        b2    


    if (extra_info[1] < extra_info[2]) {
        // if above is true then we will delete the '%' 
            // *--------*%%%%%*--------* 

        ans -= (extra_info[2] - extra_info[1]);
    }
    
    fout << ans << endl;
}