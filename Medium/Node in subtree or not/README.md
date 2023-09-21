<h2><a href="https://practice.geeksforgeeks.org/problems/find-alice/1?page=1&sortBy=latest">Node in subtree or not</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a graph g rooted at node 1. You will be given q queries of type a,b. For each query, you need to print "YES" if a in the subtree of b else print "NO".</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong> </span><br>&nbsp;</p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
N=5 
edges[]={{1,2},
         {2,3}, 
&nbsp;        {3,4},
&nbsp;        {4,5}} 
Q=1 
queryies[]={{2,4}} 
<strong>Output:</strong> 
NO 
<strong>Explanation:</strong> 
Since 2 is not in the subtree of 4 hence 
answer is NO.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;">
<strong>Input:
</strong>N=5
edges[]={{1,2},
         {1,3},
         {3,4},
         {3,5}}
Q=3
queries[]={{3,2},
&nbsp;          {1,4},
&nbsp;          {4,1}}
<strong>Output:</strong>
NO
NO
YES
<strong>Explanation:</strong>
Since only 4 is in subtree of 1 
hence answer is YES only for last query.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:-</strong><br>You don't need to read input or print anything. Your task is to complete the function isInSubtree<strong>()</strong>&nbsp;which takes the graph g in adjacency list format&nbsp;g[], Number of nodes N<strong>,&nbsp;</strong>an integer Q number of queries Q, and a 2-D array queries which contain ai, bi as input parameters&nbsp;and returns the answer vector.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(Q)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;=N&lt;=10<sup>5</sup><br>1&lt;=a,b&lt;=N<br>1&lt;=Q&lt;=10<sup>5</sup></span></p></div>