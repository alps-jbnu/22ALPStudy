#########################################
# 틀린 풀이입니다!
# 어딘가에서 런타임 에러(KeyError) 나는데 3시간 찾아도 못찾겠다...
#########################################

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


class Bst:
    class Node:
        # tup: (level, problem_id)
        def __init__(self, tup: tuple):
            self.tup = tup
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None
        self.id_to_tup = {}

    def add(self, tup):
        if not self.root:
            self.root = Bst.Node(tup)
        else:
            self.__add(tup, self.root)
        self.id_to_tup[tup[1]] = tup

    def __add(self, tup, cur: Node):
        # 더 쉬운 문제가 추가된 경우
        if tup < cur.tup:
            if not cur.left:
                cur.left = Bst.Node(tup)
            else:
                self.__add(tup, cur.left)
        # 더 어려운 문제가 추가된 경우
        elif tup > cur.tup:
            if not cur.right:
                cur.right = Bst.Node(tup)
            else:
                self.__add(tup, cur.right)
        # 난도 똑같고 id 똑같은 문제는 데이터 오류
        else:
            assert False

    def min(self) -> int:
        assert self.root
        node = self.root
        while node.left:
            node = node.left
        return node.tup[1]

    def max(self) -> int:
        assert self.root
        node = self.root
        while node.right:
            node = node.right
        return node.tup[1]

    def remove(self, id: int):
        tup = self.id_to_tup[id]
        if not self.root:
            assert False
        else:
            self.__remove(tup, self.root, None)

    def __remove(self, tup: tuple, cur: Node, parent: Node):
        if cur.tup < tup:
            self.__remove(tup, cur.right, cur)
        elif cur.tup > tup:
            self.__remove(tup, cur.left, cur)
        # 같은 노드를 발견, 삭제 작업 시작
        else:
            self.id_to_tup.pop(tup[1])
            if cur.left and cur.right:
                # 계승자: 큰 놈 중 가장 작은 놈
                successor = cur.right
                succ_parent = cur
                while successor.left:
                    succ_parent = successor
                    successor = successor.left
                self.__remove(successor.tup, successor, succ_parent)
                if not parent:
                    # [실수] 후계자로 대치하면 후계자의 링크까지 덮어써버려서,
                    # 중간 노드가 유실된다. 반드시 값만 대치해야 함!
                    # self.root = successor
                    self.root.tup = successor.tup
                else:
                    if cur == parent.left:
                        # parent.left = successor
                        parent.left.tup = successor.tup
                    elif cur == parent.right:
                        # parent.right = successor
                        parent.right.tup = successor.tup
                    else:
                        assert False
            elif cur.left or cur.right:
                successor = cur.left if cur.left else cur.right
                if not parent:
                    self.root = successor
                else:
                    if cur == parent.left:
                        parent.left = successor
                    elif cur == parent.right:
                        parent.right = successor
                    else:
                        assert False
            else:  # leaf node
                if not parent:
                    self.root = None
                else:
                    if cur == parent.left:
                        parent.left = None
                    elif cur == parent.right:
                        parent.right = None
                    else:
                        assert False


if __name__ == '__main__':
    N = int(input())
    bst = Bst()
    for i in range(N):
        P, L = map(int, input().split())
        bst.add((L, P))
    M = int(input())
    for i in range(M):
        lst = input().split()
        if lst[0] == 'add':
            P, L = int(lst[1]), int(lst[2])
            bst.add((L, P))
        elif lst[0] == 'recommend':
            x = lst[1]
            if x == '1':
                print(bst.max())
            else:  # x == -1
                print(bst.min())
        else:  # 'solved'
            bst.remove(int(lst[1]))
