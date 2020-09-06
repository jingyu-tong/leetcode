1. binary search 模板
左闭右开
```python
def bnary_search(l, r):
    while l < r:
        m = l + (r - l) // 2;
        if f(m): return m; # optional
        if g(m):
            r = m
        else 
            l = m + 1
    return l # 最小的 l，s.t. g(m)等于 true
```

左闭右闭
```python
def bnary_search(l, r):
    while l <= r:
        m = l + (r - l) // 2;
        if f(m): return m; # optional
        if g(m):
            r = m - 1
        else 
            l = m + 1
    return l # 最小的 l，s.t. g(m)等于 true
```