/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/
#include <stdio.h>
#include <stdlib.h>

// 链表节点定义
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_head->val = 0;
    dummy_head->next = NULL;
    
    struct ListNode* current = dummy_head;
    int carry = 0;  // 进位
    
    // 当还有节点需要处理或还有进位时继续循环  ||或运算
    while (l1 != NULL || l2 != NULL || carry != 0) {
        // 获取当前位的值
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        // 计算当前位的和
        int total = val1 + val2 + carry;
        carry = total / 10;      // New carry
        int digit = total % 10;  // 当前位的数字
        // 创建新节点
        struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val = digit;
        new_node->next = NULL;
        
        current->next = new_node;
        current = current->next;
        
        // 移动到下一个节点
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
    
    struct ListNode* result = dummy_head->next;
    free(dummy_head);  // 释放虚拟头节点
    return result;
}

/**
 * 创建链表节点
 */
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/**
 * 从数组创建链表
 */
struct ListNode* createLinkedList(int nums[], int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(nums[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(nums[i]);
        current = current->next;
    }
    
    return head;
}

/**
 * 打印链表
 */
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

/**
 * 链表转换为数字（用于验证，注意：仅适用于较小的数字）
 */
long long linkedListToNumber(struct ListNode* head) {
    long long num = 0;
    long long multiplier = 1;
    struct ListNode* current = head;
    
    while (current != NULL) {
        num += current->val * multiplier;
        multiplier *= 10;
        current = current->next;
    }
    
    return num;
}

/**
 * 释放链表内存
 */
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    printf("=== 两数相加 - 链表实现 ===\n\n");
    
    // 示例1: 342 + 465 = 807
    // 链表表示: [2,4,3] + [5,6,4] = [7,0,8]
    printf("示例1: 342 + 465\n");
    int nums1[] = {2, 4, 3};  // 表示数字 342
    int nums2[] = {5, 6, 4};  // 表示数字 465
    
    struct ListNode* l1 = createLinkedList(nums1, 3);
    struct ListNode* l2 = createLinkedList(nums2, 3);
    
    printf("l1: ");
    printLinkedList(l1);
    printf("    (数字: %lld)\n", linkedListToNumber(l1));
    
    printf("l2: ");
    printLinkedList(l2);
    printf("    (数字: %lld)\n", linkedListToNumber(l2));
    
    struct ListNode* result1 = addTwoNumbers(l1, l2);
    printf("结果: ");
    printLinkedList(result1);
    printf("    (数字: %lld)\n\n", linkedListToNumber(result1));
    
    // 示例2: 0 + 0 = 0
    printf("示例2: 0 + 0\n");
    int nums3[] = {0};
    int nums4[] = {0};
    
    struct ListNode* l3 = createLinkedList(nums3, 1);
    struct ListNode* l4 = createLinkedList(nums4, 1);
    
    printf("l3: ");
    printLinkedList(l3);
    printf("l4: ");
    printLinkedList(l4);
    
    struct ListNode* result2 = addTwoNumbers(l3, l4);
    printf("结果: ");
    printLinkedList(result2);
    printf("    (数字: %lld)\n\n", linkedListToNumber(result2));
    
    // 示例3: 9999999 + 9999 = 10009998
    printf("示例3: 9999999 + 9999\n");
    int nums5[] = {9,9,9,9,9,9,9};  // 表示数字 9999999
    int nums6[] = {9,9,9,9};        // 表示数字 9999
    
    struct ListNode* l5 = createLinkedList(nums5, 7);
    struct ListNode* l6 = createLinkedList(nums6, 4);
    
    printf("l5: ");
    printLinkedList(l5);
    printf("    (数字: %lld)\n", linkedListToNumber(l5));
    
    printf("l6: ");
    printLinkedList(l6);
    printf("    (数字: %lld)\n", linkedListToNumber(l6));
    
    struct ListNode* result3 = addTwoNumbers(l5, l6);
    printf("结果: ");
    printLinkedList(result3);
    printf("    (数字: %lld)\n\n", linkedListToNumber(result3));
    
    // 示例4: 测试进位传播 99 + 1 = 100
    printf("示例4: 99 + 1 = 100\n");
    int nums7[] = {9, 9};  // 表示数字 99
    int nums8[] = {1};     // 表示数字 1
    
    struct ListNode* l7 = createLinkedList(nums7, 2);
    struct ListNode* l8 = createLinkedList(nums8, 1);
    
    printf("l7: ");
    printLinkedList(l7);
    printf("    (数字: %lld)\n", linkedListToNumber(l7));
    
    printf("l8: ");
    printLinkedList(l8);
    printf("    (数字: %lld)\n", linkedListToNumber(l8));
    
    struct ListNode* result4 = addTwoNumbers(l7, l8);
    printf("结果: ");
    printLinkedList(result4);
    printf("    (数字: %lld)\n", linkedListToNumber(result4));
    
    // 释放内存
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(l3);
    freeLinkedList(l4);
    freeLinkedList(l5);
    freeLinkedList(l6);
    freeLinkedList(l7);
    freeLinkedList(l8);
    freeLinkedList(result1);
    freeLinkedList(result2);
    freeLinkedList(result3);
    freeLinkedList(result4);
    
    return 0;
}



/*
链表是一种基础的数据结构，由一系列节点组成，每个节点包含数据和指向下一个节点的指针。
基本概念
链表中的每个节点通常包含两部分：

数据域：存储实际的数据值
指针域：存储指向下一个节点的地址

与数组不同，链表中的元素在内存中不需要连续存储，而是通过指针将各个节点连接起来。
主要类型
单向链表：每个节点只有一个指向下一个节点的指针，只能单向遍历。
双向链表：每个节点有两个指针，分别指向前一个和后一个节点，可以双向遍历。
循环链表：最后一个节点的指针指向第一个节点，形成环形结构。
优缺点
优点：

动态大小，可以在运行时灵活增删节点
插入和删除操作效率高（O(1)时间复杂度，如果已知位置）
内存利用率高，按需分配

缺点：

无法随机访问，只能顺序访问
需要额外的内存空间存储指针
查找特定元素需要遍历，时间复杂度为O(n)

常见应用
链表广泛应用于实现其他数据结构（如栈、队列）、操作系统的内存管理、浏览器历史记录管理等场景中。当需要频繁插入删除操作，而对随机访问要求不高时，链表是很好的选择。
*/