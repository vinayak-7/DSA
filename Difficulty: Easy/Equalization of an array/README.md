<h2><a href="https://www.geeksforgeeks.org/problems/equalization-of-an-array1656/1">Equalization of an array</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of integers <strong>arr[ ]</strong>, the task is to count the minimum number of operations to equalize the array <em>i.e.</em>&nbsp;to make all array elements equal.<br>In one operation,&nbsp;you can choose two elements <strong>arr[i]</strong> and <strong>arr[j]</strong> such that <strong>arr[i] &gt; arr[j] </strong>and change them to <strong>arr[i] = arr[i] - 1</strong> and <strong>arr[j] = arr[j] +&nbsp;1</strong>.<br>If it is impossible to equalize the array then return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 3, 2, 0, 4]
<strong>Output:</strong> 3
<strong>Explanation</strong>: We can equalize the array by making value of all elements equal to 2. To achieve this we need to do minimum 3 operations:
1. arr[0]++ and arr[1]--
2. arr[3]++ and arr[4]--
3. arr[3]++ and arr[4]--</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 7, 1]
<strong>Output:</strong> 4
</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong> O(1).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br><span style="font-size: 18.6667px;">1 ≤ arr.size()</span><strong style="font-size: 18.6667px;">&nbsp;</strong><span style="font-size: 18.6667px;">≤ 10</span><sup>6</sup><br style="font-size: 18.6667px;"><span style="font-size: 18.6667px;">1 ≤ arr[i]</span><strong style="font-size: 18.6667px;">&nbsp;</strong><span style="font-size: 18.6667px;">≤ 10</span><sup>4</sup><br></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;