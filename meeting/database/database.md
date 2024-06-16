# mysql45讲
## mysql的框架有几个组件，各是什么作用
mysql的框架有连接器、分析器、优化器、执行器和存储引擎。
连接器负责客户端与服务器之间的连接
分析器负责分析语句是否正确, 语法分析，词法分析。
优化器是对相应的sql语句进行优化，选择效率最高的方式去执行,选择索引。
执行器首先判断是否对表有相应的执行权限，若有的话开始执行,并返回结果。
存储引擎负责存储数据，提供读写接口.

## mysql中的索引
### 为什么会有索引
索引的出现是为了提高数据查询的效率
索引大大减少了服务器需要扫描的数据量
索引可以将随机io变为顺序io.
顺序io指的是读写操作的访问地址连续，即读写磁头可以以最小的移动访问下一个块。而随机io访问地址不连续，随机分布在磁盘的地址空间。
### 为什么会使用B+树来作为索引的数据结构。
实现索引常见的数据结构，哈希表、有序数组与搜索树。
哈希表只适用于等值查询，因为一个连续的索引在经过哈希函数之后不一定连续。所以哈希表不适用于范围查询。
有序数组在范围查询上表现良好，但更新数据较为麻烦，因此，有序数组索引只适合静态存储引擎，这类不会再修改的数据。
为什么不使用二叉树呢？因为二叉树的树高较高，所以一次查询可能要访问多个数据块，由于mysql索引的根节点在内存中(buffer pool)，而其余的节点都在磁盘中，因此一次查询可能要读多次磁盘，所以不应该使用二叉树。
B树中子节点的数量一般在上千。
B树的key分布在整棵树中，每个节点既包含key,也包含data.
因此，B树的搜索可能在非叶节点结束，最好O(1)就能找到数据.
而B树的data值只存储在叶子节点，非叶子节点(内部节点)中只有key.
且B+树之间叶子节点中存在着一个双向指针，从而能够更好的支持范围查询。
并且在B+树中，内部节点无data值，因此B+树单次IO的信息量大于B树，因此B+树相对于B树来说磁盘I/O的数目更少。

### 索引的分类
根据叶子节点的内容，可以将索引分为主键索引和非主键索引
主键索引叶子节点存放的是整行数据，在InnoDB中，也被称为聚簇索引；
非主键索引叶子节点存放的是主键值，在InnoDB中，被称为二级索引。
覆盖索引指的是在非主键索引树上可以直接获取查询结果，不需要经过回表，该索引已经满足了我们的查询需求，因此称为覆盖索引。

### 索引的维护
采用业务逻辑的字段做主键，不易保证有序插入，会造成索引列的分裂和合并，造成写数据成本较高，因此，为了保证有序插入，采用自增主键是较好的选择。 

而在典型的KV场景下（只有一个索引，该索引必须是唯一索引），则适合使用业务逻辑的字段来作为索引。

### 索引的优化
1.使用覆盖索引，即建立一个联合索引, 如将身份证号和姓名建立联合索引。联合索引的key是身份证号和姓名，value是主键值。
2.最左前缀原则，建立联合索引时，需要考虑联合索引中的顺序，尽量少维护一个索引，若做不到少维护一个索引，则更多考虑节省空间。
3.索引下推，指的是在查询时，可以在二级索引的遍历过程中，对索引中包含的字段先做判断，直接过滤掉不满足条件的记录，从而减少回表次数。
##日志的作用

### 日志的种类
错误日志、慢查询日志、事务日志、二进制日志等
慢查询日志是指sql时间超过long\_query\_time的查询
二进制日志是binlog, 事务日志则包含redo log与undo log

undo log(回滚日志）是InnoDB存储引擎层生成的日志，实现了事务中的原子性，主要用于事务回滚和MVCC
redo log(重做日志）也是InnoDB存储引擎生成的日志，实现了事务中的持久性，主要用于掉电等故障恢复
binlog(归档日志）是server生成的日志，主要用于数据备份和主从复制

### redo log与binlog的区别
1. redo log位于存储引擎层，为InnoDB所特有，而binlog则位于server层，任何引擎都可以使用
2. redo log记录的是物理数据，即在哪一个物理页上做了哪些修改；而binlog记录的则是逻辑语句，
3. redo log循环写，空间会被用完，而binlog则是追加写，并不会覆盖之前的日志。这意味着，如果系统保存着最近半个月的binlog，则数据库可以恢复到最近半个月任意一秒的状态。


### undo log 的作用
事务在未提交之前，记录更新前的数据到undo log中去.
如删除某一行数据，将该行数据完整记录下来
若在事务执行中途发生了mysql崩溃，此时内存中数据仍然存在，那么就可以通过这个日志回滚到事务之前的数据。
若出现了错误或者用户执行roolback，发生回滚，就读取undo log中的内容，然后做相反操作.

因此，undo log有两大作用：
1. 实现事务回滚，保证事务执行的原子性
2. 实现MVCC(多版本并发控制）关键因素之一，MVCC是通过ReadView和undo log来实现的，undo log为每条记录保存多份历史数据，mysql在执行快照读（普通select)语句的时候，会根据事物的read view中的信息，顺着undo log的版本链找到满足其可见性的记录。

undo log同样需要刷盘（持久化到磁盘），因为在mysql发生崩溃时，需要通过undo log来实现原子性
事务的原子性指的是一个事务的所有操作必须是不可分割的，必须全部执行成功，或者全部执行失败。
因此，如果事务执行的过程中mysql发生崩溃，我们也可以通过undo log来恢复到事务执行之前的状态。
buffer pool中含有undo页，对undo页的修改也会记录到redo log, redo log每秒输盘，提交事务时也会刷盘，数据页和undo页都是靠这个机制来保持持久化的。


### buffer pool
buffer pool位于InnoDB存储引擎中，buffer pool缓存了索引页和数据页，还包括undo页等，mysql的所有增减删查都是在buffer pool中进行的

### redo log
buffer pool减少了磁盘I/O的次数，提高了读写效率，但buffer pool是基于内存的，万一断电重启，内存中的数据就会消失。

redo log是物理日志，记录的是在哪个数据页上进行了怎样的修改，可以通过设置innodb\_flush\_log\_at\_trx\_commit参数为1，来保证每次事务commit后，都可以直接将redo log持久化到磁盘，从而保证断电后数据不丢失。

这也就是所谓的WAL(Write Ahead log)技术，即mysql并不会直接将脏页写入磁盘，而是将redo log写入磁盘，再通过redo log更改磁盘中的数据页的内容。
为什么写redo log, 而不是写实际的数据页，因为写实际的数据页是随机写，而redo log则是追加写，所以是顺序写到磁盘。

因此：undo log记录的是事务在执行过程中的状态，若事务在执行过程中mysql崩溃，可以通过回滚来保证数据的正确性。
而redo log记录的是事务在提交之后的状态，事务在提交之后，发生断电等事故，可以通过redo log保证数据的正确性。
因此，redo log保证了事务的持久性。

#### redo log何时写到磁盘中去
redo log也有相应的缓存，因此在适合的时候，我们需要写入磁盘中。
1. 通过设置commit参数可以保证每次事务提交时，redo log写入磁盘
2. mysql正常关闭
3. mysql的后台线程每隔一秒会将redo log写入磁盘。
4. 当redo log相应的缓存快被写满时，需要将redo log写入磁盘。