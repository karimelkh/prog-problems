/*
	Problem name: . Matrix Similarity After Cyclic Shifts
	Difficulty: Easy
	Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/

	Description below

  Submissions:
    - Runtime: 11ms Beats 83.33%of users with C++
    - Memory: 28.74MB Beats 25.00%of users with C++
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    vector<vector<int>> tmp_mat(mat);
    int nbr_cols = tmp_mat[0].size(), nbr_rows = tmp_mat.size();
    if(k % nbr_cols == 0) return true;
    k %= nbr_cols;
    for(int i=0; i<nbr_rows; i++) {
      vector<int> tmp(tmp_mat[i]);
      if(i % 2 == 0) for(int c=0; c<nbr_cols; c++) tmp_mat[i][(c + k) % nbr_cols] = tmp.at(c);
      else for(int c=0; c<nbr_cols; c++) tmp_mat[i][(c + nbr_cols - k) % nbr_cols] = tmp.at(c);
      if (mat[i] != tmp_mat[i]) return false;
    }
    return true;
  }
};


/*
You are given a 0-indexed m x n integer matrix mat and an integer k. You have to cyclically right shift odd indexed rows k times and cyclically left shift even indexed rows k times.
Return true if the initial and final matrix are exactly the same and false otherwise.

Example 1:

Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
Output: true

Explanation:
  Initially, the matrix looks like the first figure. 
  Second figure represents the state of the matrix after one right and left cyclic shifts to even and odd indexed rows.
  Third figure is the final state of the matrix after two cyclic shifts which is similar to the initial matrix.
  Therefore, return true.

Example 2:
  Input: mat = [[2,2],[2,2]], k = 3
  Output: true
  Explanation: As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same. Therefeore, we return true.

Example 3:
  Input: mat = [[1,2]], k = 1
  Output: false
  Explanation: After one cyclic shift, mat = [[2,1]] which is not equal to the initial matrix. Therefore we return false.
*/
