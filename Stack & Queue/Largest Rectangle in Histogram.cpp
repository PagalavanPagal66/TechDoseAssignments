class Solution {
public:
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      //calculating left border
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
          //condition for left increasing manner
        }
        if (st.empty())
        {
          leftsmall[i] = 0; // it has power to form building of same size untill leftmost index (0)
        }
        else{
          leftsmall[i] = st.top() + 1; //it has power to form building untill the top of the stack
        }
        st.push(i);
      }
      while (!st.empty()) st.pop(); // clearing the stack
      //calculating right border 
        for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();
            // condition for right increasing manner
        if (st.empty())
          rightsmall[i] = n - 1; // it has power to form building of same size untill rightmost index (n-1)
        else
          rightsmall[i] = st.top() - 1; //it has power to form building untill the top of the stack

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
         maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1)); // (right-left+1 ) -> possible count of buildings formation with same height
      }
      return maxA;
    }
};