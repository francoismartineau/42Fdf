import random
import sys
import math


def gen(width: int, length: int, scale: int):
	width = int(width)
	length = int(length)
	scale = int(scale)
	for y in range(length):
		for x in range(width):
			height = math.sin(x) + math.cos(y)
			height *= scale
			height += random.random() * scale
			print(f'{int(height): 5}', end=" ")
		print("\n", end="")

if __name__ == "__main__":
	argc = len(sys.argv)
	if (argc != 4):
		print(f'Usage:\npython3 {__file__} width height scale')
		sys.exit()
	gen(*sys.argv[1:4])

