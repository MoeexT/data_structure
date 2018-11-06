package com.data_structure;
/*
*  二叉树非递归遍历
* */
import java.util.Stack;

public class BinaryTree {
    private char data;
    private BinaryTree lChild;
    private BinaryTree rChild;

    public static void preOrder(BinaryTree tree) {
        Stack<BinaryTree> stack = new Stack<>();
        while (tree != null || !stack.empty()) {
            while (tree != null) {
                System.out.println(tree.data);
                stack.push(tree);
                tree = tree.lChild;
            }
            if (!stack.empty()) {
                tree = stack.pop();
                tree = tree.rChild;
            }
        }
    }

    public static void inOrder(BinaryTree tree) {
        Stack<BinaryTree> stack = new Stack<>();
        while (tree != null || !stack.empty()) {
            while (tree != null) {
                stack.push(tree);
                tree = tree.lChild;
            }
            if (!stack.empty()) {
                tree = stack.pop();
                System.out.println(tree.data);
                tree = tree.rChild;
            }
        }
    }

    public static void postOrder(BinaryTree tree) {
        Stack<BinaryTree> btStack = new Stack<>();
        Stack<Integer> intStack = new Stack<>();
        Integer i = 1;
        while (tree != null || !btStack.empty()) {
            while (tree != null) {
                btStack.push(tree);
                intStack.push(0);
                tree = tree.lChild;
            }
            while (!btStack.empty() && intStack.peek().equals(i)) {
                intStack.pop();
                System.out.println(btStack.pop().data);
            }
            if (!btStack.empty()) {
                intStack.push(1);
                tree = btStack.peek();
                tree = tree.rChild;
            }
        }
    }

}
