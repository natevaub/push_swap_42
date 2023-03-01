class Stack:
	def __init__(self):
		self._list = []

	def push(self, x: int):
		self._list.insert(0, x)

	def pop(self):
		return self._list.pop(0)

	def swap(self):
		c = self._list[1]
		self._list[1] = self._list[0]
		self._list[0] = c

	def __str__(self) -> str:
		res = "Stack:\n"
		for i, x in enumerate(self._list):
			res += f"Node {i}: {x}\n"
		return res

i = [2, 1, 3, 6 ,5 ,8]
s = Stack()
for elem in reversed(i):
	s.push(elem)



print(s)
s.swap()
print()
print(s)







	