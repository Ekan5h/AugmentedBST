# AugmentedBST
This repository extends the implementation of a simple BST at [github.com/Ekan5h/SimpleBST/](https://github.com/Ekan5h/SimpleBST/).  
The idea is to augment the tree by storing an additional integer with every node which denotes the size of the left sub tree ie how many elements in the tree with root as the current node are smaller than the current node. This makes finding the rank of an element or finding the element with a given rank much easier. So the final tree looks something like this
                                                          
                                                        (root), 7
                                                          /  \
                                                        /      \
                                                      /          \
                                                    /              \
                                              (l), 3                (r), 3
                                               /   \                 /   \
                                             /       \             /       \
                                       (ll), 1     (lr), 1    (rl), 1     (rr), 1
                                         / \         / \        / \         / \
                                     (lll) (llr) (lrl) (lrr) (rll) (rlr) (rrl) (rrr)
                                       0     0     0     0     0     0     0     0
                                       
