#############priority queue##################
import heapq
import sys

input = sys.stdin.readline

n = int(input())
pq = []

for _ in range(n):
    tmp = int(input())
    if tmp == 0:
        if not pq:
            print(0)
        else:
            print(heapq.heappop(pq))
    else:
        heapq.heappush(pq, tmp)
#############priority queue##################

############# bfs _ dfs ##################
from collections import deque

n, m, start = map(int, input().split)
v= [[] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int, input().split)
    v[a].append[b]
    v[b].append[a]


def dfs(st):
    s = [st]
    vst = [False * (n+1)]

    while s:
        cur = s.pop()
        if vst[cur]:
            continue
        vst[cur] = True
        print(cur, end= ' ')
        for nxt in sorted(v[cur], reverse=True):
            if not vst[nxt]:
                s.append(nxt)
    print()

def bfs(st):
    q = deque([st])
    vst = [False *(n+1)]

    while q:
        cur = q.popleft()
        if vst[cur]:
            continue
        vst[cur] = True
        print(cur, end = ' ')
        for nxt in sorted(v[cur]):
            if not vst[nxt]:
                q.append(nxt)
    print()

dfs(start)
bfs(start)

############# bfs _ dfs ##################



from collections import deque
n , m , start = map(int, input.split())
v = [[]for _ in range(n+1)]

for _ in range (m):
    a, b = map(int, input.split())

    

