# Find n-th Fortunate Number
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an integer <strong>n</strong>, find the <strong>n'th</strong> Fortunate Number.<br>
<strong>A Fortunate number is the smallest integer m &gt; 1 such that, for a given positive integer n,&nbsp;</strong><strong>pn</strong><strong>&nbsp;+ m is a prime number. </strong>Here <strong>pn</strong>&nbsp;is the product of the first n prime numbers, i.e prime factorials (or&nbsp;<a href="https://www.geeksforgeeks.org/primorial-of-a-number/">primorials</a>) of order <strong>n</strong>. </span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>n = </strong>3</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">7</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">7 must be added to the product of first
n prime numbers to make the product prime.
2 x 3 x 5 = 30, need to add 7 to make it 37,
which is a prime.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>n = </strong>5</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">23</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">23 must be added to the product of first
n prime numbers to make the product prime.
2 x 3 x 5 x 7 x 11= 2310, need to add 23
to make it 2333, which is a prime.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>nthFortunateNum()</strong> which takes an Integer n as input and returns the n'th Fortunate Number.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= n &lt;= 15</span></p>
</div>