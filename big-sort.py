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
        operations.append("pb")
        push(a, b)

    def pb():
        operations.append("pa")
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

    def bring_top_minimum_a(operations):
        if operations > 0:
            for _ in range(operations):
                ra()
        else:
            for _ in range(-operations):
                rra()

    def bring_top_minimum_b(operations):
        if operations > 0:
            for _ in range(operations):
                rb()
        else:
            for _ in range(-operations):
                rrb()

    def magic_compute(a_idx, b_idx):
        greedy_a = bring_top_minimum_moves(a_idx, a)
        greedy_b = bring_top_minimum_moves(b_idx, b)
        greedy_tot = abs(greedy_a) + abs(greedy_b)

        rotate_a =  a_idx
        rotate_b =  b_idx
        rotate_tot = max(rotate_a, rotate_b)

        r_rotate_a =  -(len(a) - a_idx)
        r_rotate_b =  -(len(b) - b_idx)
        r_rotate_tot = max(abs(r_rotate_a), abs(r_rotate_b))

        if greedy_tot <= rotate_tot and greedy_tot <= r_rotate_tot:
            return greedy_a, greedy_b

        if rotate_tot <= greedy_tot and rotate_tot <= r_rotate_tot:
            return rotate_a, rotate_b

        else:
            return r_rotate_a, r_rotate_b

    def magic_bring_top(a_moves, b_moves):
        sign = a_moves * b_moves
        if sign > 0:
            aa = abs(a_moves)
            bb = abs(b_moves)
            xx = min(aa, bb)
            yy = max(aa, bb) - xx

            for _ in range(xx):
                if a_moves > 0:
                    rr()
                else:
                    rrr()
            
            for _ in range(yy):
                if a_moves > 0:
                    if aa > bb:
                        ra()
                    else:
                        rb()
                else:
                    if aa > bb:
                        rra()
                    else:
                        rrb()
        
        else:
            bring_top_minimum_a(a_moves)
            bring_top_minimum_b(b_moves)
        



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

        # a_moves = bring_top_minimum_moves(a_idx, a)

        # if a_elem > maxb or a_elem < minb:
        #     b_moves = bring_top_minimum_moves(b._elems.index(maxb), b)
        #     return a_moves, b_moves
        # else:
        #     e = find_biggest_smaller_than(a_elem)
        #     b_moves = bring_top_minimum_moves(e, b)
        #     return a_moves, b_moves

        if a_elem > maxb or a_elem < minb:
            a_moves, b_moves = magic_compute(a_idx, b._elems.index(maxb))
            return a_moves, b_moves
        else:
            e = find_biggest_smaller_than(a_elem)
            a_moves, b_moves = magic_compute(a_idx, e)
            return a_moves, b_moves


    # def  sort_aa_3_elements():
    #     # sort the top 3 elements of a

    pa()
    pa()

    while len(a) > 1:
        ops = []
        for i, x in enumerate(a._elems):
            moves_a, moves_b = compute_operations(i)
            ops.append((moves_a, moves_b))
       
        # get index of minimum in ops
        min_idx = ops.index(min(ops, key=lambda x: abs(x[0]) + abs(x[1]) + 1))
        moves_a, moves_b = ops[min_idx]
        # bring_top_minimum_a(moves_a)
        # bring_top_minimum_b(moves_b)
        magic_bring_top(moves_a, moves_b)
        pa()
        print("\n")
        print(operations)
        print("\n")
        print(a)
        print("\n")
        print(b)

    print("-----------")
    while len(b) > 0:
        mina = min(a._elems)
        maxa = max(a._elems)
        if  b._elems[0] < mina or b._elems[0] > maxa :
            # find index of smalles elemeent in b
            bring_top_minimum_a(a._elems.index(min(a._elems)))
            pb()
        else:
            e = find_smallest_bigger_than(b._elems[0])
            a_moves = bring_top_minimum_moves(e, a)
            bring_top_minimum_a(a_moves)
            pb()
            


    # find index smallest element in a
    a_idx = a._elems.index(min(a._elems))
    a_moves = bring_top_minimum_moves(a_idx, a)
    bring_top_minimum_a(a_moves)




    # assert a sorted
    assert sorted(a._elems) == a._elems






    return operations



random.seed(7)
# elems = random.sample(range(0, 1000), k=500)
elems = [7, 19, 11, 3, 14, 2, 6, 13, 16, 18, 8, 17, 9, 20, 10, 12, 1, 15, 4, 5]
#elems = [65, 204, 149, 668, 672]
#elems = [567, 655, 60, 484, 858]
print(elems)
ops = solve(elems)

print(len(ops))

from collections import Counter
print(Counter(ops))

# m = []
# for _ in range(100):

#     elems = random.sample(range(0, 1000), k=100)
#     ops = solve(elems)
#     m.append(len(ops))

# print(sum(m) / len(m))