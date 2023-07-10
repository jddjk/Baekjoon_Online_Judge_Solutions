class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def construct_tree(nodes):
    tree = {}
    for node_info in nodes:
        value, left_child, right_child = node_info
        if value not in tree:
            tree[value] = Node(value)
        if left_child != '.':
            tree[value].left = Node(left_child)
            tree[left_child] = tree[value].left
        if right_child != '.':
            tree[value].right = Node(right_child)
            tree[right_child] = tree[value].right
    return tree

def preorder_traversal(node):
    if node:
        print(node.value, end='')
        preorder_traversal(node.left)
        preorder_traversal(node.right)

def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.value, end='')
        inorder_traversal(node.right)

def postorder_traversal(node):
    if node:
        postorder_traversal(node.left)
        postorder_traversal(node.right)
        print(node.value, end='')

N = int(input())
nodes = [input().split() for _ in range(N)]

tree = construct_tree(nodes)

preorder_traversal(tree['A'])
print()

inorder_traversal(tree['A'])
print()

postorder_traversal(tree['A'])
print()
