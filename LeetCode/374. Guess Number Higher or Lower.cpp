/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long lo=1, hi=n;
        int mid;
        while(lo<=hi){  
            mid=(lo+hi)/2;
            
            int g=guess(mid);
            if(g==0) break;
             

            else if(g<0) hi=mid-1;
            else lo=mid+1;

        }
        return mid;
    }
};