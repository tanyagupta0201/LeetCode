# Merge k Sorted Arrays
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given <strong>K</strong> sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.<br>
<strong>Example 1:</strong> </span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
<strong>Output: </strong>1&nbsp;2&nbsp;3&nbsp;4&nbsp;5 6 7 8 9<strong>
Explanation:</strong>Above test case has 3&nbsp;sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6],&nbsp;
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong> </span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
<strong>Output:
</strong>1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9&nbsp;<strong>
Explanation: </strong>Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],&nbsp;[3, 3, 4, 4],
[5, 5, 6, 6]&nbsp; [7, 8, 9, 9&nbsp;]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9&nbsp;].</span></pre>

<p><span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
You do not need to read input or print anything. Your task is to complete&nbsp;<strong>mergeKArrays</strong>() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K&nbsp;sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in <strong>cpp,&nbsp;</strong>as an ArrayList in&nbsp;<strong>java,&nbsp;</strong>and list in&nbsp;<strong>python</strong>)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(K<sup>2</sup></span>*<span style="font-size:18px">Log(K))<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(K)</span></p>

<p><span style="font-size:18px"><strong>Constraints</strong>:<br>
1 &lt;= K &lt;= 100</span></p>
 <p></p>
            </div>