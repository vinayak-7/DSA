# Minimum Cost Car
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">There are n cities connected by some number of cars. You are given an array of cars&nbsp;where cars[i]&nbsp;=[from<sub>i</sub>,to<sub>i</sub>,cost<sub>i</sub>]&nbsp;indicates that there is a car from the city from<sub>i</sub> to city to<sub>i</sub> with cost&nbsp;<code>price<sub>i</sub></code>.</span></p>

<p><span style="font-size:18px">You are also given three integers src,dst, and k, return&nbsp;<em><strong>the cheapest price</strong>&nbsp;from&nbsp;</em><code>src</code><em>&nbsp;to&nbsp;</em><code>dst</code><em>&nbsp;with at most&nbsp;</em><code>k</code><em>&nbsp;stops.&nbsp;</em>If there is no such route, return<em>&nbsp;</em><code>-1</code>.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=4
cars =  {{ 0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}}
src = 0
dst = 3
k = 1.
<strong>Output:</strong>
700
<strong>Explanation:</strong>
The graph is shown above. The optimal path with at most 1 stops from cities 0 to 3 is marked in red and has cost 100 + 600 = 700. Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 3
cars = {{0,1,100},{1,2,100},{0,2,500}}
src = 0
dst = 2
k = 1
<strong>Output:</strong>
200
<strong>Explanation:</strong>
The graph is shown above. The optimal path with at most 1 stops from city 0 to 2 is marked in red and has cost 100 + 100 = 200.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>minimumCost()</strong>&nbsp;which takes a number of cities N, the cars array&nbsp;cars[], the integer src, the integer dst, and the number of stops k<strong>&nbsp;</strong>as input parameters&nbsp;and returns the minimum cost else -1.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span><br>
<br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>2</sup><br>
0&lt;= edges[i][0],edges[i][1] 1&lt;=edges[i][2]&lt;=10<sup>4</sup><br>
0&lt;=src,dst,k src!=dst</span></p>
</div>