# 华为2016软件精英挑战赛初赛题的一种实现方法 #
# ——基于Dijkstra+DFS+剪枝 #

## 赛题简介 ##
给定一个有向加权图G，找到从起点S到终点D，并经过指定点集V中所有点的最短路径，要求该路径不能成环。具体要求参考比赛官网:[http://codecraft.huawei.com/home/detail](http://codecraft.huawei.com/home/detail)

## 基本思路 ##
首先，利用Dijkstra算法找到：

- 起点S到指定点集V中所有点的最短距离
- 指定点集V中所有点到终点D的最短距离
- 指定点集V中所有点相互之间的最短距离

然后，利用DFS搜索从起点S到终点D，并经过指定点集V中所有点的所有路径，由于DFS的计算复杂度是n!，在搜索过程中需要进行剪枝，否则当V中点的数量非常大时，将会耗费大量时间，假设V中的点只有12个，我们知道12! = 479 001 600，计算量已经达到亿级。因此，我们采用以下两种剪枝策略：

1. 在搜索出一条可行的路径后，把它的权重值dist暂时记录为最短路径dist_shortest，在接下来的搜索中，只要某条路径的权重大于dist_shortest，不管该有没有包含所有需要经过的点，均要马上停止搜索。如果搜索出一条新的路径，其权重值dist小于dist_shortest，那么更新dist_shortest为该新路径的权重dist。
2. 在用Dijkstra算法计算最短路径时，V中某个点A到B的最短路径中可能会包含另一个V中的点C，那么我们就可以不搜索A到B这条路径，因为该路径已经包含在A->C和C->B这条路径中了。如果这一点不好理解可以参考算例分析部分的解释。

当然，只有这两种剪枝，在面对V中点数很多的情况下搜索效率还是非常低的。所以需要通过发现新的特性来加入新的剪枝策略。

## 算例分析 ##
下面通过分析官网给出的case1算例来具体分析以上基本思路提到的算法。


## 相关算法 ##
接下来简单介绍一下在我们算法中用到的经典算法

### Dijkstra算法 ###
Dijkstra算法的具体介绍可以参考这篇博客[http://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html](http://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html)，这篇博客是我目前找到的比较好的介绍Dijkstra算法的一篇博客了。（先用着，以后有时间自己可以整理一篇）

### DFS算法 ###
先贴出一段经典伪代码进行说明

![test](https://raw.githubusercontent.com/Zhangzhk0819/HUAWEI-Code-Craft-2016/master/DFS.png)



## 代码结构分析 ##
主程序结构可以参考官方提供的[readme](https://raw.githubusercontent.com/Zhangzhk0819/HUAWEI-Code-Craft-2016/master/readme.txt)文件。我们写的代码主要在route.cpp这个文件以及其他几个定义了相关类的文件，下面具体介绍：

1. read_graph.cpp.这个文件主要定义了ReadGraph这个类及其方法，这个类的主要作用是把输入文件中的有向图结构（topo.csv）和路由需求（demand.csv）转换成整型数存放在制定数组上，方便Dijkstra算法的使用。
2. dijkstra.cpp.这个文件主要定义了Dijkstra这个类及其方法，这个类的主要作用就是计算**基本思路**中提到的几个最短距离以及最短路径所经过的点。并存储在相应数组里，方便DFS算法的使用。
3. dfs.cpp.这个文件主要定义了DFS这个类及其方法，这个类的主要作用是就是寻找符合条件的最短路径，其主要思路在前面的内容已经提到，这里不再赘述。
4. sk66.cpp和sk.cpp这两个文件在最后提交的代码中没有用到。这两个文件实现了[Protected shortest path visiting specified nodes](http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7325218)z这篇文章提到的两个算法，不知道是算法本身有问题，还是某些细节实现有问题，运行效果并不好，所以后来改用DFS加剪枝这个方法。如果以后有时间，再补充讲一下这两个算法的基本思路。

## 附录 ##
这一节将会讲解一些关于Linux编程的相关知识，敬请期待。
