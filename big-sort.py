import random

# 100 -> [700, 900]
# 500 -> [5500, 7000]

class Stack:
    def __init__(self, elems=None):
        if (elems):
            self._elems = elems
        else:
            self._elems = []

    def __len__(self):
        return len(self._elems)

    def __str__(self):
        return str(self._elems)

    @property
    def top(self):
        return self._elems[0]

    @property
    def bottom(self):
        return self._elems[-1]

def swap(stack: Stack):
    if (len(stack._elems) > 1):
        stack._elems[0], stack._elems[1] = stack._elems[1], stack._elems[0]
    return stack

def push(stack_a: Stack, stack_b: Stack):
    # take top element from a and put it on top of b
    elem = stack_a._elems.pop(0)
    stack_b._elems.insert(0, elem)


def rotate(stack: Stack):
    # rotate elements in stack up
    elem = stack._elems.pop(0)
    stack._elems.append(elem)
    return stack

def reverse_rotate(stack: Stack):
    # rotate elements in stack down
    elem = stack._elems.pop()
    stack._elems.insert(0, elem)
    return stack

def find_median(stack: Stack):
    # find median of stack
    return sorted(stack._elems)[len(stack._elems) // 2]

def find_quantile(stack: Stack, quantile):
    # find quantile of stack
    return sorted(stack._elems)[int(len(stack._elems) * quantile)]

   


def solve(elems):
    a = Stack(elems)
    b = Stack()

    operations = []


    def sa():
        operations.append("sa")
        swap(a)

    def sb():
        operations.append("sb")
        swap(b)

    def ss():
        operations.append("ss")
        swap(a)
        swap(b)

    def pa():
        operations.append("pa")
        push(a, b)

    def pb():
        operations.append("pb")
        push(b, a)

    def ra():
        operations.append("ra")
        rotate(a)

    def rb():
        operations.append("rb")
        rotate(b)

    def rr():
        operations.append("rr")
        rotate(a)
        rotate(b)

    def rra():
        operations.append("rra")
        reverse_rotate(a)

    def rrb():
        operations.append("rrb")
        reverse_rotate(b)

    def rrr():
        operations.append("rrr")
        reverse_rotate(a)
        reverse_rotate(b)


   

    def bring_top_minimum_moves(idx, stack: Stack) -> int:
        # compute the minimum number of moves to bring the element at idx to the top of stack
        # be smart about it, reverse_rotate if idx is closer to the bottom else rotate
        # return the number of moves

        if (idx <= len(stack) // 2):
            return idx
        else:
            return -(len(stack) - idx)

    def bring_top_minimum_a(operations, stack: Stack):
        if operations > 0:
            for _ in range(operations):
                ra()
        else:
            for _ in range(-operations):
                rra()

    def bring_top_minimum_b(operations, stack: Stack):
        if operations > 0:
            for _ in range(operations):
                rb()
        else:
            for _ in range(-operations):
                rrb()



    # function to find the biggest element in b smaller than number
    def find_biggest_smaller_than(number):
        # find the biggest element in b smaller than number
        # return the index of the element
       
        current = min(b._elems)
        res = None
        for i in range(len(b)):
            e = b._elems[i]
            if e <= number and e >= current:
                current = e
                res = i
        if  res is None:
            raise Exception("No element found")
        return res

    def find_smallest_bigger_than(number):
        current = max(a._elems)
        res = None
        for i in range(len(a)):
            e = a._elems[i]
            if e >= number and e <= current:
                current = e
                res = i
        return res



    def compute_operations(a_idx):
        a_elem = a._elems[a_idx]
        minb = min(b._elems)
        maxb = max(b._elems)

        a_moves = bring_top_minimum_moves(a_idx, a)

        if a_elem > maxb or a_elem < minb:
            b_moves = bring_top_minimum_moves(b._elems.index(maxb), b)
            return a_moves, b_moves
        else:
            e = find_biggest_smaller_than(a_elem)
            b_moves = bring_top_minimum_moves(e, b)
            return a_moves, b_moves


    # def  sort_aa_3_elements():
    #     # sort the top 3 elements of a

    pa()
    print('\n', a, '\n', b, '\n')
    pa()
    print('\n', a, '\n', b, '\n')

    while len(a) > 1:
        ops = []
        for i, x in enumerate(a._elems):
            moves_a, moves_b = compute_operations(i)
            ops.append((moves_a, moves_b))
       
        # get index of minimum in ops
        min_idx = ops.index(min(ops, key=lambda x: abs(x[0]) + abs(x[1]) + 1))
        moves_a, moves_b = ops[min_idx]
        bring_top_minimum_a(moves_a, a)
        bring_top_minimum_b(moves_b, b)
        pa()
        print('\n', a, '\n', b, '\n')
        # print(i, x, "-->", moves_a, moves_b, abs(moves_a) + abs(moves_b) + 1)

    print("-----------")
    while len(b) > 0:
        mina = min(a._elems)
        maxa = max(a._elems)
        if  b._elems[0] < mina or b._elems[0] > maxa :
            # find index of smalles elemeent in b
            bring_top_minimum_a(a._elems.index(min(a._elems)), a)
            pb()
            print('\n', a, '\n', b, '\n')
        else:
            e = find_smallest_bigger_than(b._elems[0])
            print(e)
            print(a, '\n' , b)
            a_moves = bring_top_minimum_moves(e, a)
            bring_top_minimum_a(a_moves, a)
            pb()
            print('\n', a, '\n', b, '\n')
            


    # find index smallest element in a
    a_idx = a._elems.index(min(a._elems))
    a_moves = bring_top_minimum_moves(a_idx, a)
    bring_top_minimum_a(a_moves, a)
    print('\n', a, '\n', b, '\n')




    print(a)
   
    # assert a sorted
    assert sorted(a._elems) == a._elems






    return operations



           
elems = random.sample(range(0, 1000), k=100)
elems = [8, 62, 3, 67, 39, 9, 94, 52, 66, 1, 30, 33, 84, 25, 70, 96, 13, 35, 41, 34, 4, 81, 2, 56, 15, 59, 47, 46, 11, 38, 61, 91, 64, 65, 89, 83, 42, 75, 17, 99, 78, 49, 28, 77, 32, 63, 95, 100, 51, 20, 19, 71, 68, 76, 58, 69, 86, 10, 7, 36, 50, 88, 72, 82, 98, 80, 97, 60, 45, 73, 14, 21, 29, 44, 53, 40, 31, 54, 57, 87, 79, 6, 23, 5, 27, 37, 48, 18, 55, 12, 43, 22, 93, 26, 16, 90, 85, 74, 92, 24]
#elems = [65, 204, 149, 668, 672]
#elems = [567, 655, 60, 484, 858]
print(elems)
ops = solve(elems)

print(len(ops))

# m = []
# for _ in range(100):

#     elems = random.sample(range(0, 1000), k=100)
#     ops = solve(elems)
#     m.append(len(ops))

# print(sum(m) / len(m))