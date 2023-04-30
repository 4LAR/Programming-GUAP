
from search import *

class AVLTree:
    def __init__(self):
        self.root = None
        self.client = None
        self.left = None
        self.right = None
        self.height = 1

    def clear(self):
        self.root = None
        self.client = None
        self.left = None
        self.right = None

    def insert(self, node, client):
        if node == None:
            node = AVLTree()
            node.client = None

        if node.client == None:
            node.client = client
            return node

        elif client.number < node.client.number:
            node.left = self.insert(node.left, client)

        else:
            node.right = self.insert(node.right, client)

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        ###
        balance = self.get_balance(node)

        if balance > 1 and client.number < node.left.client.number:
            return self.right_rotate(node)

        if balance < -1 and client.number > node.right.client.number:
            return self.left_rotate(node)

        if balance > 1 and client.number > node.left.client.number:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        if balance < -1 and client.number < node.right.client.number:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        ###

        return node

    def left_rotate(self, node):
        right = node.right
        left = right.left

        right.left = node
        node.right = left

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        right.height = 1 + max(self.get_height(right.left), self.get_height(right.right))

        return right

    def right_rotate(self, node):
        left = node.left
        right = left.right

        left.right = node
        node.left = right

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        left.height = 1 + max(self.get_height(left.left), self.get_height(left.right))

        return left

    def get_height(self, node):
        if node is None:
            return 0

        return node.height

    def get_balance(self, node):
        if node is None:
            return 0

        return self.get_height(node.left) - self.get_height(node.right)

    def search(self, node, number):
        if node is None:
            return None

        if number == node.client.number:
            return node.client

        if number < node.client.number:
            return self.search(node.left, number)

        return self.search(node.right, number)

    def pre_order(self, node):
        if (node):
            print("-" * 20)
            if node.client != None:
                node.client.print()
            self.pre_order(node.left)
            self.pre_order(node.right)

    def pre_order_return(self, node):
        out = []
        if (node):
            if node.client != None:
                out.append(node.client)
            out += self.pre_order_return(node.left)
            out += self.pre_order_return(node.right)

        return out

################################################################################
# поиск по заданию
    def search_by_number(self, number):
        current = self
        while True:
            if current == None:
                return None

            if current.client.number == number:
                return current.client

            elif number < current.client.number:
                current = current.left

            else:
                current = current.right

    def search_by_equipment(self, equipment, current=None):
        if current == None:
            current = self

        result = []
        if boyerMurSearch(equipment, current.client.equipment) != None:
            result += current.client

        if current.left != None:
            result += self.search_by_equipment(equipment, current.left)

        if current.right != None:
            result += self.search_by_equipment(equipment, current.right)

        return result

    def delete_by_number(self, number):
        current = self
        go_left = False
        prev = None
        while True:
            if current == None:
                return False

            if current.client.number == number:
                if go_left:
                    prev.left = None
                else:
                    prev.right = None

                left = current.left
                right = current.right
                prev.insert(prev, left)
                prev.insert(prev, right)

                return True

            else:
                prev = current
                if number < current.client.number:
                    current = current.left
                    go_left = True

                else:
                    current = current.right
                    go_left = False
