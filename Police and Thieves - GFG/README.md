# Police and Thieves
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of size <strong>n</strong> such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police.&nbsp;<br>
Keep in mind the following conditions :</span></p>

<ol>
	<li><span style="font-size:18px">Each policeman can catch only one thief.</span></li>
	<li><span style="font-size:18px">A policeman cannot catch a thief who is more than <strong>K</strong> units away from him.</span></li>
</ol>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5, K = 1
arr[] = {P, T, T, P, T}
<strong>Output:</strong> 2
<strong>Explanation:</strong> Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 6, K = 2
arr[] = {T, T, P, P, T, P}
<strong>Output:</strong> 3
<strong>Explanation: </strong>Maximum 3 thieves can be caught.</span></pre>

<p><span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function <strong>catchThieves() </strong>that takes <strong>n, k</strong> and <strong>arr[ ]</strong>&nbsp;as input parameters and returns the maximum number of thieves that can be caught by the police.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n ≤&nbsp;10<sup>5</sup><br>
1 ≤&nbsp;k ≤&nbsp;100<br>
arr[i] = 'P' or 'T'</span></p>
</div>