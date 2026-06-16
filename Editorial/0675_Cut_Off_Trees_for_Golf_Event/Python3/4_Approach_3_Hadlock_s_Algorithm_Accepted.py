def hadlocks(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    processed = set()
    deque = collections.deque([(0, sr, sc)])
    while deque:
        detours, r, c = deque.popleft()
        if (r, c) not in processed:
            processed.add((r, c))
            if r == tr and c == tc:
                return abs(sr-tr) + abs(sc-tc) + 2*detours
            for nr, nc, closer in ((r-1, c, r > tr), (r+1, c, r < tr),
                                   (r, c-1, c > tc), (r, c+1, c < tc)):
                if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                    if closer:
                        deque.appendleft((detours, nr, nc))
                    else:
                        deque.append((detours+1, nr, nc))
    return -1
