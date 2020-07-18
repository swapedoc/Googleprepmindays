Btree
 
 A B tree of degree t , typical leaf nodes have keys and they are in sorted order
 max No of children for order t= t;if t children , then t-1 keys;(root can have 2t-1 keys)
  max keys in any node= t-1
  min keys in any node(except root)=(t-1)/2
 INsertion
 insert at bottom
 split node with m key pairs and put it up
 
 b trees -in postgresql, windows: ntfs,oracle, hfs, xfs
 red black in c++ map, multipmap, rbtree in linux , stack scanning emacs
 
 Btree variation B+ tree, B*tree, B#tree
 
 Search		O(log n)	O(log n)
Insert		O(log n)	O(log n)
Delete		O(log n)	O(log n)

best case height of a B-tree of order n and which has k keys?
 logn (k+1) – 1