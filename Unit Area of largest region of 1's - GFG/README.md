# Unit Area of largest region of 1's
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a grid of dimension <strong>n</strong>x<strong>m&nbsp;</strong>containing 0s and 1s. Find the unit area of the largest region of 1s.<br>
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
<strong>Output: </strong>5
<strong>Explanation: </strong>The grid is-
<span style="color:#FF0000">1 1 1</span> 0
0 0 <span style="color:#FF0000">1 </span>0
0 0 0 <span style="color:#FF0000">1
</span>The largest region of 1's is colored
in orange.
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{0,1}}
<strong>Output: </strong>1
<strong>Explanation: </strong>The grid is-
0 <span style="color:#FF0000">1
</span>The largest region of 1's is colored in 
orange.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anyhting. Your task is to complete the function&nbsp;<strong>findMaxArea()&nbsp;</strong>which takes grid as input parameter and returns the area of the largest region of 1's.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(n*m)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(n*m)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n, m ≤ 500</span></p>
 <p></p>
            </div>