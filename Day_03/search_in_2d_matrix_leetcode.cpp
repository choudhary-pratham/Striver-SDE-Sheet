#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int low = 0;
    int high = (n*m)-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(mat[mid/n][mid%n] == target) return true;
        else if(mat[mid/n][mid%n] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}