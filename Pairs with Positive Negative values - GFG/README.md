# Pairs with Positive Negative values
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif">Given an array of&nbsp;integers, print all the pairs having positive&nbsp;and negative values of a number that exists in the array.</span></span></p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>NOTE:</strong> If&nbsp;no such pair exists, simply&nbsp;return an empty array, also multiple pairs of the same number could exist and&nbsp;you need to print each of them separately.</span></span></p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Example 1:</strong></span></span></p>

<pre><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input:</strong>
n = 8
a [ ] = {1, -3, 2, 3, 6, -1, -3, 3}
<strong>Output:</strong>
-1 1 -3 3 -3 3
<strong>Explanation:
</strong>The array contains both 1 and -1, and
3 &amp; -3 two times.</span></span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Example 2:</strong></span></span></p>

<pre><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input:</strong>
n = 8
a [ ] = {4, 8, 9, -4, 1, -1, -8, -9}
<strong>Output:</strong>
-1 1 -4 4 -8 8 -9 9
<strong>Explanation:
</strong>Here, the array contains the pairs 1 &amp; -1,
4 &amp; -4, 8 &amp; -8, and 9 &amp; -9.</span></span>
</pre>

<p><br>
<br>
<span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>PosNegPair()</strong>&nbsp;which takes the array <strong>a[]</strong> and its size <strong>n</strong><strong> </strong>as inputs and returns all the required pairs in the increasing order of their absolute numbers.</span></span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Expected Time Complexity:</strong> O(nLog(n))<br>
<strong>Expected Auxiliary Space:</strong> O(n)</span></span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Constraints:</strong><br>
1&lt;=n&lt;=10<sup>5</sup><br>
-10<sup>5</sup>&lt;=a[i]&lt;=10<sup>5</sup></span></span></p>
 <p></p>
            </div>