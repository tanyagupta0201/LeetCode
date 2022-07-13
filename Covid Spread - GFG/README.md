# Covid Spread
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Aterp is the head nurse at a city hospital. City hospital contains R*C&nbsp;number of wards and the structure of a hospital is in the form of a 2-D matrix.<br>
Given a matrix of dimension <strong>R</strong>*<strong>C</strong> where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:</span><br>
<span style="font-size:18px"><strong>0</strong>: Empty ward</span><br>
<span style="font-size:18px"><strong>1</strong>: Cells have uninfected patients</span><br>
<span style="font-size:18px"><strong>2</strong>: Cells have infected patients</span></p>

<p><span style="font-size:18px">An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (<strong>up</strong>, <strong>down</strong>, <strong>left</strong> and <strong>right</strong>) in unit time. Help Aterp&nbsp;determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected.&nbsp;If all patients are not infected after infinite units of time then simply return -1.</span></p>

<p>&nbsp;</p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 </span><span style="font-size:18px">
<strong>Output:</strong>
2</span>
<span style="font-size:18px"><strong>Explanation:
</strong>Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px">3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
<strong>Output:</strong>
-1</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">All patients will not be infected.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong>&nbsp;&nbsp;</span><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function <strong>helpaterp</strong>()&nbsp;which takes a 2-D Matrix <strong>hospital&nbsp;</strong>as input parameter&nbsp;and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(R*C)<br>
<strong>Expected Auxiliary Space:</strong> O(R*C)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 </span> <span style="font-size:18px">≤</span> <span style="font-size:18px"> R,C&nbsp;≤ 1000<br>
0 ≤ mat[i][j]&nbsp;≤ 2</span></p>
 <p></p>
            </div>