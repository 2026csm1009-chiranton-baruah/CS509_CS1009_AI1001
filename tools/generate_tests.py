from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
TESTS = ROOT / 'assignment_02' / 'tests'
TESTS.mkdir(parents=True, exist_ok=True)

def write_graph(path, n, edges):
    adj = [[] for _ in range(n)]
    for u, v in sorted(edges):
        adj[u].append(v); adj[v].append(u)
    with open(path, 'w') as f:
        f.write(f'{n} {len(edges)}\n')
        for u in range(n):
            a = adj[u]
            f.write(f'{u} {len(a)}' + ((' ' + ' '.join(map(str, a))) if a else '') + '\n')

def structured_connected(n, offsets=(1,2,3)):
    e=set()
    for d in offsets:
        for u in range(n-d):
            e.add((u,u+d))
    return e

def structured_components(n):
    if n == 10:
        groups=[list(range(0,4)),list(range(4,7)),[7],[8],[9]]
    elif n == 100:
        groups=[list(range(0,40)),list(range(40,70)),list(range(70,95))] + [[i] for i in range(95,100)]
    else:
        iso=max(2,n//25)
        usable=n-iso
        a_end=usable*2//5
        b_end=a_end+usable//3
        groups=[list(range(0,a_end)),list(range(a_end,b_end)),list(range(b_end,usable))] + [[i] for i in range(usable,n)]
    e=set()
    for g in groups:
        m=len(g)
        for d in (1,2):
            for i in range(m-d): e.add((g[i],g[i+d]))
    return e

for n in [10,100,10_000,50_000,100_000]:
    write_graph(TESTS/f'tc_{n}.txt',n,structured_connected(n,(1,2,3)))
    write_graph(TESTS/f'cc_{n}.txt',n,structured_components(n))
for n in [10,100,1_000,5_000,10_000]:
    write_graph(TESTS/f'bc_{n}.txt',n,structured_connected(n,(1,2,3)))
