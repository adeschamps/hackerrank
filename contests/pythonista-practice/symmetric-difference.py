M_count = int(input())
M = set(map(int, input().split()))

N_count = int(input())
N = set(map(int, input().split()))

sym_diff = M.union(N).difference(M.intersection(N))
sdl = list(sym_diff)
sdl.sort()
for i in sdl:
    print(i)
