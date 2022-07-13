# X Total Shapes
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given&nbsp; a grid of <strong>n</strong>*<strong>m</strong>&nbsp;consisting<strong>&nbsp;</strong>of <strong>O<code>'s</code></strong>&nbsp;and <strong>X<code>'s</code></strong>. The task is to find the number of '<strong>X</strong>' total shapes.<br>
<strong>Note:&nbsp;</strong>'<strong>X</strong>' shape consists of one or more adjacent <strong>X</strong><code>'s</code>&nbsp;(diagonals not included).</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{X,O,X},{O,X,O},{X,X,X}}
<strong>Output: </strong>3
<strong>Explanation: 
</strong>The grid is-
<span style="color:#EE82EE"><strong>X</strong></span> O <span style="color:#FF8C00"><strong>X</strong></span>
O <span style="color:#00FF00"><strong>X</strong></span> O
<strong><span style="color:#00FF00">X</span> <span style="color:#00FF00">X</span> <span style="color:#00FF00">X</span>
</strong>So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.</span><span style="font-size:18px"><strong>
</strong></span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{X,X},{X,X}}
<strong>Output: </strong>1
<strong>Expanation: 
</strong>The grid is- 
<span style="color:#EE82EE"><strong>X</strong></span> <span style="color:#EE82EE"><strong>X</strong></span>
<strong><span style="color:#EE82EE">X</span> <span style="color:#EE82EE">X</span></strong>
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function <strong>xShape()&nbsp;</strong>which takes grid as input parameter and returns the count of total X shapes.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Compelxity:&nbsp;</strong>O(n*m)<br>
<strong>Expected Space Compelxity:&nbsp;</strong>O(n*m)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n, m&nbsp;≤ 100</span></p>
 <p></p>
            </div>